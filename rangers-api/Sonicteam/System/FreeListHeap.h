#pragma once

namespace csl::fnd {
    class FreeListHeapBase : public HeapBase {
        size_t bufferStart;
        size_t bufferEnd;
        uint64_t unk103;
        uint64_t unk104;
        uint64_t unk105;
        size_t unused;
        size_t unallocated;
        unsigned int liveAllocations;
        unsigned int totalAllocations;
        uint32_t unk109;
        uint32_t unk110;
        bool initialized;
    public:
        FreeListHeapBase(const char* name);

        virtual void* Alloc(size_t in_size, size_t in_alignment) override;
        virtual void* AllocBottom(size_t in_size, size_t in_alignment) override;
        virtual int64_t UnkFunc1() override;
        virtual int64_t UnkFunc2() override;
        virtual int64_t UnkFunc3() override;
        virtual int64_t UnkFunc4() override;
        virtual void UnkFunc5() override;
        virtual void GetStatistics(HeapStatistics& statistics) override;
        virtual size_t GetBufferStart() override;
        virtual size_t GetBufferEnd() override;
        virtual unsigned int GetLiveAllocations() override;
        virtual unsigned int GetTotalAllocations() override;
        virtual int64_t UnkFunc13() override;
        virtual bool UnkFunc18() override;
        virtual int UnkFunc19() override;
        virtual int64_t UnkFunc20() override;

        void Initialize(void* unkParam1, void* unkParam2, size_t unkParam3);
    };

    template<typename TLock>
    class alignas(8) FreeListHeapTemplate : public FreeListHeapBase {
        TLock m_Lock;

		void* Alloc(size_t in_size, size_t in_alignment) override
		{
			m_Lock.Lock();
			void* pMemory = FreeListHeapBase::Alloc(in_size, in_alignment);
			m_Lock.Unlock();

			return pMemory;
		}

		void* AllocBottom(size_t in_size, size_t in_alignment) override
		{
			m_Lock.Lock();
			void* pMemory = FreeListHeapBase::AllocBottom(in_size, in_alignment);
			m_Lock.Unlock();

			return pMemory;
		}

		void Free(void* in_pMemory) override
		{
			m_Lock.Lock();
			FreeListHeapBase::Free(in_pMemory);
			m_Lock.Unlock();
		}

        virtual int64_t UnkFunc1() override;
        virtual void UnkFunc5() override;
        virtual int64_t UnkFunc13() override;
        virtual void UnkFunc22() override;
        virtual void UnkFunc23() override;
    };
}
