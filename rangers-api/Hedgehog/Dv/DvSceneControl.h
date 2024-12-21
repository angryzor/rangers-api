#pragma once

#define DV_NODE_DECLARATION_BASE(ClassName)\
		ClassName(csl::fnd::IAllocator* allocator);

namespace hh::dv {
    class DvSceneControl : public game::GameObject, game::GameStepListener, game::ObjectUpdateListener{
    public:
        csl::ut::MoveArray<DvSceneControlListener*> listeners;
        DvSceneNodeTree* nodeTree;
        DvSceneTimeline* timeline;
        ut::TinyFsm<DvSceneControl, ut::TinyFsmEvent> fsm;
        csl::ut::VariableString cutsceneName;
        int32_t unk2;
        int32_t state;
        ResDvScene* resource;
        int32_t unk6;
        float speed;
        int32_t unk7;
        int32_t unk9;

        virtual bool ProcessMessage(hh::fnd::Message& message) override;
		virtual void AddCallback(hh::game::GameManager* gameManager) override;

        GAMEOBJECT_CLASS_DECLARATION(DvSceneControl)
    };
}
