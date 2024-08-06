#pragma once

namespace hh::needle {
    class WorldRenderingPipelineExecContext : public NeedleObject {
    public:
        struct Unk1 {
            uint8_t byte470;
            bool byte471;
            uint32_t dword474;
            WorldRenderingPipeline::SetupInfo pipelineSetupInfo;
        };

        uint8_t byte8;
        GatherRenderingPassContext gatherRenderingPassContext;
        uint64_t qword258;
        GatherRenderingPassContext* pGatherRenderingPassContext;
        uint8_t byte268;
        PipelineInfo pipelineInfo;
        intrusive_ptr<GlobalParameterBuilder> globalParameterBuilder;
        intrusive_ptr<ParameterValueObject> globalParameters;
        CScratchMemoryContext memCtx;
        uint64_t qword458;
        uint64_t qword460;
        uint32_t dword468;
        Unk1 unk1;

        WorldRenderingPipelineExecContext(unsigned int unkParam);
        virtual ~WorldRenderingPipelineExecContext();
    };
}
