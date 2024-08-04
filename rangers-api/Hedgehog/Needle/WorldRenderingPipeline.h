#pragma once

namespace hh::needle {
    class WorldRenderingPipelineExecContext;
    class WorldRenderingPipeline : public RenderingPipeline {
    public:
        csl::fnd::Mutex mutex;
        uint64_t unk101;
        uint32_t unk102;
        uint64_t unk103;
        uint64_t unk104;
        uint64_t unk105;
        uint64_t unk106;
        uint64_t unk107;
        uint64_t unk108;
        uint32_t enableOcclusionCullingView;
        uint32_t unk109;
        uint64_t unk110;
        uint8_t unk111;
        csl::ut::MoveArray<void*> unk112;
        csl::ut::MoveArray<void*> unk113;
        int unk114;
        uint32_t unk115;

        WorldRenderingPipeline(csl::fnd::IAllocator* allocator);

        WorldRenderingPipelineExecContext* CreateExecContext(unsigned int unkParam);

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
