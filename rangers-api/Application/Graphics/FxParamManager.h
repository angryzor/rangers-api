#pragma once

namespace app::gfx {
    class FxParamManager;
    class FxParamExtension : public hh::fnd::BaseObject {
        FxParamManager* fxParamManager;

    public:
        FxParamExtension(csl::fnd::IAllocator* allocator);
        virtual void* GetRuntimeTypeInfo() = 0;
        virtual void Initialize() = 0;
        virtual void Destroy() = 0;
        virtual void UnkFunc1() {}
        virtual void UnkFunc2() {}
        virtual void UnkFunc3() {}
        virtual void UnkFunc4() {}
        virtual void UnkFunc5() {}
    };

    class FxParamManager
        : public hh::game::GameService
        , public hh::game::GameStepListener
        , public app::game::GameCondition::Listener {
    public:
        class InterpolatorBase : public hh::fnd::ReferencedObject {
        public:
            InterpolatorBase(csl::fnd::IAllocator* allocator);
            virtual void AddJob(uint64_t ownerId, const void* value, unsigned int interpolationGroupMemberBits, unsigned int priority, float interpolationTime, uint32_t unk6Param) = 0;
            virtual void UpdateJob(uint64_t ownerId, const void* value) = 0;
            virtual void ReverseJob(uint64_t ownerId, float interpolationTime) = 0;
            virtual void Update(float deltaTime) = 0;
            virtual void SetTweenPosition(uint64_t ownerId, float position) = 0;
            virtual void UnkFunc1() {}
        };

        template<typename T>
        class Interpolator : public InterpolatorBase {
            struct Unk1 {
                T parameters;
                uint64_t ownerId;
                unsigned int interpolationGroupMemberBits;
                unsigned int priority;
                float currentTweenPosition;
                float tweenPositionIncrementPerSecond;
                uint32_t unk6;
            };
        public:
            T* target;
            void (*interpolationFunction)(T* target, T* lower, T* upper, unsigned int flags, float delta);
            csl::ut::InplaceMoveArray<Unk1, 4> interpolationJobs;
            unsigned int interpolationGroupEnabledBits; // bit nr = index of group
            unsigned int interpolationGroupCount;

            Interpolator(csl::fnd::IAllocator* allocator, T* target);
            virtual void AddJob(uint64_t ownerId, const void* value, unsigned int interpolationGroupMemberBits, unsigned int priority, float interpolationTime, uint32_t unk6Param) override;
            virtual void UpdateJob(uint64_t ownerId, const void* value) override;
            virtual void ReverseJob(uint64_t ownerId, float interpolationTime) override;
            virtual void Update(float deltaTime) override;
            virtual void SetTweenPosition(uint64_t ownerId, float position) override;
        };

        struct NeedleFXSceneConfigInterpolators {
            Interpolator<app::rfl::FxRenderTargetSetting>* fxRenderTargetSettingInterpolator;
            Interpolator<app::rfl::FxAntiAliasing>* fxAntiAliasingInterpolator;
            Interpolator<app::rfl::StageCommonAtmosphereParameter>* stageCommonAtmosphereParameterInterpolator;
            Interpolator<app::rfl::FxLODParameter>* fxLODParameterInterpolator;
            Interpolator<app::rfl::FxDetailParameter>* fxDetailParameterInterpolator;
            Interpolator<app::rfl::FxDynamicResolutionParameter>* fxDynamicResolutionParameterInterpolator;
            Interpolator<app::rfl::StageCommonTimeProgressParameter>* stageCommonTimeProgressParameterInterpolator;
        };

        app::rfl::NeedleFxParameter parameters;
        app::rfl::NeedleFxSceneConfig sceneConfig;
        InterpolatorBase* paramInterpolators[40];
        NeedleFXSceneConfigInterpolators sceneConfigInterpolators;
        SceneParameters* sceneParameters[2];
        csl::ut::MoveArray<FxParamExtension*> extensions;
        int currentSceneParameters;
        csl::fnd::Mutex mutex;
        uint16_t unk107;
        uint8_t unk108;

    public:
        virtual void OnAddedToGame() override;
        virtual void OnRemovedFromGame() override;
		virtual void PostStepCallback(hh::game::GameManager* gameManager, const hh::fnd::SUpdateInfo& updateInfo) override;

        void SetSceneParameters(SceneParameters* parameters, int idx);

		GAMESERVICE_CLASS_DECLARATION(FxParamManager)
    };
}
