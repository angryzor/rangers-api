#pragma once

namespace app {
    class ObjSwitchVolume
        : public hh::game::GameObject
        , public app::VolumeListener
        , public app::game::GOCEventListener {
        app::rfl::ObjSwitchVolumeSpawner::Condition condition;
        app::VolumeTrigger volumeTrigger;
    public:
        virtual void* GetRuntimeTypeInfo() override;
		virtual bool ProcessMessage(hh::fnd::Message& message) override;
		virtual void AddCallback(hh::game::GameManager* gameManager) override;
        virtual void EventCallback(unsigned int event) override;

        GAMEOBJECT_CLASS_DECLARATION(ObjSwitchVolume)
    };
}
