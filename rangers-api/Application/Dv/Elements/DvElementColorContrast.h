#pragma once

namespace app::dv{
    class DvElementColorContrast : public AppDvElementBase{
    public:
        struct Data {
        public:
            enum class Flags : unsigned int {
                ENABLED,
                CURVE_ENABLED,
                USE_HLS_CORRECTION
            };

            csl::ut::Bitset<Flags> flags;
            float unk0;
            float dynamicRange;
            float crushShadows;
            float crushHighlights;
            float hlsHueOffset;
            float hlsLightnessOffset;
            float hlsSaturationOffset;
            float curveData[32];
        };

        struct UnkData {
        public:
            float unk0;
            float dynamicRange;
            float crushShadows;
            float crushHighlights;
            float hlsHueOffset;
            float hlsLightnessOffset;
            float hlsSaturationOffset;
            float hlsColorizeRate;
            float hlsColorizeHue;
        };

        UnkData data;
        int framesOnScreen;
        bool jobGenerated;

        virtual void Setup(void* unk) override;
        virtual void* UnkFunc2() override;

        APP_DV_ELEMENT_DECLARATION_BASE(DvElementColorContrast)
    };
}