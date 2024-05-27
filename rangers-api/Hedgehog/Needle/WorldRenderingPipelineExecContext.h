#pragma once

namespace hh::needle {
    class WorldRenderingPipelineExecContext : public NeedleObject {
    public:
        struct Unk1 {
            uint8_t byte470;
            bool byte471;
            uint32_t dword474;
            uint64_t qword478;
            uint32_t dword480;
            uint64_t qword488;
            uint64_t qword490;
            uint64_t qword498;
            uint64_t qword4A0;
            uint64_t qword4A8;
            uint64_t qword4B0;
            uint64_t qword4B8;
            uint64_t qword4C0;
            uint8_t byte4C8;
        };

        uint8_t byte8;
        GatherRenderingPassContext gatherRenderingPassContext;
        uint64_t qword258;
        uint64_t qword260;
        uint8_t byte268;
        PipelineInfo pipelineInfo;
        NeedleRefcountObject* globalParameterBuilder;
        NeedleRefcountObject* unkObj;
        CScratchMemoryContext memCtx;
        uint64_t qword458;
        uint64_t qword460;
        uint32_t dword468;
        Unk1 unk1;

        WorldRenderingPipelineExecContext(unsigned int unkParam);
        virtual ~WorldRenderingPipelineExecContext();
    };
}
