#pragma once

namespace app::dv{
    class DvElementFootIk : public AppDvElementBase{
    public:
        struct Data {}; // unknown

        void* unk0;

        virtual bool UnkFunc1() override;
        virtual void* UnkFunc2() override;
        virtual void AppUnkFunc0() override;

        APP_DV_ELEMENT_DECLARATION_BASE(DvElementFootIk)
    };
}