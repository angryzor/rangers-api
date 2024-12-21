#pragma once

namespace hh::dv{
    class DvSceneNodeTree : public hh::fnd::BaseObject{
    public:
        uint8_t isLoaded; //always 1 it seems
        int unk1;
        DvNodeBase* mainNode;
        DvParamUpdater* paramUpdater;
        DvSceneControl* parent;
        int diEventManagerDWORDC0;

        DvSceneNodeTree(csl::fnd::IAllocator* allocator);
    };
}