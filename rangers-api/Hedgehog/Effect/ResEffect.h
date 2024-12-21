#pragma once

namespace hh::eff {
    class ResEffect : public fnd::ManagedResource {
    public:
        bool offsetsFixed;
        csl::ut::StringMap<ResEffect*> childEffects;
        csl::ut::MoveArray<char*> childEffectNames;
        csl::ut::StringMap<gfnd::ResTexture*> textures;
        csl::ut::StringMap<gfx::ResModel*> models;

        virtual void Load(void* data, size_t size) override;
        virtual void Unload() override;
        virtual void Resolve(fnd::ResourceResolver& resolver) override;
        virtual void Reload(void* data, size_t size) override {}

        MANAGED_RESOURCE_CLASS_DECLARATION(ResEffect)
    };
}
