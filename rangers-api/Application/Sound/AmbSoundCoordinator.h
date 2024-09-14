#pragma once

namespace app::snd {
    class AmbSoundCoordinator : public hh::game::GameObject {
    public:
        uint64_t unk1;
        csl::ut::MoveArray<hh::fnd::Handle<hh::game::GameObject>> emitters;
        uint64_t unk3;
        csl::math::Matrix34 unk4;
        uint64_t unk5;
        uint64_t unk6;

		virtual void AddCallback(hh::game::GameManager* gameManager) override;
		virtual void UnkFunc11(uint64_t a1, uint64_t a2, uint64_t a3, uint64_t a4) override;

        GAMEOBJECT_CLASS_DECLARATION(AmbSoundCoordinator);
    };
}