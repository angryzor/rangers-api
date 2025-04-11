#pragma once

namespace hh::animeff {
    class GOCParticleLocator : public game::GOComponent, public anim::TriggerListener, public anim::AnimationStateMachineListener {
    public:
        struct SetupInfo {
            ResParticleLocation* resource{}; // ResParticleLocation
            unsigned int gocVisualModelNameHash{};
            unsigned int gocAnimatorNameHash{};
            uint8_t byteC0{};
            uint32_t qwordC8{};
        };

        struct BoundEffectCollection {
            struct BoundEffect {
                uint16_t unk1;
                uint16_t unk2;
                uint8_t unk3;
                uint64_t unk4;
                hh::eff::EffectHandle effectHandle;
            };

            csl::ut::MoveArray<BoundEffect> boundEffects;
            csl::fnd::IAllocator* allocator;
        };

        fnd::Reference<ResParticleLocation> resource;
        anim::GOCAnimator* gocAnimator;
        eff::GOCEffect* gocEffect;
        gfx::GOCVisualModel* gocVisualModel;
        uint8_t byteB0;
        short effectTriggerTypeIndex;
        short soundTriggerTypeIndex;
        unsigned int gocVisualModelNameHash{};
        unsigned int gocAnimatorNameHash{};
        uint8_t byteC0;
        uint32_t qwordC4;
        uint32_t qwordC8;
        csl::ut::MoveArray<void*> unkD0;
        csl::ut::MoveArray<BoundEffectCollection*> boundEffectsByBoneIndex;
        csl::ut::MoveArray<void*> unk110;
        csl::ut::InplaceMoveArray<void*, 1> unk130;

        GOCParticleLocator(csl::fnd::IAllocator* allocator);

        virtual void* GetRuntimeTypeInfo() const override;
		virtual void UpdateAsync(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo, void* unkParam) override;
		virtual void OnGOCEvent(GOCEvent event, game::GameObject& ownerGameObject, void* data) override;
        virtual void TransitionEndedCallback(anim::AnimationStateMachine* animationStateMachine, int stateId) override;
        virtual void TL_MaybeOnTrigger() override;

        void Setup(const SetupInfo& setupInfo);

        GOCOMPONENT_CLASS_DECLARATION(GOCParticleLocator);
    };
}
