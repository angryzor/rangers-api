#pragma once

namespace hh::anim {
    class AsmResourceManager : public fnd::ReferencedObject {
    public:
        fnd::Reference<ResAnimator> animatorResource;
        uint64_t unk0b;
        csl::ut::MoveArray<ResAnimation*> animationResources;
        csl::ut::MoveArray<void*> unk2;
        csl::ut::MoveArray<void*> unk3;
        csl::ut::MoveArray<void*> unk4;
        csl::ut::MoveArray<void*> unk5;
        float unk6;
        uint8_t unk7;
        struct Config {
            ResAnimator* animatorResource;
            const char* animatorName; // defninitely not correct
        };

        static AsmResourceManager* Load(const char* resourceName, const char* name, csl::fnd::IAllocator* allocator);
        static AsmResourceManager* Create(csl::fnd::IAllocator* allocator);
        AsmResourceManager(csl::fnd::IAllocator* allocator);
        void Setup(const Config& config);
        bool ShouldReloadResource(fnd::ManagedResource* resource);
        unsigned int GetNumBones() const;
    };
}
