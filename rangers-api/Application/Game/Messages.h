#pragma once

namespace app::game {
    class MsgNotifyLevelStatus : public hh::fnd::Message {
    public:
        uint32_t status;
        uint16_t unk1;
        uint8_t unk2;
    };
}