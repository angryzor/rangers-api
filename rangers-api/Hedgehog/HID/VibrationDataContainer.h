#pragma once

namespace hh::hid{
    class VibrationDataContainer : public fnd::ReferencedObject{
    public:
        void* unk0;
        int unk1;
        float unk2;
        float unk3;
        int unk4;
        csl::ut::MoveArray<void*> unk5;
        int unk6;
        int unk7;
        int unk8;
        int unk9;
        float unk10;
        int unk11;
        int64_t unk12;

        VibrationDataContainer(csl::fnd::IAllocator* allocator);
    };
}