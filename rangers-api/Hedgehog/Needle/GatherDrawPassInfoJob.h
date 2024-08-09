#pragma once

namespace hh::needle {
    class PipelineInfo;
    class RenderJob;
    class GatherDrawPassInfoJob : public NeedleRefcountObject {
    public:
        RenderJob* renderJob;
        unsigned int viewportId;
        csl::ut::MoveArray<void*> unk1;
        csl::ut::MoveArray<void*> unk2;

        GatherDrawPassInfoJob(RenderJob* renderJob, csl::fnd::IAllocator* allocator, unsigned int viewportId);
        virtual void Run(uint64_t unkParam, const PipelineInfo& pipelineInfo);
    };
}
