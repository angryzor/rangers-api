#pragma once

namespace hh::dv{
    class DvElementCameraShakeLoop : public DvElementBase {
    public:
        struct Data {
        public:
            int unk0;
            bool enabled;
            float frequency;
            float unk3;
            float unk4;
            float unk5;
            float unk6;
            float unk7;
            float curveData[64];
        };

        Data binaryData;
        int64_t unk0;
        int64_t unk1;
        int64_t unk2;

        virtual void Setup(void* unk) override;
        virtual bool UnkFunc1() override;
        virtual void SetData(void* data) override;

        DV_ELEMENT_DECLARATION_BASE(DvElementCameraShakeLoop)
    };
}