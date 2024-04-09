#pragma once

namespace hh::fnd {
    // This is NOT SimpleResourceContainer, it's some kind of synchronization object.
    class SimpleResourceContainer : public ReferencedObject {
        class Unk1 : public ReferencedObject {
            const ResourceTypeInfo* typeInfo;
            csl::fnd::Mutex mutex;
        };
        csl::ut::MoveArray<Unk1*> unk1s;
        csl::ut::PointerMap<ResourceTypeInfo*, Unk1*> unk1sByTypeInfo;
    public:
        SimpleResourceContainer(csl::fnd::IAllocator* allocator);
        void LoadFromTypeInfos();
    };
}
