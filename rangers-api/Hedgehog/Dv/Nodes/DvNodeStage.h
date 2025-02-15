#pragma once

namespace hh::dv{
    class DvNodeStage : public DvNodeBase{
    public:
        int unk0;

        virtual void Setup(void* setupInfo) override;
        virtual void Start() override;

        DV_NODE_DECLARATION_BASE(DvNodeStage)
    };
}