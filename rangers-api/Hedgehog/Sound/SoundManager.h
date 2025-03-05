#pragma once

namespace hh::snd {
    class SoundManager : public game::GameService, game::GameStepListener {
    public:
        csl::ut::MoveArray<GOCSound*> gocSounds;
        csl::ut::MoveArray<SoundHandle> sounds;
        csl::ut::InplaceMoveArray<hh::fnd::Reference<hh::snd::ResAtomConfig>, 1> atomConfigs;

		virtual void* GetRuntimeTypeInfo() override;
		virtual void OnAddedToGame() override;
		virtual void OnRemovedFromGame() override;
		virtual void PostStepCallback(game::GameManager* gameManager, const game::GameStepInfo& gameStepInfo) override;

        GAMESERVICE_CLASS_DECLARATION(SoundManager);
    };
}
