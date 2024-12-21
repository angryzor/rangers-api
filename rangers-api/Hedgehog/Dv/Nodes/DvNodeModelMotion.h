#pragma once

namespace hh::dv{
    class DvNodeModelMotion : public DvNodeCharacterMotion{
    public:
        struct DvNodeModelMotionData {
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

        DvNodeModelMotionData binaryData;

        DV_NODE_DECLARATION_BASE(DvNodeModelMotion)
    };
}