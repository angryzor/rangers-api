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

        struct NeedleFXParameterInterpolators {
            Interpolator<app::rfl::FxBloomParameter>* bloomInterpolator;
            Interpolator<app::rfl::FxDOFParameter>* dofInterpolator;
            Interpolator<app::rfl::FxColorContrastParameter>* colorContrastInterpolator;
            Interpolator<app::rfl::FxToneMapParameter>* tonemapInterpolator;
            Interpolator<app::rfl::FxCameraControlParameter>* cameraControlInterpolator;
            Interpolator<app::rfl::FxShadowMapParameter>* shadowmapInterpolator;
            Interpolator<app::rfl::FxShadowHeightMapParameter>* shadowHeightMapInterpolator;
            Interpolator<app::rfl::FxVolumetricShadowParameter>* volShadowInterpolator;
            Interpolator<app::rfl::FxScreenBlurParameter>* blurInterpolator;
            Interpolator<app::rfl::FxSSAOParameter>* ssaoInterpolator;
            Interpolator<app::rfl::FxSHLightFieldParameter>* shlightfieldInterpolator;
            Interpolator<app::rfl::FxLightScatteringParameter>* lightscatteringInterpolator;
            Interpolator<app::rfl::FxRLRParameter>* rlrInterpolator;
            Interpolator<app::rfl::FxSSGIParameter>* ssgiInterpolator;
            Interpolator<app::rfl::FxPlanarReflectionParameter>* planarReflectionInterpolator;
            Interpolator<app::rfl::FxOcclusionCapsuleParameter>* occlusionCapsuleInterpolator;
            Interpolator<app::rfl::FxGodrayParameter>* godrayInterpolator;
            Interpolator<app::rfl::FxScreenSpaceGodrayParameter>* ssGodrayInterpolator;
            Interpolator<app::rfl::FxHeatHazeParameter>* heatHazeInterpolator;
            Interpolator<app::rfl::FxSceneEnvironmentParameter>* sceneEnvInterpolator;
            Interpolator<app::rfl::FxRenderOption>* renderOptionInterpolator;
            Interpolator<app::rfl::FxSGGIParameter>* sggiInterpolator;
            Interpolator<app::rfl::FxTAAParameter>* taaInterpolator;
            Interpolator<app::rfl::FxEffectParameter>* effectInterpolator;
            Interpolator<app::rfl::FxAtmosphereParameter>* atmosphereInterpolator;
            Interpolator<app::rfl::FxDensityParameter>* densityInterpolator;
            Interpolator<app::rfl::FxWindComputeParameter>* windInterpolator;
            Interpolator<app::rfl::FxGpuEnvironmentParameter>* gpuEnvironmentInterpolator;
            Interpolator<app::rfl::FxInteractiveWaveParameter>* interactiveWaveInterpolator;
            Interpolator<app::rfl::FxChromaticAberrationParameter>* chromaticAberrationInterpolator;
            Interpolator<app::rfl::FxVignetteParameter>* vignetteInterpolator;
            Interpolator<app::rfl::FxTerrainMaterialBlendingParameter>* terrainBlendInterpolator;
            Interpolator<app::rfl::FxWeatherParameter>* weatherInterpolator;
            Interpolator<app::rfl::FxColorAccessibilityFilterParameter>* colorAccessibilityInterpolator;
            Interpolator<app::rfl::FxCyberNoiseEffectParameter>* cyberNoiseInterpolator;
            Interpolator<app::rfl::FxCyberSpaceStartNoiseParameter>* cyberStartNoiseInterpolator;
            Interpolator<app::rfl::FxCyberNPCSSEffectRenderParameter>* cyberNPCSSInterpolator;
            Interpolator<app::rfl::FxDentParameter>* dentInterpolator;
            Interpolator<app::rfl::FxFieldScanEffectRenderParameter>* fieldScanInterpolator;
            Interpolator<app::rfl::FxSeparableSSSParameter>* ssssInterpolator;
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
        NeedleFXParameterInterpolators paramInterpolators;
        NeedleFXSceneConfigInterpolators sceneConfigInterpolators;
        SceneParameters* sceneParameters[2];
        csl::ut::MoveArray<FxParamExtension*> extensions;
        int currentSceneParameters;
        csl::fnd::Mutex mutex;
        uint8_t unk107;
        bool updated;
        uint8_t unk108;
    protected:
        bool UpdateNeedleFxSceneConfigInterpolators();
        bool UpdateNeedleFxParameterInterpolators();

    public:
        virtual void OnAddedToGame() override;
        virtual void OnRemovedFromGame() override;
		virtual void PostStepCallback(hh::game::GameManager* gameManager, const hh::game::GameStepInfo& gameStepInfo) override;

        void SetSceneParameters(SceneParameters* parameters, int idx);

        inline void AddNeedleFxSceneConfigInterpolationJob(uint64_t ownerId, app::rfl::NeedleFxSceneConfig* needleFxSceneConfig, unsigned int priority, float interpolationTime) {
            this->mutex.Lock();
            sceneConfigInterpolators.fxRenderTargetSettingInterpolator->AddJob(ownerId, &needleFxSceneConfig->rendertarget, -1, priority, interpolationTime, -1);
            sceneConfigInterpolators.fxAntiAliasingInterpolator->AddJob(ownerId, &needleFxSceneConfig->antialiasing, -1, priority, interpolationTime, -1);
            sceneConfigInterpolators.stageCommonAtmosphereParameterInterpolator->AddJob(ownerId, &needleFxSceneConfig->atmosphere, -1, priority, interpolationTime, -1);
            sceneConfigInterpolators.fxLODParameterInterpolator->AddJob(ownerId, &needleFxSceneConfig->lod, -1, priority, interpolationTime, -1);
            sceneConfigInterpolators.fxDetailParameterInterpolator->AddJob(ownerId, &needleFxSceneConfig->detail, -1, priority, interpolationTime, -1);
            sceneConfigInterpolators.fxDynamicResolutionParameterInterpolator->AddJob(ownerId, &needleFxSceneConfig->dynamicResolution, -1, priority, interpolationTime, -1);
            sceneConfigInterpolators.stageCommonTimeProgressParameterInterpolator->AddJob(ownerId, &needleFxSceneConfig->timeProgress, -1, priority, interpolationTime, -1);
            this->mutex.Unlock();
            updated |= UpdateNeedleFxSceneConfigInterpolators();
        }
        void AddDefaultNeedleFxSceneConfigInterpolationJob(app::rfl::NeedleFxSceneConfig* needleFxParameter, unsigned int priority);
        inline void UpdateNeedleFxSceneConfigInterpolationJob(uint64_t ownerId, app::rfl::NeedleFxSceneConfig* needleFxSceneConfig) {
            this->mutex.Lock();
            sceneConfigInterpolators.fxRenderTargetSettingInterpolator->UpdateJob(ownerId, &needleFxSceneConfig->rendertarget);
            sceneConfigInterpolators.fxAntiAliasingInterpolator->UpdateJob(ownerId, &needleFxSceneConfig->antialiasing);
            sceneConfigInterpolators.stageCommonAtmosphereParameterInterpolator->UpdateJob(ownerId, &needleFxSceneConfig->atmosphere);
            sceneConfigInterpolators.fxLODParameterInterpolator->UpdateJob(ownerId, &needleFxSceneConfig->lod);
            sceneConfigInterpolators.fxDetailParameterInterpolator->UpdateJob(ownerId, &needleFxSceneConfig->detail);
            sceneConfigInterpolators.fxDynamicResolutionParameterInterpolator->UpdateJob(ownerId, &needleFxSceneConfig->dynamicResolution);
            sceneConfigInterpolators.stageCommonTimeProgressParameterInterpolator->UpdateJob(ownerId, &needleFxSceneConfig->timeProgress);
            this->mutex.Unlock();
            updated |= UpdateNeedleFxSceneConfigInterpolators();
        }
        void UpdateDefaultNeedleFxSceneConfigInterpolationJob(app::rfl::NeedleFxSceneConfig* needleFxParameter);
        inline void RemoveNeedleFxSceneConfigInterpolationJob(uint64_t ownerId, float interpolationTime) {
            this->mutex.Lock();
            sceneConfigInterpolators.fxRenderTargetSettingInterpolator->ReverseJob(ownerId, interpolationTime);
            sceneConfigInterpolators.fxAntiAliasingInterpolator->ReverseJob(ownerId, interpolationTime);
            sceneConfigInterpolators.stageCommonAtmosphereParameterInterpolator->ReverseJob(ownerId, interpolationTime);
            sceneConfigInterpolators.fxLODParameterInterpolator->ReverseJob(ownerId, interpolationTime);
            sceneConfigInterpolators.fxDetailParameterInterpolator->ReverseJob(ownerId, interpolationTime);
            sceneConfigInterpolators.fxDynamicResolutionParameterInterpolator->ReverseJob(ownerId, interpolationTime);
            sceneConfigInterpolators.stageCommonTimeProgressParameterInterpolator->ReverseJob(ownerId, interpolationTime);
            this->mutex.Unlock();
            // updated |= UpdateNeedleFxSceneConfigInterpolators();
        }
    
        void AddNeedleFxParameterInterpolationJob(uint64_t ownerId, app::rfl::NeedleFxParameter* needleFxParameter, unsigned int priority, float interpolationTime);
        void AddDefaultNeedleFxParameterInterpolationJob(app::rfl::NeedleFxParameter* needleFxParameter, unsigned int priority);
        void UpdateDefaultNeedleFxParameterInterpolationJob(app::rfl::NeedleFxParameter* needleFxParameter);
        void UpdateNeedleFxParameterInterpolationJob(uint64_t ownerId, app::rfl::NeedleFxParameter* needleFxParameter);
        inline void RemoveNeedleFxParameterInterpolationJob(uint64_t ownerId, float interpolationTime) {
            this->mutex.Lock();
            paramInterpolators.bloomInterpolator->ReverseJob(ownerId, interpolationTime);
            paramInterpolators.dofInterpolator->ReverseJob(ownerId, interpolationTime);
            paramInterpolators.colorContrastInterpolator->ReverseJob(ownerId, interpolationTime);
            paramInterpolators.tonemapInterpolator->ReverseJob(ownerId, interpolationTime);
            paramInterpolators.cameraControlInterpolator->ReverseJob(ownerId, interpolationTime);
            paramInterpolators.shadowmapInterpolator->ReverseJob(ownerId, interpolationTime);
            paramInterpolators.shadowHeightMapInterpolator->ReverseJob(ownerId, interpolationTime);
            paramInterpolators.volShadowInterpolator->ReverseJob(ownerId, interpolationTime);
            paramInterpolators.blurInterpolator->ReverseJob(ownerId, interpolationTime);
            paramInterpolators.ssaoInterpolator->ReverseJob(ownerId, interpolationTime);
            paramInterpolators.shlightfieldInterpolator->ReverseJob(ownerId, interpolationTime);
            paramInterpolators.lightscatteringInterpolator->ReverseJob(ownerId, interpolationTime);
            paramInterpolators.rlrInterpolator->ReverseJob(ownerId, interpolationTime);
            paramInterpolators.ssgiInterpolator->ReverseJob(ownerId, interpolationTime);
            paramInterpolators.planarReflectionInterpolator->ReverseJob(ownerId, interpolationTime);
            paramInterpolators.occlusionCapsuleInterpolator->ReverseJob(ownerId, interpolationTime);
            paramInterpolators.godrayInterpolator->ReverseJob(ownerId, interpolationTime);
            paramInterpolators.ssGodrayInterpolator->ReverseJob(ownerId, interpolationTime);
            paramInterpolators.heatHazeInterpolator->ReverseJob(ownerId, interpolationTime);
            paramInterpolators.sceneEnvInterpolator->ReverseJob(ownerId, interpolationTime);
            paramInterpolators.renderOptionInterpolator->ReverseJob(ownerId, interpolationTime);
            paramInterpolators.sggiInterpolator->ReverseJob(ownerId, interpolationTime);
            paramInterpolators.taaInterpolator->ReverseJob(ownerId, interpolationTime);
            paramInterpolators.effectInterpolator->ReverseJob(ownerId, interpolationTime);
            paramInterpolators.atmosphereInterpolator->ReverseJob(ownerId, interpolationTime);
            paramInterpolators.densityInterpolator->ReverseJob(ownerId, interpolationTime);
            paramInterpolators.windInterpolator->ReverseJob(ownerId, interpolationTime);
            paramInterpolators.gpuEnvironmentInterpolator->ReverseJob(ownerId, interpolationTime);
            paramInterpolators.interactiveWaveInterpolator->ReverseJob(ownerId, interpolationTime);
            paramInterpolators.chromaticAberrationInterpolator->ReverseJob(ownerId, interpolationTime);
            paramInterpolators.vignetteInterpolator->ReverseJob(ownerId, interpolationTime);
            paramInterpolators.terrainBlendInterpolator->ReverseJob(ownerId, interpolationTime);
            paramInterpolators.weatherInterpolator->ReverseJob(ownerId, interpolationTime);
            paramInterpolators.colorAccessibilityInterpolator->ReverseJob(ownerId, interpolationTime);
            paramInterpolators.cyberNoiseInterpolator->ReverseJob(ownerId, interpolationTime);
            paramInterpolators.cyberStartNoiseInterpolator->ReverseJob(ownerId, interpolationTime);
            paramInterpolators.cyberNPCSSInterpolator->ReverseJob(ownerId, interpolationTime);
            paramInterpolators.dentInterpolator->ReverseJob(ownerId, interpolationTime);
            paramInterpolators.fieldScanInterpolator->ReverseJob(ownerId, interpolationTime);
            paramInterpolators.ssssInterpolator->ReverseJob(ownerId, interpolationTime);
            this->mutex.Unlock();
            // updated |= UpdateNeedleFxParameterInterpolators();
        }

		GAMESERVICE_CLASS_DECLARATION(FxParamManager)
    };
}
