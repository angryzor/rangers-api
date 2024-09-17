#pragma once

namespace hh::anim {
    class AnimationControl : public fnd::ReferencedObject {
    public:
        fnd::Reference<ResAnimation> resource;
        uint64_t unk2;
        uint64_t unk3;

        AnimationControl(csl::fnd::IAllocator* allocator);
        virtual void UnkFunc1(float unkParam1) = 0;
        virtual void UnkFunc2(float unkParam1) = 0;
        virtual float UnkFunc3() const = 0;
        virtual void UnkFunc4(float unkParam1) = 0;
        virtual float UnkFunc5() const = 0;
        virtual void UnkFunc6() = 0;
        virtual void UnkFunc7(float unkParam1) = 0;
        virtual float UnkFunc8() const = 0;
        virtual void UnkFunc9(float unkParam1) = 0;
        virtual float UnkFunc11() const = 0;
        virtual void UnkFunc12(float unkParam1) = 0;
        virtual float UnkFunc13() const = 0;
        virtual void UnkFunc14(uint8_t* unkParam1) = 0;
        virtual void UnkFunc15(float unkParam1) = 0;
        virtual bool UnkFunc16() const = 0;
        virtual bool UnkFunc17() const = 0;
        virtual void UnkFunc18(bool unkParam1) = 0;
    };
}
