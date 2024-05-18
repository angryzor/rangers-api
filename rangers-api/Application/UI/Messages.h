#pragma once

namespace app::ui {
    class MsgUIChangePlayerCharacter : public fnd::AppMessage<MsgUIChangePlayerCharacter> {
    public:
        player::CharacterIdU8 characterId;
        
        MsgUIChangePlayerCharacter(player::CharacterIdU8 characterId) : fnd::AppMessage<MsgUIChangePlayerCharacter>{ hh::fnd::MessageID::UI_CHANGE_PLAYER_CHARACTER }, characterId{ characterId } {}
    };
}
