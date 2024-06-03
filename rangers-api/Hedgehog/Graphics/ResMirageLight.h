#pragma once

namespace hh::gfx {
    class ResMirageLight : public fnd::ManagedResource {
    public:
        csl::math::Vector4 unk101;
        csl::math::Vector4 unk102;
        csl::math::Vector4 unk103;
        uint32_t unk104;
        uint32_t unk105;

        virtual void Load(void* data, size_t size) override;
        virtual void Unload() override {}
        virtual void Reload(void* data, size_t size) override;

        MANAGED_RESOURCE_CLASS_DECLARATION(ResMirageLight)
    };
}
