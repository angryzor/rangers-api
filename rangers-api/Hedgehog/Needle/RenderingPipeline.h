#pragma once

#ifdef AddJob
#undef AddJob
#endif

namespace hh::needle {
    class GlobalParameterBuilder;
    struct GatherRenderingPassContext;
    struct DrawPassIdToIndexMap;
    struct DrawPassInfo {
        DrawPassIdToIndexMap* drawPassIdToIndexMap;
        GatherRenderingPassContext* pGatherRenderingPassContext;
        uint8_t byte268;
    };
    class PipelineInfo : public NeedleObject {
    public:
        uint32_t dword8;
        DrawPassInfo drawPassInfo;
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
        uint32_t drawPassCount;
        uint32_t currentPass;
        uint64_t qword180;
        uint32_t dword188;
        RenderUnit* renderUnit;
        uint64_t qword198;
        CScratchMemoryContext* scratchMemoryContext;

        PipelineInfo(CNameIDObject* renderUnitNameId);
        PipelineInfo(const PipelineInfo& other);
        PipelineInfo& operator=(const PipelineInfo& other);

        virtual uint64_t UnkFunc1();

        void SetDrawPassInfo(const DrawPassInfo& drawPassInfo);
        const DrawPassInfo& GetDrawPassInfo() const;

        template<typename T> SceneParamContainer::ParamHolder<T>* GetSceneParam();
        template<> SceneParamContainer::ParamHolder<FxBloomParameter>* GetSceneParam();
        template<> SceneParamContainer::ParamHolder<FxDOFParameter>* GetSceneParam();
        template<> SceneParamContainer::ParamHolder<FxColorContrastParameter>* GetSceneParam();
        template<> SceneParamContainer::ParamHolder<FxToneMapParameter>* GetSceneParam();
        template<> SceneParamContainer::ParamHolder<FxCameraControlParameter>* GetSceneParam();
        template<> SceneParamContainer::ParamHolder<FxShadowMapParameter>* GetSceneParam();
        template<> SceneParamContainer::ParamHolder<FxShadowHeightMapParameter>* GetSceneParam();
        template<> SceneParamContainer::ParamHolder<FxVolumetricShadowParameter>* GetSceneParam();
        template<> SceneParamContainer::ParamHolder<FxScreenBlurParameter>* GetSceneParam();
        template<> SceneParamContainer::ParamHolder<FxSSAOParameter>* GetSceneParam();
        template<> SceneParamContainer::ParamHolder<FxSHLightFieldParameter>* GetSceneParam();
        template<> SceneParamContainer::ParamHolder<FxLightScatteringParameter>* GetSceneParam();
        template<> SceneParamContainer::ParamHolder<FxRLRParameter>* GetSceneParam();
        template<> SceneParamContainer::ParamHolder<FxSSGIParameter>* GetSceneParam();
        template<> SceneParamContainer::ParamHolder<FxPlanarReflectionParameter>* GetSceneParam();
        template<> SceneParamContainer::ParamHolder<FxOcclusionCapsuleParameter>* GetSceneParam();
        template<> SceneParamContainer::ParamHolder<FxGodrayParameter>* GetSceneParam();
        template<> SceneParamContainer::ParamHolder<FxScreenSpaceGodrayParameter>* GetSceneParam();
        template<> SceneParamContainer::ParamHolder<FxHeatHazeParameter>* GetSceneParam();
        template<> SceneParamContainer::ParamHolder<FxSceneEnvironmentParameter>* GetSceneParam();
        template<> SceneParamContainer::ParamHolder<FxRenderOption>* GetSceneParam();
        template<> SceneParamContainer::ParamHolder<FxSGGIParameter>* GetSceneParam();
        template<> SceneParamContainer::ParamHolder<FxTAAParameter>* GetSceneParam();
        template<> SceneParamContainer::ParamHolder<FxEffectParameter>* GetSceneParam();
        template<> SceneParamContainer::ParamHolder<FxAtmosphereParameter>* GetSceneParam();
        template<> SceneParamContainer::ParamHolder<FxDensityParameter>* GetSceneParam();
        template<> SceneParamContainer::ParamHolder<FxWindComputeParameter>* GetSceneParam();
        template<> SceneParamContainer::ParamHolder<FxGpuEnvironmentParameter>* GetSceneParam();
        template<> SceneParamContainer::ParamHolder<FxInteractiveWaveParameter>* GetSceneParam();
        template<> SceneParamContainer::ParamHolder<FxChromaticAberrationParameter>* GetSceneParam();
        template<> SceneParamContainer::ParamHolder<FxVignetteParameter>* GetSceneParam();
        template<> SceneParamContainer::ParamHolder<FxTerrainMaterialBlendingParameter>* GetSceneParam();
        template<> SceneParamContainer::ParamHolder<FxWeatherParameter>* GetSceneParam();
        template<> SceneParamContainer::ParamHolder<FxColorAccessibilityFilterParameter>* GetSceneParam();
        template<> SceneParamContainer::ParamHolder<FxCyberNoiseEffectParameter>* GetSceneParam();
        template<> SceneParamContainer::ParamHolder<FxCyberSpaceStartNoiseParameter>* GetSceneParam();
        template<> SceneParamContainer::ParamHolder<FxCyberNPCSSEffectRenderParameter>* GetSceneParam();
        template<> SceneParamContainer::ParamHolder<FxFieldScanEffectRenderParameter>* GetSceneParam();
        template<> SceneParamContainer::ParamHolder<FxSeparableSSSParameter>* GetSceneParam();

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
        virtual void RenderMatchingJobs(PipelineInfo* pipelineInfo, uint64_t mask, bool renderNonMatching); // mask bits seem to correspond to render passes, renderNonMatching inverts the mask
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
