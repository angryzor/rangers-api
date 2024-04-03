#pragma once

namespace hh::needle {
    class CScratchMemoryContext {
    public:
        void* memory;
        size_t usedSize;
        size_t allocatedSize;
        size_t unk2;
        size_t unk3;
        size_t unk4;

        CScratchMemoryContext(bool empty);
        ~CScratchMemoryContext();
        void PreAllocInside(size_t size);

        // Return value is nr of pages allocated.
        static unsigned int AllocPoolMemoryPage(unsigned int pageCount);
        static unsigned int AllocLargePoolMemoryPage(unsigned int pageCount);
        static unsigned int FreePoolMemoryPage(unsigned int pageCount);
        static unsigned int FreeLargePoolMemoryPage(unsigned int pageCount);
        static unsigned int GetMaxAllocatablePageSize();
    };
}
