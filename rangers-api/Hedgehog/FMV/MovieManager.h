#pragma once

namespace hh::fmv{
    class MovieManager : public game::GameService, game::GameStepListener{
    public:
        csl::ut::MoveArray<void*> unkArray;
        csl::ut::MoveArray<char> amountOfMoviesPlayed; // it seems to always have one item that adds +1 whenever a movie starts playing (why)
        csl::ut::MoveArray<char> randomString;
        int64_t qwordB8;
        bool paused;

        virtual void* GetRuntimeTypeInfo() override;
		virtual void OnAddedToGame() override;
		virtual void OnRemovedFromGame() override;

        GAMESERVICE_CLASS_DECLARATION(MovieManager)
    };
}
