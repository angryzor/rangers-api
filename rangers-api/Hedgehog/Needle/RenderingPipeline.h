#pragma once

#ifdef AddJob
#undef AddJob
#endif

namespace hh::needle {
    class GlobalParameterBuilder;
    class PipelineInfo : public NeedleObject {
    public:
        uint32_t dword8;
        uint64_t qword10;
        uint64_t qword18;
        uint64_t qword20;
        SupportFX::FxRenderParam renderParam;
        SupportFXAll* supportFX;
        uint64_t qword138;
        GlobalParameterBuilder* globalParameterBuilder;
        RenderTarget* renderTarget;
        RenderingContextManager* renderingContextManager;
        CNameIDObject* renderUnitNameId;
        CNameIDObject* sceneNameId;
        uint32_t cameraId;
        SceneParamContainer* sceneParamContainer;
        uint64_t qword178;
        uint64_t qword180;
        uint32_t dword188;
        RenderUnit* renderUnit;
        uint64_t qword198;
        uint64_t qword1A0;

        PipelineInfo(CNameIDObject* renderUnitNameId);
        PipelineInfo(const PipelineInfo& other);

        virtual uint64_t UnkFunc1();

        NeedleType<FxBloomParameter>* GetFxBloomParameter() const;
        NeedleType<FxDOFParameter>* GetFxDOFParameter() const;
        NeedleType<FxColorContrastParameter>* GetFxColorContrastParameter() const;
        NeedleType<FxToneMapParameter>* GetFxToneMapParameter() const;
        NeedleType<FxCameraControlParameter>* GetFxCameraControlParameter() const;
        NeedleType<FxShadowMapParameter>* GetFxShadowMapParameter() const;
        NeedleType<FxShadowHeightMapParameter>* GetFxShadowHeightMapParameter() const;
        NeedleType<FxVolumetricShadowParameter>* GetFxVolumetricShadowParameter() const;
        NeedleType<FxScreenBlurParameter>* GetFxScreenBlurParameter() const;
        NeedleType<FxSSAOParameter>* GetFxSSAOParameter() const;
        NeedleType<FxSHLightFieldParameter>* GetFxSHLightFieldParameter() const;
        NeedleType<FxLightScatteringParameter>* GetFxLightScatteringParameter() const;
        NeedleType<FxRLRParameter>* GetFxRLRParameter() const;
        NeedleType<FxSSGIParameter>* GetFxSSGIParameter() const;
        NeedleType<FxPlanarReflectionParameter>* GetFxPlanarReflectionParameter() const;
        NeedleType<FxOcclusionCapsuleParameter>* GetFxOcclusionCapsuleParameter() const;
        NeedleType<FxGodrayParameter>* GetFxGodrayParameter() const;
        NeedleType<FxScreenSpaceGodrayParameter>* GetFxScreenSpaceGodrayParameter() const;
        NeedleType<FxHeatHazeParameter>* GetFxHeatHazeParameter() const;
        NeedleType<FxSceneEnvironmentParameter>* GetFxSceneEnvironmentParameter() const;
        NeedleType<FxRenderOption>* GetFxRenderOption() const;
        NeedleType<FxSGGIParameter>* GetFxSGGIParameter() const;
        NeedleType<FxTAAParameter>* GetFxTAAParameter() const;
        NeedleType<FxEffectParameter>* GetFxEffectParameter() const;
        NeedleType<FxAtmosphereParameter>* GetFxAtmosphereParameter() const;
        NeedleType<FxDensityParameter>* GetFxDensityParameter() const;
        NeedleType<FxWindComputeParameter>* GetFxWindComputeParameter() const;
        NeedleType<FxGpuEnvironmentParameter>* GetFxGpuEnvironmentParameter() const;
        NeedleType<FxInteractiveWaveParameter>* GetFxInteractiveWaveParameter() const;
        NeedleType<FxChromaticAberrationParameter>* GetFxChromaticAberrationParameter() const;
        NeedleType<FxVignetteParameter>* GetFxVignetteParameter() const;
        NeedleType<FxTerrainMaterialBlendingParameter>* GetFxTerrainMaterialBlendingParameter() const;
        NeedleType<FxWeatherParameter>* GetFxWeatherParameter() const;
        NeedleType<FxColorAccessibilityFilterParameter>* GetFxColorAccessibilityFilterParameter() const;
        NeedleType<FxCyberNoiseEffectParameter>* GetFxCyberNoiseEffectParameter() const;
        NeedleType<FxCyberSpaceStartNoiseParameter>* GetFxCyberSpaceStartNoiseParameter() const;
        NeedleType<FxCyberNPCSSEffectRenderParameter>* GetFxCyberNPCSSEffectRenderParameter() const;
        NeedleType<FxFieldScanEffectRenderParameter>* GetFxFieldScanEffectRenderParameter() const;
        NeedleType<FxSeparableSSSParameter>* GetFxSeparableSSSParameter() const;

        SceneContextManager* GetSceneContextManager() const;
    };

    class RenderingPipeline : public NeedleRefcountObject {
    public:
        csl::ut::MoveArray<RenderJob*> renderJobs;
        csl::fnd::IAllocator* allocator;
        const char* name;
        bool initialized;
        bool jobsAreRunning;

        RenderingPipeline(csl::fnd::IAllocator* allocator, const char* name);

        virtual uint64_t UnkFunc1();
        virtual void UnkFunc2(PipelineInfo* pipelineInfo);
        virtual void UnkFunc3(PipelineInfo* pipelineInfo) {}
        virtual void RenderMatchingJobs(PipelineInfo* pipelineInfo, uint64_t mask, bool renderNonMatching);
        virtual void Initialize();
        virtual void Deinitialize();
        virtual void StartJobs(const RenderJobContext& context);
        virtual void StopJobs();
        virtual uint64_t UnkFunc9() {}
        virtual uint64_t UnkFunc10();
        virtual void InitializeJobs() {}
        virtual void DeinitializeJobs() {}

        void AddJob(RenderJob* job);
        void RemoveJob(RenderJob* job);
    };
}
