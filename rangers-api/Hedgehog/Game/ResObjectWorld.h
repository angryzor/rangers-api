#pragma once

namespace hh::game {
    struct ComponentData {
        uint64_t unk1;
        const char* type;
        uint64_t size;
        void* data;

        ComponentData(csl::fnd::IAllocator* allocator, const GOComponentRegistry::GOComponentRegistryItem* gocRegItem, void* data) : type{ gocRegItem->name }, size{ gocRegItem->rflClass->GetSizeInBytes() }, data{ data } {
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
            , localTransform { localTransform }
            , componentData{ allocator }
            , id{ id } {
            if (parent) {
                parentID = parent->id;
                // transform = Eigen::
            } else {
                parentID = { 0, 0 };
                transform = localTransform;
            }

            spawnerData = gameObjectClass->spawnerDataRflClass == nullptr ? nullptr : hh::fnd::RflTypeInfoRegistry::GetInstance()->ConstructObject(allocator, gameObjectClass->spawnerDataRflClass->GetName());
        }

        ComponentData* GetComponentDataByType(const char* type);
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
