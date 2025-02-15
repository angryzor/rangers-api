#pragma once

namespace app::dv{
    class DvElementTheEndCableObject : public AppDvElementBase{
    public:
        struct Data {
        public:
            int unk0;
            int unk1;
            float curveData[1024];
        };

        hh::fnd::Reference<hh::game::GameObject> unkHandle;
        bool unk1;

        virtual void Setup(void* unk) override;
        virtual bool UnkFunc1() override;
        virtual void* UnkFunc2() override;
        virtual void AppUnkFunc0() override;
        virtual void AppUnkFunc1() override;

        APP_DV_ELEMENT_DECLARATION_BASE(DvElementTheEndCableObject)
    };
}
