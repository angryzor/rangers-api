#pragma once

namespace hh::dv{
    class DvNodeCharacterMotion : public DvNodeBase {
    public:
        struct DvNodeCharacterMotionData {
            int flags;
            int start;
            int end;
            int field0c;
            char asmState[8];
            float speed;
            int unk0;
            int unk1;
            int unk2;
            int unk3;
            int unk4;
        };

        DvNodeCharacterMotionData binaryData;
        int unk1;
        int unk2;
        int unk3;
        float unk4; //prolly a bitset
        csl::math::Transform transform0;
        csl::math::Transform transform1;
        float unk5;

        virtual void Setup();
        virtual void SetCharacterState(); // not sure about this one
        virtual bool Update();
        virtual bool IsUnkFlag0() override;

        DV_NODE_DECLARATION_BASE(DvNodeCharacterMotion)
    };
}