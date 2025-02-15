#pragma once

namespace hh::dv {
    class DiEventPreviewManager : public DiEventManager {
    public:
        virtual void* GetRuntimeTypeInfo() override;

        GAMESERVICE_CLASS_DECLARATION(DiEventPreviewManager)
    };
}
