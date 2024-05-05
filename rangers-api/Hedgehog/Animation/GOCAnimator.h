#pragma once

namespace hh::anim {
    class GOCAnimator : public GOCAnimationSingle, public TriggerListener, public AnimationStateListener {
    public:
        AnimationStateMachine* animationStateMachine;
        AsmResourceManager* asmResourceManager;
        uint32_t unk203;
        char flags;
        char unk204b;
        uint64_t unk205;
    
        struct SetupInfo : public GOCAnimationSingle::SetupInfo {
            AsmResourceManager* asmResourceManager;
            uint8_t unk102;
            uint8_t unk103; // This isn't referenced in Setup(), I don't understand...
            bool setUnk2Flag;
        };

        virtual void* GetRuntimeTypeInfo() override;
		virtual void GetDebugInfoMaybe() override;
		virtual void OnGOCEvent(GOCEvent event, game::GameObject& ownerGameObject, void* data) override;
        virtual bool GetDeltaMotion(csl::math::Transform* transform) override;
        virtual void UnkFunc2() override;
        virtual void UnkFunc3() override;
        virtual uint64_t UnkFunc4() override;
        virtual void TL_MaybeOnTrigger() override;
        virtual void ASL_MaybeOnStateChange() override;

        void Setup(const SetupInfo& setupInfo);
        bool ChangeState(const char* stateName);
        bool ChangeStateWithoutTransition(const char* stateName);
        bool ChangeToNull(int unkParam);

        GOCOMPONENT_CLASS_DECLARATION(GOCAnimator)
    };
}
