#pragma once

namespace app::player {
    class Tails {
    public:
        static constexpr size_t stateDescCount = 206;
        static const GOCPlayerHsm::StateDescRef stateDescs[stateDescCount];
    };
}
