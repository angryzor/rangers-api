#pragma once

namespace app::dv{
    class DvElementCameraBlurParam : public AppDvElementBase{
    public:
        struct Data {
        public:
            enum class Flags : unsigned int {
                ENABLED,
                SINGLE_DIRECTION_OPT,
                CURVE_ENABLED
            };
        
            csl::ut::Bitset<Flags> flags;
            int sampleAmount;
            float blurAmount;
            float finishBlurAmount;
            float curveData[32];
        };

        virtual void Setup(void* unk) override;
        virtual bool UnkFunc1() override;
        virtual void* UnkFunc2() override;
        virtual void* AppUnkFunc3(void* unk0, unsigned int unk1) override;

        APP_DV_ELEMENT_DECLARATION_BASE(DvElementCameraBlurParam)
    };
}