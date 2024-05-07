#pragma once

namespace hh::fnd
{
    //hh::fnd::Handle<hh::fnd::Messenger,hh::fnd::HandleManager<hh::fnd::Messenger>>
	class HandleManager : public ReferencedObject {
        csl::ut::MoveArray<RefByHandleObject*> objects;
        void* begin;
        void* end;
        void* count;
        void* field_50;
        void* current;
        void* pAllocator2;
        volatile int spinlock;
    public:
        HandleManager(csl::fnd::IAllocator* pAllocator, size_t size);
        static HandleManager* Create(csl::fnd::IAllocator* pAllocator, size_t size);
        void AddObject(RefByHandleObject* obj);
        void RemoveObject(RefByHandleObject* obj);
    };
}
