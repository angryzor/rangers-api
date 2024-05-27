#pragma once

namespace hh::needle {
    class GatherRenderingPassContext {
        uint64_t unk1;
        CScratchMemoryContext memCtx;
        uint32_t unk2;
        char unk3[512];

    public:
        virtual ~GatherRenderingPassContext();

        GatherRenderingPassContext(unsigned int unk2Param);
    };
}
