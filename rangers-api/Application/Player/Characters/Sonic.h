#pragma once

namespace app::player {
    class Sonic {
    public:
        static constexpr size_t stateDescCount = 211;
        static const GOCPlayerHsm::StateDescRef stateDescs[stateDescCount];
    };
}
