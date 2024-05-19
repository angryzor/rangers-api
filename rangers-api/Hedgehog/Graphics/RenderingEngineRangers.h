#pragma once

namespace hh::gfx {
    class RenderingEngineRangers : public RenderingEngineNeedle {
    public:
        needle::SupportFXAll supportFX;
        needle::RenderUnit* mainRenderUnit;
        needle::RenderingPipelineRangers* mainRenderingPipeline;
        uint64_t unk203;

        RenderingEngineRangers(csl::fnd::IAllocator* allocator);
        
        virtual uint64_t Startup() override;
        virtual void SetFXParameter(app::rfl::NeedleFxParameter* parameter, unsigned int unkParam1) override;
        virtual void GetFXParameter(app::rfl::NeedleFxParameter* parameter) override;
        virtual void SetSceneConfig(app::rfl::NeedleFxSceneConfig* sceneConfig) override;
        virtual void GetSceneConfig(app::rfl::NeedleFxSceneConfig* sceneConfig) override;
        virtual uint64_t CreateRenderTextureHandle(const needle::RenderTextureCreateArgs& createArgs, csl::fnd::IAllocator* allocator) override;
        virtual void AddRenderableToRenderTextureHandle(needle::RenderTextureHandle* handle, gfnd::Renderable* renderable) override;
        virtual void UnkFunc19() override;
        virtual unsigned int UnkFunc23() override;
        virtual void SetupMainRenderUnit() override;
    };
}
