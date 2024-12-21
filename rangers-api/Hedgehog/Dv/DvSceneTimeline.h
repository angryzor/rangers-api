#pragma once

namespace hh::dv{
    class DvSceneTimeline : public hh::fnd::BaseObject {
    public:
        uint8_t unk0;
        uint8_t unk1[7];
        int currentFrame0;
        int currentFrame1;
        int frameStart;
        int frameEnd;
        int currentCut;
        int unk2;
        int64_t unk3;
        csl::ut::MoveArray<float> cuts;
        csl::ut::MoveArray<void*> unkArray0;
        csl::ut::MoveArray<DvPage*> authPages;
        int64_t unk4;
        int64_t unk5;
        int64_t unk6;
        int64_t unk7;

        DvSceneTimeline(csl::fnd::IAllocator* allocator);
    };
}