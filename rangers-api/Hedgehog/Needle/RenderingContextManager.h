#pragma once

namespace hh::needle {
    class RenderingContextManager : public NeedleRefcountObject {
    public:
        csl::fnd::IAllocator* allocator;
        RenderingDevice* renderingDevice;
        uint32_t unk1;
        uint64_t unk2;
        csl::ut::MoveArray<intrusive_ptr<SyncDrawContext>> drawContexts;
        csl::ut::MoveArray<void*> unk3;
        bool unk4;
        bool unk5;

        RenderingContextManager(RenderingDevice* renderingDevice, csl::fnd::IAllocator* allocator, unsigned int drawContextCount);
    };
}
