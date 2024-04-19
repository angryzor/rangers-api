#pragma once

namespace hh::needle {
    class NeedleObject {
    public:
        NeedleObject(csl::fnd::IAllocator* allocator);
        static void* operator new(size_t count, void* ptr);
        static NeedleObject* AllocateObjectMemory(size_t size, size_t alignment);
    };
}
