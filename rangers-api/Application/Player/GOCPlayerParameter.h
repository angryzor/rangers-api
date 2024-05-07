#pragma once

namespace app::player {
    class GOCPlayerParameter : public hh::game::GOComponent {
    public:
        enum class Mode : uint32_t {
            NORMAL,
            WATER,
            CYBERSPACE_FORWARD_VIEW,
            CYBERSPACE_SIDE_VIEW,
        };

        enum class SuperState : uint32_t {
            NORMAL_SONIC,
            SUPER_SONIC,
            SUPER_SONIC_2,
        };

        union CharacterParameters {
            hh::fnd::ResReflection<app::rfl::SonicParameters> sonic;
            hh::fnd::ResReflection<app::rfl::AmyParameters> amy;
            hh::fnd::ResReflection<app::rfl::KnucklesParameters> knuckles;
            hh::fnd::ResReflection<app::rfl::TailsParameters> tails;
        };

        union CharacterModePackage {
            app::rfl::ModePackageSonic sonic;
            app::rfl::ModePackageAmy amy;
            app::rfl::ModePackageKnuckles knuckles;
            app::rfl::ModePackageTails tails;
            app::rfl::ModePackage unknown;
        };

        hh::fnd::Reference<CharacterParameters> characterParameters;
        hh::fnd::Reference<hh::fnd::ResReflection<app::rfl::PlayerCameraSetParameters>> cameraSetParameters;
        app::rfl::ModePackage* modePackages[4];
        app::rfl::WaterModePackage* waterModePackage;
        Mode mode;
        SuperState superState;
        CharacterId characterId;
        app::rfl::PlayerParamCommon* commonParameters[4];
        app::rfl::PlayerParamSpeed* speedParameters[4];
        app::rfl::PlayerParamJump* jumpParameters[4];
        app::rfl::PlayerParamJumpSpeed* jumpSpeedParameters[4];
        app::rfl::PlayerParamDoubleJump* doubleJumpParameters[4];
        app::rfl::PlayerParamBoost* boostParameters[4];
        app::rfl::PlayerParamAirBoost* airBoostParameters[4];

    private:
        void* GetPlayerParameter(const hh::fnd::RflClass& rflClass);
    public:
        struct Config {
            uint32_t flags;
            hh::fnd::Reference<hh::fnd::ResReflection<CharacterParameters>> characterParameters;
            hh::fnd::Reference<hh::fnd::ResReflection<app::rfl::PlayerCameraSetParameters>> cameraSetParameters;
            CharacterId characterId;
        };

        GOCPlayerParameter(csl::fnd::IAllocator* allocator);
        void Initialize(const Config& config);

        app::rfl::PlayerParamCommon& GetCommonParameters() const;
        app::rfl::PlayerParamSpeed& GetSpeedParameters() const;
        app::rfl::PlayerParamJump& GetJumpParameters() const;
        app::rfl::PlayerParamJumpSpeed& GetJumpSpeedParameters() const;
        app::rfl::PlayerParamDoubleJump& GetDoubleJumpParameters() const;
        app::rfl::PlayerParamBoost& GetBoostParameters() const;
        app::rfl::PlayerParamAirBoost& GetAirBoostParameters() const;

        app::rfl::PlayerParamAcceleCombo& GetAcceleComboParameters() const;
        app::rfl::PlayerParamLoopKick& GetLoopKickParameters() const;
        app::rfl::PlayerParamCrasher& GetCrasherParameters() const;
        app::rfl::PlayerParamSpinSlash& GetSpinSlashParameters() const;
        app::rfl::PlayerParamChargeAttack& GetChargeAttackParameters() const;
        app::rfl::PlayerParamStompingAttack& GetStompingAttackParameters() const;
        app::rfl::PlayerParamComboFinish& GetComboFinishParameters() const;
        app::rfl::PlayerParamSonicBoom& GetSonicBoomParameters() const;
        app::rfl::PlayerParamCrossSlash& GetCrossSlashParameters() const;
        app::rfl::PlayerParamHomingShot& GetHomingShotParameters() const;
        app::rfl::PlayerParamSmash& GetSmashParameters() const;

        void SetMode(Mode mode);
        void SetSuperState(SuperState state);

        template<typename T>
        T* GetPlayerParameter() {
            return reinterpret_cast<T*>(GetPlayerParameter(RESOLVE_STATIC_VARIABLE(T::rflClass)));
        }

        // template<typename T>
        // T* GetPlayerParameter(const hh::fnd::RflClass& rflClass) {
        //     return reinterpret_cast<T*>(GetPlayerParameter(rflClass));
        // }

        virtual void* GetRuntimeTypeInfo() override;
		virtual void GetDebugInfoMaybe() override;
		virtual void OnGOCEvent(hh::game::GOComponent::GOCEvent event, hh::game::GameObject& ownerGameObject, void* data) override;

        GOCOMPONENT_CLASS_DECLARATION(GOCPlayerParameter)
    };
}
