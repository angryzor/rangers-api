#pragma once

namespace app::gfx {
    class SceneParameterListener;

    class SceneParameters : public hh::fnd::ReferencedObject, public hh::gfx::FxParamEditorListener {
    public:
        app::rfl::NeedleFxSceneData* sceneData;
        csl::ut::MoveArray<SceneParameterListener*> listeners;
        csl::ut::MoveArray<void*> unk2;
        uint64_t unk3;
        csl::ut::VariableString unk4;
        uint8_t unk5;
        uint32_t unk6;
        SceneParameters(csl::fnd::IAllocator* allocator);
        virtual void FPE_OnSetParam(const hh::gfx::FxParamEditInfo& editInfo) override;
        virtual void FPE_OnSetParam2(const hh::gfx::FxParamEditInfo& editInfo) override;
        virtual void FPE_OnInterpolate(const hh::gfx::FxParamEditInfo& editInfo) override;
        app::rfl::NeedleFxSceneData* GetSceneData();
    };
}