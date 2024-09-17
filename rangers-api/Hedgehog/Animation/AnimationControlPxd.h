#pragma once

namespace hh::anim {
    class AnimationControlPxd : public AnimationControl, public fnd::ReloaderListener {
    public:
        uint8_t unk100;
        float unk101;
        float unk102;
        uint32_t unk103;
        uint32_t unk104;
        int unk105;
        float unk106;
        float unk107;
        csl::ut::MoveArray<void*> unk108;
        uint64_t unk109;

        DEFAULT_CREATE_FUNC(AnimationControlPxd);
        virtual void UnkFunc1(float unkParam1) override;
        virtual void UnkFunc2(float unkParam1) override;
        virtual float UnkFunc3() const override;
        virtual void UnkFunc4(float unkParam1) override;
        virtual float UnkFunc5() const override;
        virtual void UnkFunc6() override;
        virtual void UnkFunc7(float unkParam1) override;
        virtual float UnkFunc8() const override;
        virtual void UnkFunc9(float unkParam1) override;
        virtual float UnkFunc11() const override;
        virtual void UnkFunc12(float unkParam1) override;
        virtual float UnkFunc13() const override;
        virtual void UnkFunc14(uint8_t* unkParam1) override;
        virtual void UnkFunc15(float unkParam1) override;
        virtual bool UnkFunc16() const override;
        virtual bool UnkFunc17() const override;
        virtual void UnkFunc18(bool unkParam1) override;
        virtual void PostResourceReloadCallback(fnd::ManagedResource* resource) override;
    };
}
