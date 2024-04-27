#pragma once

namespace app::level {
    class PlayerInformation : public hh::fnd::BaseObject {
    public:
        hh::fnd::Handle<hh::fnd::Messenger> playerObject;
    };
}
