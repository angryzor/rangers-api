#pragma once

namespace hh::needle {
    class WorldRenderingPipelineExecContext;
    class WorldRenderingPipeline : public RenderingPipeline {
    public:
        struct RenderParameters {
            SDrawPassSceneSetting* drawPassSettings;
            unsigned int parameterCount;
            unsigned int unk104;
            unsigned int parameterSize;
            unsigned int cullingGroupCount;
            SCullGroupSetting* cullingGroups;
            uint64_t unk107;
            uint32_t occlusionCullingViewIndex; // dunno
            uint32_t unk108a;
            uint32_t enableOcclusionCullingView; // or maybe occlusion culling view type? dunno
            uint32_t unk109;
            uint64_t unk110;
        };
        struct SetupInfo {
            PBRModelInstanceRenderer* modelInstanceRenderer;
            uint32_t drawPassCount;
            RenderParameters renderParameters;
            uint8_t unk111;
        };

        csl::fnd::Mutex mutex;
        SetupInfo settings;
        csl::ut::MoveArray<void*> unk112;
        csl::ut::MoveArray<void*> unk113;
        int unk114;
        uint32_t unk115;

        WorldRenderingPipeline(csl::fnd::IAllocator* allocator);

        WorldRenderingPipelineExecContext* CreateExecContext(unsigned int unkParam);
        void Setup(const SetupInfo& setupInfo);

        virtual uint64_t UnkFunc1() override;
        virtual void UnkFunc2(PipelineInfo* pipelineInfo) override;
        virtual void StopJobs() override;
        virtual void Execute(PipelineInfo* pipelineInfo, WorldRenderingPipelineExecContext* execContext);
        virtual void UnkFunc14() {}
        virtual void UnkFunc15() {}
        virtual void UnkFunc16() {}
        virtual void UnkFunc17() {}
    };
}
