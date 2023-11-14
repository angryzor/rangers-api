#pragma once

namespace csl::fnd
{
	class IAllocator
	{
	public:
		virtual ~IAllocator() = default;
		
		virtual void* Alloc(size_t in_size, size_t in_alignment) = 0;
		virtual void Free(void* in_pMemory) = 0;
	};
}

inline void* operator new(size_t count, csl::fnd::IAllocator* pAllocator) {
	return pAllocator->Alloc(count, 8);
}

inline void operator delete(void* ptr, csl::fnd::IAllocator* pAllocator) noexcept {
	pAllocator->Free(ptr);
}

//inline void* operator new(size_t count, csl::fnd::IAllocator* pAllocator, size_t alignment) {
//	return pAllocator->Alloc(count, alignment);
//}
//
//inline void* operator new(size_t count, csl::fnd::IAllocator* pAllocator) {
//	return operator new(count, pAllocator, 8);
//}
//
//inline void operator delete(void* ptr, csl::fnd::IAllocator* pAllocator, size_t alignment) noexcept {
//	pAllocator->Free(ptr);
//}
//
//inline void operator delete(void* ptr, csl::fnd::IAllocator* pAllocator) noexcept {
//	operator delete(ptr, pAllocator, 8);
//}
