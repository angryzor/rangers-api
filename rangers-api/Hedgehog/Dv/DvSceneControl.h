#pragma once

#define DV_NODE_DECLARATION_BASE(ClassName)\
		ClassName(csl::fnd::IAllocator* allocator);

namespace hh::dv {
    class DiEventManager;

    class DvSceneControl : public game::GameObject, game::GameStepListener, game::ObjectUpdateListener{
    public:
        DiEventManager* diEvtMgr;
        csl::ut::MoveArray<DvSceneControlListener*> listeners;
        DvSceneNodeTree* nodeTree;
        DvSceneTimeline* timeline;
        ut::TinyFsm<DvSceneControl, ut::TinyFsmEvent> fsm;
        csl::ut::VariableString cutsceneName;
        int64_t unk2;
        int64_t state;
        ResDvScene* resource;
        int32_t unk6;
        float speed;
        int32_t unk7;
        int32_t unk9;

        virtual bool ProcessMessage(hh::fnd::Message& message) override;
		virtual void AddCallback(hh::game::GameManager* gameManager) override;
		virtual void RemoveCallback(hh::game::GameManager* gameManager) override;
        virtual void PreStepCallback(hh::game::GameManager* gameManager, const game::GameStepInfo& gameStepInfo) override;
		virtual void PostStepCallback(hh::game::GameManager* gameManager, const game::GameStepInfo& gameStepInfo) override;
        virtual void PreObjectUpdateCallback(game::GameManager* gameManager, fnd::UpdatingPhase phase, const fnd::SUpdateInfo& updateInfo) override;

        const char* GetCutsceneName();

        GAMEOBJECT_CLASS_DECLARATION(DvSceneControl)
    };
}
