#pragma once

namespace app::game {
    class IslandRangeSpawningManager
        : public hh::game::ObjectWorldExtension
        , public hh::game::ObjectWorldListener
        , public hh::game::ObjectWorldChunkListener
        , public hh::game::GameStepListener
    {
        uint64_t unk1;
        csl::ut::MoveArray<void*> unk2;
        uint8_t unk3;
    }
}