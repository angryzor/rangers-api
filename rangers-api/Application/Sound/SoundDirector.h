#pragma once

namespace app::snd {
    class SoundDirectorExtension {

    };

    class SoundDirector : public hh::game::GameService, public hh::game::GameStepListener, hh::game::GameManagerListener {
    public:
        struct PlayBgmInfo {
            const char* name;
            uint32_t unk1;
            float unk2a;
            float unk2b;
            float unk2c;
            float unk2d;
            uint32_t unk3;
            uint32_t flags;
            uint8_t unk4;
        };

		virtual void* GetRuntimeTypeInfo() override;
        bool ProcessMessage(hh::fnd::Message& message) override;
		virtual void OnAddedToGame() override;
		virtual void OnRemovedFromGame() override;
		virtual void UpdateCallback(hh::game::GameManager* gameManager, const hh::game::GameStepInfo& gameStepInfo) override;
		virtual void GameServiceRemovedCallback(hh::game::GameService* gameService) override;

        void AddExtension(SoundDirectorExtension* extension);
        void RemoveExtension(SoundDirectorExtension* extension);
        SoundDirectorExtension* GetExtension(unsigned int nameHash);
        void PlayBgm(const PlayBgmInfo& playBgmInfo);

        template<typename T>
        T* GetExtension() {
            return static_cast<T*>(GetExtension(csl::ut::HashString(T::name)));
        }

        GAMESERVICE_CLASS_DECLARATION(SoundDirector)
    };
}
