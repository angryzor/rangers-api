#pragma once

namespace app::player {
    class GOCPlayerBlackboard : public hh::game::GOComponent {
    public:
        hh::fnd::Reference<Blackboard> blackboard;

        GOCOMPONENT_CLASS_DECLARATION(GOCPlayerBlackboard)
    };
}
