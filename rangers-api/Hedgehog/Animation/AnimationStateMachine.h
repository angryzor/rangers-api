#pragma once

namespace hh::anim {
    class AnimationStateListener {
    public:
        virtual ~AnimationStateListener() = default;
        virtual void ASL_MaybeOnStateChange() = 0;
    };

    class AnimationStateMachine : public fnd::ReferencedObject {
    public:
        struct VariableInfo {
            BindableCollection bindables;
        };
        struct LayerInfo {
            uint32_t layerId;
            uint8_t unk2;
            uint8_t unk3;
            uint16_t unk4;
            uint8_t unk5;
            float unk6;
            uint16_t unk7;
            uint64_t unk8;
            fnd::Reference<LayerBlendNode> blendNode;
            AnimationStateMachine* animStateMachine;
        };
    // private:
        csl::ut::InplaceMoveArray<csl::math::Matrix44, 4> unk1;
        uint8_t unk2;
        uint64_t unk3;
        fnd::Reference<AsmResourceManager> asmResourceManager;
        fnd::Reference<SkeletonBlender> skeletonBlender;
        csl::ut::InplaceMoveArray<LayerInfo, 1> layers;
        csl::ut::InplaceMoveArray<void*, 1> unk6;
        csl::ut::InplaceMoveArray<void*, 1> unk7;
        csl::ut::InplaceMoveArray<void*, 1> unk8;
        uint64_t unk9;
        csl::ut::MoveArray<VariableInfo> variables;
        fnd::Reference<BlendNodeBase> blendTree;
        csl::ut::MoveArray<csl::ut::MoveArray<void*>> unk11; // from u17 in resanimator
        uint32_t unk12;
        float unk13;
        csl::math::Transform transform;
        uint8_t unk14;
        bool initialized;
        uint8_t unk15;

    public:
        AnimationStateMachine(csl::fnd::IAllocator* allocator);
        void Setup(AsmResourceManager* resourceManager, SkeletonBlender* skeletonBlender);
        void AddListener(AnimationStateListener* listener);
        void RemoveListener(AnimationStateListener* listener);
        void UnloadResource(fnd::ManagedResource* resource);
        void LoadResource(fnd::ManagedResource* resource);
        bool ChangeState(const char* stateName);
        bool ChangeStateWithoutTransition(const char* stateName);
        bool ChangeToNull(int layer);
        void DoTransit(const TransitionData& transitionData, int layer);
        int GetActiveInternalState(int layer) const;
        int GetActiveState(int layer) const;
        int GetCurrentState(int layer) const;
        BlendNodeBase* BuildLayerBlendTree(const BlendNodeData& blendNodeData);
    };
}
