#pragma once

namespace hh::dv {
    class DvPageConditionRandom : public DvPageConditionBase {
    public:
        long long unk5;
        long long unk6;

        virtual void UnkFunc0() override;
        virtual bool UnkFunc5() override;
    };
}