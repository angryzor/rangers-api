#pragma once

namespace hh::dv{
    class DvNodeFolderCondition : public DvNodeBase{
    public:
        int64_t unk0;

        virtual int Setup(void* unk);
        virtual void SetUnkFlag1() override;
        virtual void* UnkFunc1();
        virtual char UnkFunc2(int unk);
        virtual bool IsUnkFlag0() override;
        virtual bool GetUnkFlag0();

        DV_NODE_DECLARATION_BASE(DvNodeFolderCondition)
    };
}