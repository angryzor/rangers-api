#pragma once

namespace hh::game {
    struct ComponentData {
        uint64_t unk1{};
        const char* type;
        uint64_t size;
        void* data;

private:
        template<typename T>
        ComponentData(const char* type, T* data) : type{ type }, size{ sizeof(T) }, data{ data } {}

public:
        template<typename T>
        static ComponentData* Create(csl::fnd::IAllocator* allocator, const char* type) {
            void* buffer = allocator->Alloc(sizeof(T) + sizeof(ComponentData), 16);
            T* data = new (reinterpret_cast<void*>(reinterpret_cast<size_t>(buffer) + sizeof(ComponentData))) T{};
            return new (buffer) ComponentData{ type, data };
        }

        template<typename T>
        static ComponentData* Create(csl::fnd::IAllocator* allocator, const char* type, const T& value) {
            void* buffer = allocator->Alloc(sizeof(T) + sizeof(ComponentData), 16);
            T* data = new (reinterpret_cast<void*>(reinterpret_cast<size_t>(buffer) + sizeof(ComponentData))) T{ value };
            return new (buffer) ComponentData{ type, data };
        }

        template<typename T>
        static ComponentData* Create(csl::fnd::IAllocator* allocator, const char* type, T&& value) {
            void* buffer = allocator->Alloc(sizeof(T) + sizeof(ComponentData), 16);
            T* data = new (reinterpret_cast<void*>(reinterpret_cast<size_t>(buffer) + sizeof(ComponentData))) T{ std::move(value) };
            return new (buffer) ComponentData{ type, data };
        }

        template<typename T>
        inline T* GetData() const {
            return static_cast<T*>(data);
        }
    };

    struct ObjectTransformData {
        csl::math::Position position;
        csl::math::Position rotation;

        bool operator==(const ObjectTransformData& other) {
            return position == other.position && rotation == other.rotation;
        }

        bool operator!=(const ObjectTransformData& other) {
            return !operator==(other);
        }
    };

    struct ObjectData {
        enum class Flag : uint32_t {
            COMPONENT_DATA_NEEDS_TERMINATION,
            SPAWNER_DATA_NEEDS_TERMINATION,
        };
        csl::ut::Bitset<Flag> flags;
        const char* gameObjectClass;
        csl::ut::VariableString name;
        ObjectId id;
        ObjectId parentID;
        ObjectTransformData transform;
        ObjectTransformData localTransform;
        csl::ut::MoveArray<ComponentData*> componentData;
        void* spawnerData;

        ObjectData(csl::fnd::IAllocator* allocator, const GameObjectClass* gameObjectClass, ObjectId id, const char* name, ObjectData* parent, const ObjectTransformData& localTransform)
            : name{ name, allocator }
            , gameObjectClass{ gameObjectClass->name }
            , flags {}
            , localTransform { localTransform }
            , componentData{ allocator }
            , id{ id } {
            flags.set(Flag::COMPONENT_DATA_NEEDS_TERMINATION);
            
            if (parent) {
                parentID = parent->id;
            } else {
                parentID = {};
                transform = localTransform;
            }

            auto* spawnerRfl = gameObjectClass->spawnerDataRflClass;
            if (spawnerRfl == nullptr) {
                spawnerData = nullptr;
            } else {
                auto* tinfoReg = hh::fnd::BuiltinTypeRegistry::GetTypeInfoRegistry();
                auto* rflObj = tinfoReg->ConstructObject(allocator, spawnerRfl->GetName());

                spawnerData = hh::fnd::DeepCopier::Copy(rflObj, *spawnerRfl, allocator);

                tinfoReg->CleanupLoadedObject(rflObj, spawnerRfl->GetName());
                allocator->Free(rflObj);

                flags.set(Flag::SPAWNER_DATA_NEEDS_TERMINATION);
            }
        }

        ObjectData(csl::fnd::IAllocator* allocator, ObjectId id, const char* name, const ObjectData& other)
            : name{ name, allocator }
            , gameObjectClass{ other.gameObjectClass }
            , flags { other.flags }
            , localTransform { other.localTransform }
            , transform{ other.transform }
            , componentData{ allocator }
            , id{ id }
            , parentID{ other.parentID } {
            flags.set(Flag::COMPONENT_DATA_NEEDS_TERMINATION);
            
            auto* spawnerRfl = GameObjectSystem::GetInstance()->gameObjectRegistry->GetGameObjectClassByName(gameObjectClass)->spawnerDataRflClass;
            if (spawnerRfl == nullptr) {
                spawnerData = nullptr;
            } else {
                assert(other.spawnerData != nullptr);

                auto* tinfoReg = hh::fnd::BuiltinTypeRegistry::GetTypeInfoRegistry();
                spawnerData = hh::fnd::DeepCopier::Copy(other.spawnerData, *spawnerRfl, allocator);
                flags.set(Flag::SPAWNER_DATA_NEEDS_TERMINATION);
            }
        }

        ObjectData(csl::fnd::IAllocator* allocator, ObjectId id, const ObjectData& other) : ObjectData{ allocator, id, other.name, other } {}

        ComponentData* GetComponentDataByType(const char* type);

        const char* GetName() {
            return name.c_str();
        }
    };

    struct ObjectWorldData {
        enum class Flag : uint8_t {
            NEEDS_TERMINATION,
        };
        uint32_t unk1;
        uint32_t unk2;
        csl::ut::Bitset<Flag> flags;
        csl::ut::MoveArray<ObjectData*> objects;
    };

    void TerminateObjectData(csl::fnd::IAllocator* allocator, ObjectData* objData);
    void TerminateObjectWorldData(csl::fnd::IAllocator* allocator, ObjectWorldData* objData);

    class ResObjectWorld : public fnd::ManagedResource {
    public:
        ObjectWorldData* binaryData;
        virtual void Load(void* data, size_t size);
        const csl::ut::MoveArray<ObjectData*>& GetObjects() const;
        void TerminateLayerData();

        inline void AddObject(ObjectData* objData) {
            if (binaryData->objects.get_allocator() == nullptr)
                binaryData->objects.change_allocator(GetAllocator());

            binaryData->objects.push_back(objData);
        }

        inline void RemoveObject(ObjectData* objData) {
            size_t idx = binaryData->objects.find(objData);

            if (idx == -1)
                return;

            binaryData->objects.remove(idx);
        }

        MANAGED_RESOURCE_CLASS_DECLARATION(ResObjectWorld)
    };
}
