#pragma once

namespace app::player {
    class Amy {
    public:
        static constexpr size_t stateDescCount = 217;
        static const GOCPlayerHsm::StateDescRef stateDescs[stateDescCount];
    };
}
