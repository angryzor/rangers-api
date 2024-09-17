#pragma once

namespace hh::anim {
    class AsmResourceManager : public fnd::ReferencedObject {
    public:
        struct ClipBindInfo {
            uint64_t unk1;
            float unk2;
            fnd::Reference<ResAnimation> resource;
        };

        struct StateBindInfo {
            float unk1;
            uint8_t unk2;
        };

        struct BlendMaskInfo {
            csl::ut::MoveArray<char> masks;
        };

        struct BindInfo {
            ResAnimator* animatorResource;
            ResSkeleton* skeletonResource;
        };

        fnd::Reference<ResAnimator> animatorResource;
        uint64_t unk0b;
        csl::ut::MoveArray<ClipBindInfo> clipBindInfos;
        csl::ut::MoveArray<StateBindInfo> stateBindInfos; // index is state ID, see AnimationState ctor
        csl::ut::MoveArray<BlendMaskInfo> blendMaskInfos;
        csl::ut::MoveArray<void*> unk4;
        csl::ut::MoveArray<void*> unk5;
        float unk6;
        uint8_t unk7;

        static AsmResourceManager* Load(const char* resourceName, const char* name, csl::fnd::IAllocator* allocator);
        static AsmResourceManager* Create(csl::fnd::IAllocator* allocator);
        AsmResourceManager(csl::fnd::IAllocator* allocator);
        void Setup(const BindInfo& bindInfo);
        void Bind(const BindInfo& bindInfo, fnd::ResourceResolver& resourceResolver);
        bool ShouldReloadResource(fnd::ManagedResource* resource);
        unsigned int GetNumBones() const;
    };
}
