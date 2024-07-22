#pragma once

namespace app::player {
    class VisualAmy : public VisualHuman {
    public:
        uint64_t unk201;

        virtual unsigned int GetNameHash() const override;
        virtual uint64_t UnkFunc2() override;
        virtual uint64_t UnkFunc6() override;
        virtual uint64_t UnkFunc10() override;
        virtual uint64_t UnkFunc11() override;

        PLAYER_VISUAL_CLASS_DECLARATION(VisualAmy);
    };
}
