#pragma once

namespace hh::needle {
    class ModelRenderJobBase : public RenderJob {
    public:
        struct Unk1 {
            int64_t unk1;
            int64_t unk2;
            uint64_t unk3;
            uint32_t unk4;
            int unk5;

            Unk1();
        };

        uint32_t unk101;
        unsigned int viewportId;
        Unk1 unk103[12];

        ModelRenderJobBase(unsigned int viewportId);
        virtual void UnkFunc7(void* unkParam) override {}
        virtual void UnkFunc8() override {}
        virtual void SetUnk103(unsigned int index, const Unk1& newUnk103);
    };
}
