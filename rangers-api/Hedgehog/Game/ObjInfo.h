#pragma once

namespace hh::game {
    class ObjInfo;
    class ObjInfoContainer;

    class ObjInfoClass {
    public:
        const char *pName;
        ObjInfo* (*Create)(csl::fnd::IAllocator* pAllocator);
    };

    class ObjInfo : public fnd::ReferencedObject {
        void* unk5;
        fnd::ResourceLoader* resourceLoader;
        void* unk7;
        GameManager* gameManager;
    public:
        ObjInfo(csl::fnd::IAllocator* pAllocator);
        virtual void Load() {}
        virtual void Initialize() {}
        virtual void Finalize() {}
        virtual const char* GetInfoName() { return ""; }
        virtual void RegistCallback(ObjInfoContainer* container) {}
    };
}
