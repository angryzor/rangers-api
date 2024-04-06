#pragma once

namespace csl::fnd {
    class alignas(8) TlsfHeapBase : public HeapBase {
        struct BlockHead {
            uint64_t unk1;
            uint64_t unk2;
            uint64_t unk3;
            uint64_t unk4;
            uint32_t unk5;
            uint32_t unk6[25];
            void* unk7[25][32];
        };

        void* bufferBegin;
        void* bufferEnd;
    public:
        uint32_t liveAllocations;
        uint32_t totalAllocations;
        uint64_t unk102;
        uint64_t unk103;
        uint32_t blockCount;
        uint64_t block;
        bool initialized;
        TlsfHeapBase(const char* name);
        
        virtual void* Alloc(size_t in_size, size_t in_alignment) override;
        virtual void* AllocBottom(size_t in_size, size_t in_alignment) override;
        virtual void Free(void* in_pMemory) override;
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
    };

    template<typename TLock>
    class alignas(8) TlsfHeapTemplate : public TlsfHeapBase {
        TLock m_Lock{};
    public:
        TlsfHeapTemplate(const char* name) : TlsfHeapBase{ name } {}

		virtual void* Alloc(size_t in_size, size_t in_alignment) override;
		virtual void* AllocBottom(size_t in_size, size_t in_alignment) override;
		virtual void Free(void* in_pMemory) override;
        virtual int64_t UnkFunc1() override;
        virtual void UnkFunc5() override;
        virtual int64_t UnkFunc13() override;
    };
}