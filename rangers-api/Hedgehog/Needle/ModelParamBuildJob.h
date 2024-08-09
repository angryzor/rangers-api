#pragma once

namespace hh::needle {
    class ModelParamBuildJob : public ParamBuildJob {
    public:
        ModelRenderJobBase* modelRenderJob;
        virtual void Run() override {}
        virtual void OnSetEnable(bool enabled) override;
    };
}
