#pragma once

namespace app::player {
    class Knuckles {
    public:
        static constexpr size_t stateDescCount = 216;
        static const GOCPlayerHsm::StateDescRef stateDescs[stateDescCount];
    };
}
