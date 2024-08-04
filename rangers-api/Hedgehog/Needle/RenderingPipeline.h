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
        uint64_t qword148;
        uint64_t qword150;
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

        virtual uint64_t UnkFunc1();

        FxRenderOption* GetFxRenderOption() const;
        SceneContextManager* GetSceneContextManager() const;
    };

    class RenderingPipeline : public NeedleRefcountObject {
    public:
        csl::ut::MoveArray<RenderJob*> renderJobs;
        csl::fnd::IAllocator* allocator;
        const char* name;
        bool initialized;
        bool jobsRunning;

        RenderingPipeline(csl::fnd::IAllocator* allocator, const char* name);

        virtual uint64_t UnkFunc1();
        virtual void UnkFunc2(PipelineInfo* pipelineInfo);
        virtual void UnkFunc3(PipelineInfo* pipelineInfo) {}
        virtual void RenderMatchingJobs(PipelineInfo* pipelineInfo, uint64_t mask, bool renderNonMatching);
        virtual void Initialize();
        virtual void Deinitialize();
        virtual void StartJobs();
        virtual void StopJobs();
        virtual uint64_t UnkFunc9() {}
        virtual uint64_t UnkFunc10();
        virtual void InitializeJobs() {}
        virtual void DeinitializeJobs() {}

        void AddJob(RenderJob* job);
        void RemoveJob(RenderJob* job);
    };
}
