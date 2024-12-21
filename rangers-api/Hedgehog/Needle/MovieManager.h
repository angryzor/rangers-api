#pragma once

namespace hh::needle {
    class MovieManager : public hh::game::GameService{
    public:
        uint64_t qword70;
        csl::ut::MoveArray<hh::game::InputComponent*> csl__ut__movearray_hh__game__inputcomponent__78;
        csl::ut::MoveArray<uint16_t> qword98; // [0] amount of played movies in total?
        csl::ut::MoveArray<void*> qwordB8;
        uint64_t qwordB8Buffer;
        bool paused;

        virtual void* GetRuntimeTypeInfo() override;
		virtual void OnAddedToGame() override;
		virtual void OnRemovedFromGame() override;

        GAMESERVICE_CLASS_DECLARATION(MovieManager)
    };
}