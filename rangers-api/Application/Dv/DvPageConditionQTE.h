#pragma once

namespace app::dv {
    class DvPageConditionQTE : public hh::dv::DvPageConditionBase {
    public:
        struct Data {
        public:
            int unk0;
            int unk1;
            int unk2;
            int unk3;
        };

        Data binaryData;
        evt::EventPlayer* evtPlayer;
        char unk0;

        virtual void Setup(void* setupInfo) override;
        virtual bool UnkFunc5() override;

        static DvPageConditionQTE* Create(csl::fnd::IAllocator* allocator);
    };
}