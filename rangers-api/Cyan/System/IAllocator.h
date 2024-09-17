#pragma once

namespace Cyan::System {
    class IAllocator {
    public:
        virtual void* Alloc(size_t size, size_t alignment) = 0;
        virtual void* Alloc2(size_t size, size_t alignment) = 0;
        virtual void Free(void* ptr) = 0;
        virtual void UnkFunc4() = 0;
        virtual void SetUnk1(void* unkParam1) = 0;
        virtual void* GetUnk1() const = 0;
    };
}
