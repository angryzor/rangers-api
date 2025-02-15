#pragma once

namespace app::dv{
    class DvElementBossName : public AppDvElementBase{
    public:
        struct Data {
        public:
            enum class BossID : unsigned int {
                GIANT,
                DRAGON,
                KNIGHT,
                RIFLE,
                THEEND,
                RIFLEBEAST
            };

            int unk0;
            BossID bossId;
        };

        hh::fnd::Reference<hh::game::GameObject> uiBossNameObject;

        virtual bool UnkFunc1() override;

        APP_DV_ELEMENT_DECLARATION_BASE(DvElementBossName)
    };
}