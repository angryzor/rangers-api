#pragma once

namespace hh::dv{
    class DvNodeStage : public DvNodeBase{
    public:
        virtual void Setup();
        virtual void UnkFunc1();

        DV_NODE_DECLARATION_BASE(DvNodeStage)
    };
}