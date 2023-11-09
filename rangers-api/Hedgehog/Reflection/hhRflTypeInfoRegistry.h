#pragma once

namespace hh::fnd
{
	class RflTypeInfoRegistry : public RflRegistryTemplate<RflTypeInfo>, csl::fnd::Singleton<RflTypeInfoRegistry>
	{
	public:
		void* ConstructObject(csl::fnd::IAllocator* pAllocator, const char* pName) const
		{
			auto pTypeInfo = GetByName(pName);
			if (!pTypeInfo || !pAllocator)
				return nullptr;

			auto* pInstance = pAllocator->Alloc(pTypeInfo->GetSize(), 16);
			pTypeInfo->ConstructObject(pInstance, pAllocator);
			return pInstance;
		}

		void FinishLoadedObject(void* pInstance, const char* pName) const
		{
			auto* pTypeInfo = GetByName(pName);
			if (!pTypeInfo)
				return;

			pTypeInfo->FinishLoadedObject(pInstance);
		}

		void CleanupLoadedObject(void* pInstance, const char* pName) const
		{
			auto* pTypeInfo = GetByName(pName);
			if (!pTypeInfo)
				return;

			pTypeInfo->CleanupLoadedObject(pInstance);
		}
	};
}

// DEFINE_SINGLETONPTR(hh::fnd::RflTypeInfoRegistry, ASLR(0x00FD4310));