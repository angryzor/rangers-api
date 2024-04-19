#pragma once

namespace hh::gfnd {
    class RenderManagerBase : public fnd::BaseObject, public game::GameUpdateListener, public csl::fnd::Singleton<RenderManagerBase> {
    public:
        RenderManagerBase(csl::fnd::IAllocator* allocator);

        virtual uint64_t UnkFunc1() = 0;
        virtual uint64_t UnkFunc2() = 0;
        virtual uint64_t UnkFunc3() = 0;
        virtual void UnkFunc4() {}
        virtual uint64_t UnkFunc5() = 0;

		virtual void PostGameUpdateCallback(game::GameManager* gameManager, const fnd::SUpdateInfo& updateInfo) override;
    };
}