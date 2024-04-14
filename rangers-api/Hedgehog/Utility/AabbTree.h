#pragma once

namespace hh::ut {
    bool IntersectionRay3Aabb(const csl::math::Vector3& from, const csl::math::Vector3& direction, float distance, const csl::geom::Aabb& aabb, float* entry, float* exit);

    class AabbTreeHandle {
        unsigned int handle;
    };
    //  {
    // public:
    //     AabbTreeHandle(csl::fnd::IAllocator* allocator);
    //     static AabbTreeHandle* Create(csl::fnd::IAllocator* allocator);
    // };

    class AabbTree : public fnd::ReferencedObject {
        struct Unk1 {
            csl::ut::MoveArray<AabbTreeHandle*> handles;
        };

        enum class Flag : uint8_t {
            REBUILD_REQUIRED,
            OBJECT_ADDED,
        };

        volatile int unk1;
        Flag flags;
        uint32_t unkUnkParam2;
        uint32_t unk3;
        Unk1 unk4;
        csl::ut::MoveArray<csl::geom::Aabb> unk5;
        csl::ut::MoveArray<void*> unk6;
        csl::ut::MoveArray<void*> unk7;
        csl::ut::MoveArray<void*> unk8;

        void BuildR(const csl::geom::Aabb& aabb, unsigned short* unkParam10, unsigned short* unkParam2, int unkParam3, unsigned int unkParam4);
        
    public:
        AabbTree(csl::fnd::IAllocator* allocator, int unkParam1, int unkParam2);
        static AabbTree* Create(csl::fnd::IAllocator* allocator, int unkParam1, int unkParam2);
        void AddObject(hh::ut::AabbTreeHandle* handle, const csl::geom::Aabb& aabb);
        void UpdateObject(hh::ut::AabbTreeHandle* handle, const csl::geom::Aabb& aabb);
        void AddOrUpdateObject(hh::ut::AabbTreeHandle* handle, const csl::geom::Aabb& aabb);
        bool IsObjectInTree(hh::ut::AabbTreeHandle* handle);
        void RemoveObject(hh::ut::AabbTreeHandle* handle);
        bool GetAabb(csl::geom::Aabb* aabb);
        void GetAllAabbs(csl::ut::MoveArray<csl::geom::Aabb>* aabbs) const;
        bool Raycast(const csl::math::Vector3& from, const csl::math::Vector3& to, csl::ut::MoveArray<hh::ut::AabbTreeHandle*>& results) const;
        void QueryPoint(const csl::math::Vector3& point, csl::ut::MoveArray<hh::ut::AabbTreeHandle*>& results) const;
        void QueryAabb(const csl::geom::Aabb& aabb, csl::ut::MoveArray<hh::ut::AabbTreeHandle*>& results) const;
        void QueryAabbBruteForce(const csl::geom::Aabb& aabb, csl::ut::MoveArray<hh::ut::AabbTreeHandle*>& results) const;
        void Build();
        void Verify();
        bool IsRebuildRequired();
    };
}
