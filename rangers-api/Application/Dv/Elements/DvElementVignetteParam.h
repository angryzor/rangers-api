#pragma once

namespace app::dv{
    class DvElementVignetteParam : public AppDvElementBase{
    public:
        struct Data {
        public:
            enum class Flags : unsigned int {
                ENABLED,
                CURVE_ENABLED
            };

            struct VignetteParam {
            public:
                csl::math::Vector2 position;
                csl::math::Vector2 size;
                float scale;
                float rotation;
                float unk0;
                int alpha;
                float unk1;
                float unk2;
                float unk3;
            };

            struct MinMaxParam {
            public:
                float minMaxPenumbraScale[2];
                float bokehScale;
                float minMaxDOFOpacityScale[2];
                float minMaxOpacityScale[2];
                float minMaxOpacityDist[2];
            };

            csl::ut::Bitset<Flags> flags;
            int unk1;
            VignetteParam param0;
            csl::math::Vector2 center;
            csl::math::Vector2 direction;
            float penumbraScale0;
            MinMaxParam mmParam0;
            VignetteParam param1;
            float unk2;
            float penumbraScale1;
            float unk3;
            MinMaxParam mmParam1;
            float curveData[32];
        };

        bool jobGenerated;

        virtual void Update(int currentFrame, csl::math::Transform transform) override;
        virtual bool AddCallback(int currentFrame, csl::math::Transform transform) override;
        virtual void* RemoveCallback() override;

        APP_DV_ELEMENT_DECLARATION_BASE(DvElementVignetteParam)
    };
}
