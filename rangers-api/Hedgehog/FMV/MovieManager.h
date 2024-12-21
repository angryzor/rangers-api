#pragma once

namespace hh::fmv{
    class MovieManager : public game::GameService, game::GameStepListener{
    public:
        csl::ut::MoveArray<void*> unkArray;
        csl::ut::MoveArray<char> amountOfMoviesPlayed; // it seems to always have one item that adds +1 whenever a movie starts playing (why)
        csl::ut::MoveArray<char> randomAssString;
    };
}
