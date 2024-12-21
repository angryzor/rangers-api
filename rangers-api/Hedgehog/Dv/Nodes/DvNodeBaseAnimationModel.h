#pragma once

namespace hh::dv{
    class DvNodeBaseAnimationModel : public DvNodeBase{
    public:
        struct DvNodeCharacterData {
            int useName3;
            char modelName[64];
            char skeletonName[64];
            char name3[64];
            char unkData[76];
        };

        DvNodeCharacterData binaryData;
        hh::game::GameObject* nodeCharacterObj;
        csl::ut::MoveArray<void*> guids;
        int unk0;
        float unk1;
        csl::ut::MoveArray<void*> unk3;
        float unk4;
        uint32_t unk5;
        uint32_t unk6;

        virtual void Setup();
        virtual void DeleteCharacterObject();
        virtual void UnkCharacterObject0();
        virtual bool UnkCharacterObject1();
        virtual void* GetRuntimeTypeInfo();
        virtual char UnkFunc0();

        DvNodeBaseAnimationModel(csl::fnd::IAllocator* allocator);
    };
}