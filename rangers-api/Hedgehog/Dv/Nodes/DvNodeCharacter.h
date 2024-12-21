#pragma once

namespace hh::dv{
    class DvNodeCharacter : public DvNodeBaseAnimationModel {
    public:
        virtual void Setup() override;
        virtual void DeleteCharacterObject() override;
        virtual void UnkFunc1();
        virtual void UnkCharacterObject0() override;
        virtual void UnkCharacterObject2();
        virtual char UnkFunc0() override;

        DV_NODE_DECLARATION_BASE(DvNodeCharacter)
    };
}