#pragma once

namespace app::dv{
    class DvElementQTEAccel : public AppDvElementBase{
    public:
        struct Data {
        public:
            int unk0;
            int unk1;
            int dword8;
            int dwordC;
            char byte10;
        };

        void* unk0;
        void* unk1;
        void* unk2;
        void* unk3;
        int unk4;
        int unk5;

        virtual void Setup(void* unk) override;
        virtual bool UnkFunc1() override;
        virtual void* UnkFunc2() override;
        virtual void AppUnkFunc0() override;
        virtual void AppUnkFunc1() override;

        APP_DV_ELEMENT_DECLARATION_BASE(DvElementQTEAccel)
    };
}
