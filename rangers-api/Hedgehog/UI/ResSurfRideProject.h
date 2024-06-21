#pragma once

namespace hh::ui {
    class ResSurfRideProject : public fnd::ManagedResource {
        csl::ut::MoveArray<void*> unk101;
        void* unk102;
        uint16_t unk103;
    public:
        virtual void Load(void* data, size_t size) override;
        virtual void Unload() override;
        virtual void Resolve(hh::fnd::ResourceResolver& resolver) override;
        virtual void Reload(void* data, size_t size) override;
        
        MANAGED_RESOURCE_CLASS_DECLARATION(ResSurfRideProject);
    };
}
