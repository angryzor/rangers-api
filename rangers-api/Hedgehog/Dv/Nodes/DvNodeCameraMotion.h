#pragma once

namespace hh::dv{
    class DvNodeCameraMotion : public DvNodeBase {
    public:
        struct DvNodeCameraMotionData {
            int flags;
            int start;
            int end;
            int field0c;
        };

        DvNodeCameraMotionData binaryData;
        csl::ut::MoveArray<void*> unkArray;
        int unk3;
        int unk4;

        virtual void UnkFunc0();
        virtual void UnkFunc1();
        virtual bool UnkFunc2();
        virtual bool IsUnkFlag0() override;

        DV_NODE_DECLARATION_BASE(DvNodeCameraMotion)
    };
}