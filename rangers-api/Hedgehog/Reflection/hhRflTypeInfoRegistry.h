#pragma once

namespace hh::fnd
{
	class RflTypeInfoRegistry : public RflRegistryTemplate<RflTypeInfo>, public csl::fnd::Singleton<RflTypeInfoRegistry>
	{
		static RflTypeInfo* staticRflTypeInfos[2081];
	public:
		void* ConstructObject(csl::fnd::IAllocator* pAllocator, const char* pName) const;

		void ConstructObject(csl::fnd::IAllocator* pAllocator, void* placement, const char* pName) const
		{
			auto* pTypeInfo = GetByName(pName);
			if (!pTypeInfo)
				return;

			pTypeInfo->ConstructObject(placement, pAllocator);
		}

		void FinishLoadedObject(void* pInstance, const char* pName) const
		{
			auto* pTypeInfo = GetByName(pName);
			if (!pTypeInfo)
				return;

			pTypeInfo->FinishLoadedObject(pInstance);
		}

		void CleanupLoadedObject(void* pInstance, const char* pName) const;
	};
}

// DEFINE_SINGLETONPTR(hh::fnd::RflTypeInfoRegistry, ASLR(0x00FD4310));