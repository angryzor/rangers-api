#pragma once

namespace app::trr {
	class TerrainManager
        : public hh::game::GameService
        , public hh::game::GameManagerListener
        , public hh::game::GameStepListener
    {
	public:
        class ReloaderListener
            : public hh::fnd::ReferencedObject
            , public hh::fnd::ReloaderListener {
            TerrainManager* manager;
        public:
            virtual void PostResourceReloadCallback(hh::fnd::ManagedResource* resource) override;
        };

        struct SetupInfo {
            const char* stageId;
            const char* stageName;
            uint8_t* staticSectors;
            uint8_t* dynamicSectors;
            uint32_t staticSectorCount;
            uint32_t dynamicSectorCount;
        };

		uint8_t unk1;
        uint64_t unk2;
        uint32_t unk3;
        float unk4;
        uint64_t unk5;
        uint32_t unk6;
        uint64_t unk7;
        uint32_t unk8;
        csl::ut::InplaceMoveArray<csl::math::Vector4, 1> unk9; // not a vector
        csl::ut::MoveArray<void*> unk10;
        int currentTerrain;
        ReloaderListener* reloaderListener;
        csl::ut::StringMap<void*> unk13;
        csl::ut::MoveArray<void*> unk14;

        GAMESERVICE_CLASS_DECLARATION(TerrainManager)

        // wrong
        void ReloadTerrain();

        void Setup(const SetupInfo& setupInfo);

		virtual void* GetRuntimeTypeInfo() override;
        virtual bool ProcessMessage(hh::fnd::Message& message) override;
		virtual void OnAddedToGame() override;
		virtual void OnRemovedFromGame() override;
		virtual void GameServiceAddedCallback(hh::game::GameService* gameService) override;
		virtual void GameServiceRemovedCallback(hh::game::GameService* gameService) override;
		virtual void UpdateCallback(hh::game::GameManager* gameManager, const hh::game::GameStepInfo& gameStepInfo) override;
	};
}
