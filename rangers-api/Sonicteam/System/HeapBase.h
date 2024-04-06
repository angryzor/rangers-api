#pragma once

namespace csl::fnd {
    struct HeapBlock {

    };

    struct HeapStatistics {
        size_t bufferSize;
        size_t used;
        size_t allocated;
        unsigned int liveAllocations;
        unsigned int totalAllocations;
    };

    class alignas(8) HeapBase {
        void* unk0;
        bool unk1;
        char name[10];
        uint64_t unk2;
        HeapBase* parent;
        csl::ut::LinkList<HeapBase> children;
        uint64_t unk8;
        uint64_t unk9;
        bool initialized;
        uint32_t unk11;
        uint32_t unk12;
        bool unk13;
        uint64_t unk14;
        uint64_t unk15;
        uint32_t unk16;
    public:
        HeapBase(const char* name);
        virtual ~HeapBase() = default;
        virtual void* Alloc(size_t in_size, size_t in_alignment) = 0;
        virtual void* AllocBottom(size_t in_size, size_t in_alignment) = 0;
        virtual void Free(void* in_pMemory) = 0;
        virtual int64_t UnkFunc1() = 0;
        virtual int64_t UnkFunc2() = 0;
        virtual int64_t UnkFunc3() = 0;
        virtual int64_t UnkFunc4() = 0;
        virtual void UnkFunc5() {}
        virtual void GetStatistics(HeapStatistics& statistics) = 0;
        virtual size_t GetBufferStart() = 0;
        virtual size_t GetBufferEnd() = 0;
        virtual unsigned int GetLiveAllocations() = 0;
        virtual unsigned int GetTotalAllocations() = 0;
        virtual bool UnkFunc11() { return true; }
        virtual void UnkFunc12() {}
        virtual int64_t UnkFunc13() = 0;
        virtual int64_t UnkFunc14();
        virtual int64_t UnkFunc15();
        virtual int64_t UnkFunc16();
        virtual void UnkFunc17() {}
        virtual bool UnkFunc18() { return false; }
        virtual int UnkFunc19() { return -1; }
        virtual int64_t UnkFunc20();
        virtual bool UnkFunc21() { return false; }
        virtual void UnkFunc22();// {}
        virtual void UnkFunc23();// {}
        virtual bool UnkFunc24() { return false; }
        virtual void UnkFunc25() {}

        void SetName(const char* name);
        inline const char* GetName() {
            return name;
        }
        inline HeapBase* GetParent() {
            return parent;
        }

        inline const csl::ut::LinkList<HeapBase>& GetChildren() {
            return children;
        }
    };
}
