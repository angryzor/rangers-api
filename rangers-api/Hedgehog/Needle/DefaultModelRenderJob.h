#pragma once

namespace hh::needle {
    class PipelineInfo;
    class DefaultModelRenderJob : public ModelRenderJobBase {
    public:
        const char* name;
        uint8_t unk201;
        RenderJobCallback onBeforeDefaultRender;
        RenderJobCallback onBeforeRender;
        RenderJobCallback onAfterRender;
        uint32_t unk208;
        uint8_t unk209;

        DefaultModelRenderJob(unsigned int viewportId, const char* name);
        virtual unsigned int UnkFunc6() override;
        virtual void UnkFunc7(void* unkParam) override;
        virtual void Render(PipelineInfo* pipelineInfo) override;
        virtual unsigned int GetNameHash() override;
        virtual const char* GetName() override;
        virtual unsigned int UnkFunc16() override;
        virtual unsigned int UnkFunc17() override;
    };
}
