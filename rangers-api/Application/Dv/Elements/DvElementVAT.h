#pragma once

namespace app::dv{
    class DvElementVAT : public AppDvElementBase {
    public:
        struct Data {
        public:
            enum class Flags : unsigned int {
                UNK0,
                UNK1, // used in setup
            };

            csl::ut::Bitset<Flags> flags;
            char vatAnimName[64];
            int unk1;
            float speed; // perhaps speed
            int unk3;
            int unk4;
        };

        hh::fnd::ManagedResource* vatAnimRes; // hasn't been reversed

        virtual void Setup(void* unk) override;
        virtual bool UnkFunc1() override;
        virtual void* UnkFunc2() override;
        virtual void AppUnkFunc2() override;
        virtual void* AppUnkFunc3(void* unk0, unsigned int unk1) override;

        APP_DV_ELEMENT_DECLARATION_BASE(DvElementVAT)
    };
}