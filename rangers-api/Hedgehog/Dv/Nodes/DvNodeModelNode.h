#pragma once

namespace hh::dv{
    class DvNodeModelNode : public DvNodeBase {
    public:
        struct DvNodeModelNodeData {
            int field00;
            char nodeName[64];
            int padding[3];
        };

        int unk0;
        float unk1;
        DvNodeModelNodeData binaryData;
        int nodeID;

        virtual void Setup();
        virtual bool UnkFunc1();

        DV_NODE_DECLARATION_BASE(DvNodeModelNode)
    };
}