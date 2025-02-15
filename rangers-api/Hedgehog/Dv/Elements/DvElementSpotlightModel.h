#pragma once

namespace hh::dv{
    class DvElementSpotlightModel : public DvElementBase {
    public:
        struct Data {
        public:
            bool curveEnabled;
            csl::math::Position position;
            csl::math::Position finishPosition;
            csl::math::Position rotation;
            unsigned int color[3];
            float range;
            float intensity;
            float falloff;
            float angle;
            float unk1[6];
            float curveData[64];
        };

        Data binaryData;
        hh::fnd::Reference<hh::game::GameObject> light;
        csl::math::Vector4 unk0;
        csl::math::Vector4 unk1;
        void* unk2;
        
        virtual void Setup(void* unk) override;
        virtual bool UnkFunc1() override;
        virtual void* UnkFunc2() override;
        virtual void SetData(void* data) override;
        virtual void UnkFunc4() override;
        virtual void UnkFunc6() override;

        DV_ELEMENT_DECLARATION_BASE(DvElementSpotlightModel)
    };
}