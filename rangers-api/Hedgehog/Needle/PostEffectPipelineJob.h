#pragma once

namespace hh::needle {
    class RenderingPipeline;
    class PostEffectPipelineJob : public RenderJob {
    public:
        csl::ut::MoveArray<void*> effects;
        RenderingPipeline* postEffectPipeline;

        PostEffectPipelineJob();
        virtual unsigned int UnkFunc6() override;
        virtual void UnkFunc7(void* unkParam) override;
        virtual void UnkFunc8() override;
        virtual void UnkFunc9() override;
        virtual void Render(PipelineInfo* pipelineInfo) override;
        virtual unsigned int GetNameHash() override;
        virtual const char* GetName() override;
        virtual unsigned int UnkFunc16() override;
        virtual void SetupPipeline();
    };
}
