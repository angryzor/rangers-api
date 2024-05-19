#pragma once

namespace hh::needle {
    class PipelineInfo {

    };

    class RenderingPipeline : public NeedleRefcountObject {
    public:
        csl::ut::MoveArray<void*> unk1;
        csl::fnd::IAllocator* allocator;
        const char* name;
        uint16_t unk2;

        RenderingPipeline(csl::fnd::IAllocator* allocator, const char* name);

        virtual uint64_t UnkFunc1();
        virtual uint64_t UnkFunc2();
        virtual uint64_t UnkFunc3() {}
        virtual uint64_t UnkFunc4();
        virtual uint64_t UnkFunc5();
        virtual uint64_t UnkFunc6();
        virtual uint64_t UnkFunc7();
        virtual uint64_t UnkFunc8();
        virtual uint64_t UnkFunc9() {}
        virtual uint64_t UnkFunc10();
        virtual uint64_t UnkFunc11() {}
        virtual uint64_t UnkFunc12() {}
    };
}