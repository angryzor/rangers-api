#pragma once

namespace hh::snd {
    class SoundManagerCri : public SoundManager, public fnd::ResourceManager::ResourceListener {
    public:
        ResAtomConfig* atomConfig;
        csl::ut::MoveArray<hh::fnd::Reference<hh::snd::ResAtomCueSheet>> cueSheets;
        
		virtual void* GetRuntimeTypeInfo() override;
        virtual void ResourceLoadedCallback(fnd::ManagedResource* resource) override;
        virtual void ResourceUnloadedCallback(fnd::ManagedResource* resource) override;

        GAMESERVICE_CLASS_DECLARATION(SoundManagerCri);
    };
}