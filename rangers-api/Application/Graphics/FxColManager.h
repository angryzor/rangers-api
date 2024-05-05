#pragma once

namespace app::gfx {
    class FxColManager
        : public hh::game::GameService {
    public:
		virtual void* GetRuntimeTypeInfo() override;
		virtual bool ProcessMessage(hh::fnd::Message& message) override;
		virtual void OnAddedToGame() override;
		virtual void OnRemovedFromGame() override;
		GAMESERVICE_CLASS_DECLARATION(FxColManager)
    };
}
