#pragma once

namespace hh::needle {
    class RenderProperty : public NeedleObject {
    public:
        uint16_t unk1;
        uint32_t unk2;
        uint32_t unk3;
        uint32_t unk3a;
        uint64_t unk4;
        uint64_t unk5;
        uint64_t unk6;
        csl::fnd::IAllocator* allocator;

        RenderProperty(csl::fnd::IAllocator* allocator);
    };
}
