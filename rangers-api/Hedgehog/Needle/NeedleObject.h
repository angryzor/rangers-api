#pragma once

namespace hh::needle {
    void AllocateNeedle(size_t size, size_t alignment);
    void FreeNeedle(void* ptr);

    class NeedleObject {
    public:
        NeedleObject(csl::fnd::IAllocator* allocator);
        static void* operator new(size_t count, void* ptr);
        static NeedleObject* AllocateObjectMemory(size_t size, size_t alignment);

		static void operator delete(void* ptr, void* place) noexcept {
		}

		static void* operator new(size_t count) {
			return AllocateObjectMemory(count, 0);
		}

		static void operator delete(void* ptr) noexcept {
			FreeNeedle(ptr);
		}

		// static void operator delete(void* ptr, size_t size) noexcept {
		// 	FreeNeedle(ptr);
		// } 

		static void* operator new(size_t count, std::align_val_t al) {
			return AllocateObjectMemory(count, static_cast<size_t>(al));
		}

		static void operator delete(void* ptr, std::align_val_t al) noexcept {
			FreeNeedle(ptr);
		}
    };
}
