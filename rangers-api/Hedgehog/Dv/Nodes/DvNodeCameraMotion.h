#pragma once

namespace hh::dv{
    class DvNodeCameraMotion : public DvNodeBase {
    public:
        struct Data {
            int flags;
            int start;
            int end;
            int field0c;
        };

        Data binaryData;
        csl::ut::MoveArray<void*> unkArray;
        int unk3;
        int unk4;

        virtual void Setup(void* setupInfo) override;
        virtual void Start() override;
        virtual void Update(int curFrame) override;
        virtual int GetUpdateTiming() override;

        DV_NODE_DECLARATION_BASE(DvNodeCameraMotion)
    };
}