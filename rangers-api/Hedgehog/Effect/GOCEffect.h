#pragma once

namespace hh::eff {
    enum class EffectTransType : uint32_t {
        FRAME,
        NODE,
        NODE_AND_FRAME,
        NODE_POSITION,
        MODEL,
        MODEL_SPACE_NODE,
        WORLD_POSITION,
        FRAME_OVERRIDE_ROTATION_SCALE,
        FRAME_POSITION,
    };

    struct EffectTransFrameInfo {
        fnd::HFrame* frame;
        bool scale;
    };

    struct EffectTransNodeInfo {
        gfx::GOCVisualModel* model;
        const char* nodeName;
        int nodeIndex;
        bool scale;
    };

    struct EffectTransNodeAndFrameInfo {
        fnd::HFrame* frame;
        gfx::GOCVisualModel* model;
        const char* nodeName;
        int nodeIndex;
        bool scale;
    };

    struct EffectTransNodePositionInfo {
        fnd::HFrame* frame;
        gfx::GOCVisualModel* model;
        const char* nodeName;
        int nodeIndex;
    };

    struct EffectTransModelInfo {
        gfx::GOCVisualModel* model;
    };

    struct EffectTransModelSpaceNodeInfo {
        gfx::GOCVisualModel* model;
        const char* nodeName;
        int nodeIndex;
    };

    struct EffectTransWorldPositionInfo {
        fnd::WorldPosition worldPosition;
    };

    struct EffectTransFrameOverrideRotationScaleInfo {
        fnd::HFrame* positionFrame;
        fnd::HFrame* rotationScaleFrame;
        bool scale;
    };

    struct EffectTransFramePositionInfo {
        fnd::HFrame* frame;
    };

    struct EffectCreateInfo {
        uint8_t unk1;
        bool unk1a;
        uint8_t unk2;
        const char* resourceName;
        float unk4;
        int unk4a;
        uint64_t unk5;
        uint64_t unk6;
        EffectTransType transType;
        fnd::WorldPosition additionalWorldPos;
        bool useAdditionalWorldPos;

        EffectCreateInfo(EffectTransType transType, const char* resourceName)
            : transType{ transType }
            , unk1{ 1 }
            , unk1a{ 0 }
            , unk2{ 0 }
            , resourceName{ resourceName }
            , unk4{ 1.0f }
            , unk4a{ -1 }
            , unk5{ 0 }
            , unk6{ 0 }
            , additionalWorldPos{}
            , useAdditionalWorldPos{ false }
        {}
    };

    struct EffectTransFrameCreateInfo : EffectCreateInfo {
        EffectTransFrameInfo transInfo;

        EffectTransFrameCreateInfo(const char* resourceName) : EffectCreateInfo{ EffectTransType::FRAME, resourceName } {}
    };

    struct EffectTransNodeCreateInfo : EffectCreateInfo {
        EffectTransNodeInfo transInfo;

        EffectTransNodeCreateInfo(const char* resourceName) : EffectCreateInfo{ EffectTransType::NODE, resourceName } {}
    };

    struct EffectTransNodeAndFrameCreateInfo : EffectCreateInfo {
        EffectTransNodeAndFrameInfo transInfo;

        EffectTransNodeAndFrameCreateInfo(const char* resourceName) : EffectCreateInfo{ EffectTransType::NODE_AND_FRAME, resourceName } {}
    };

    struct EffectTransNodePositionCreateInfo : EffectCreateInfo {
        EffectTransNodePositionInfo transInfo;

        EffectTransNodePositionCreateInfo(const char* resourceName) : EffectCreateInfo{ EffectTransType::NODE_POSITION, resourceName } {}
    };

    struct EffectTransModelCreateInfo : EffectCreateInfo {
        EffectTransModelInfo transInfo;

        EffectTransModelCreateInfo(const char* resourceName) : EffectCreateInfo{ EffectTransType::MODEL, resourceName } {}
    };

    struct EffectTransModelSpaceNodeCreateInfo : EffectCreateInfo {
        EffectTransModelSpaceNodeInfo transInfo;

        EffectTransModelSpaceNodeCreateInfo(const char* resourceName) : EffectCreateInfo{ EffectTransType::MODEL_SPACE_NODE, resourceName } {}
    };

    struct EffectTransWorldPositionCreateInfo : EffectCreateInfo {
        EffectTransWorldPositionInfo transInfo;

        EffectTransWorldPositionCreateInfo(const char* resourceName) : EffectCreateInfo{ EffectTransType::WORLD_POSITION, resourceName } {}
    };

    struct EffectTransFrameOverrideRotationScaleCreateInfo : EffectCreateInfo {
        EffectTransFrameOverrideRotationScaleInfo transInfo;

        EffectTransFrameOverrideRotationScaleCreateInfo(const char* resourceName) : EffectCreateInfo{ EffectTransType::FRAME_OVERRIDE_ROTATION_SCALE, resourceName } {}
    };

    struct EffectTransFramePositionCreateInfo : EffectCreateInfo {
        EffectTransFramePositionInfo transInfo;

        EffectTransFramePositionCreateInfo(const char* resourceName) : EffectCreateInfo{ EffectTransType::FRAME_POSITION, resourceName } {}
    };

    class EffectHandle {
        int unk1;
        void* unk2;
        EffectHandle();
    };

    class GOCEffect : public game::GOComponent {
    public:
        struct Description {
            uint32_t unk1;
            uint32_t unk2;
            float unk3;
            uint32_t unk4;
            int unk5;
            uint32_t unk6;
            uint8_t unk7;
            bool unk8;
        };

        struct EffectTransInfo {
            enum class TransType : uint8_t {
                FRAME,
                NODE,
                NODE_AND_FRAME,
                NODE_POSITION,
                MODEL,
                MODEL_SPACE_NODE,
                WORLD_POSITION,
                FRAME_OVERRIDE_ROTATION_SCALE,
                FRAME_POSITION,
            };

            enum class Flag : uint8_t {
                ADDITIONAL_MATRIX,
                SCALE,
            };

            TransType transType;
            csl::ut::Bitset<Flag> flags;
            unsigned short modelNodeIndex;
            gfx::GOCVisualModel* model;
            fnd::Reference<fnd::HFrame> frame1;
            fnd::Reference<fnd::HFrame> frame2;
            csl::math::Matrix34 transformationMatrix1;
            csl::math::Matrix34 additionalTransformationMatrix;
        };

        uint64_t qword80;
        fnd::Reference<fnd::HFrame> frame;
        float dword90;
        uint8_t byte94;
        int dword98;
        float dword9C;
        uint32_t dwordA0;
        gfx::GOCVisualModel* model;
        csl::ut::MoveArray<void*> unkB0;
        csl::ut::MoveArray<void*> unkD0;
        csl::ut::InplaceMoveArray<void*, 1> unkF0;
        uint32_t dword118;

		virtual void* GetRuntimeTypeInfo() override;
		virtual void GetDebugInfoMaybe() override;
		virtual void OnGOCEvent(GOCEvent event, game::GameObject& ownerGameObject, void* data) override;

        void SetModel(unsigned int* nameHash);
        void Setup(const Description& description);
        void SetupGlobalScale();
        csl::math::Matrix34 CalcEffectMatrix(const EffectTransInfo& transInfo);
        void SetupTransInfo(const EffectCreateInfo& createInfo, EffectTransInfo* transInfo);
        EffectHandle CreateEffectHandle(const char* resourceName, const csl::math::Matrix34& location, float unkParam2, const float* unkParam3, const EffectCreateInfo* createInfo);
        void CreateEffect(const char* resourceName, EffectHandle* handle);
        void CreateEffectEx(const EffectCreateInfo& createInfo, EffectHandle* handle);
        void CreateEffectLoop(const char* resourceName, EffectHandle* handle);
        void CreateEffectLoopEx(const EffectCreateInfo& createInfo, EffectHandle* handle);
        void CreateEffectPlain(const char* resourceName, const csl::math::Matrix34& location);
        void CreateEffectWorld(const char* resourceName, const csl::math::Matrix34& location, EffectHandle* handle);
        void StopEffect(EffectHandle handle, bool unkParam);
        void StopEffectAll();

        GOCOMPONENT_CLASS_DECLARATION(GOCEffect)
    };
}
