#pragma once

namespace hh::anim {
    class BlendNodeBase;
    class ClipNode;
    class AnimationState : public fnd::ReferencedObject {
    public:
        class SpeedBindable : public Bindable {
        public:
            struct Unk2 {
                int variableIndex;
                Bindable* bindable;
            };

            struct Unk1 {
                csl::ut::InplaceMoveArray<Unk2, 6> unk1;
            };
            uint64_t unk1;
            uint64_t unk2;
            uint64_t unk3;
            AnimationState* animationState;
            Unk1 unk4;

            virtual void Bind(float value) override;
        };

        struct Unk1 {
            uint32_t unk1;
            float speed;
            float unk3;
            uint32_t unk4;

            float unk5;
            float unk6;
            uint32_t unk7;
            uint32_t unk8;

            uint32_t unk9;
            uint32_t unk10;
            bool loops;
            uint16_t unk12;
    
            uint64_t unk13;

            csl::ut::MoveArray<void*> unk14;
            uint64_t unk15;
            void* unk16[1];

        };
        AsmResourceManager* asmResourceManager;
        StateData* stateData;
        const char* name;
        short stateId;
        bool loops;
        uint16_t sequenceNumber;
        uint16_t word36; // may not exist
        float duration;
        float speed;
        float durationScaledByFloat44;
        float float44;
        uint32_t dword48;
        uint32_t maxCycles;
        EventArray* eventArray;
        TransitionArray* transitionArray;
        csl::ut::InplaceMoveArray<Unk1, 3> unk60;
        uint8_t byte1B8;
        uint64_t qword1C0;
        uint64_t qword1C8;
        fnd::Reference<BlendNodeBase> blendTree;
        SpeedBindable speedBindable;

        CREATE_FUNC(AnimationState, AsmResourceManager* asmResourceManager, int stateId);

        ClipNode* CreateClipNode(int clipIndex);
        BlendNodeBase* BuildBlendTree(BlendNodeData* rootBlendNode);
        void Update();
    };
}
