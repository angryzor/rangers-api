#pragma once

namespace hh::gfx {
    class DefaultDynamicResolutionController : public DynamicResolutionController {
    public:
        uint8_t unk101;
        uint8_t unk101a;
        uint32_t pad101;
        float unk102; 
 
        DEFAULT_CREATE_FUNC(DefaultDynamicResolutionController);
        virtual void CalculateDynamicResolution(ResolutionInfo& resolutionInfo, gfnd::ViewportDimensions (&viewportDimensions)[4]) override;
        virtual float UnkFunc3() const override;

        void CalculateDynamicResolution(ResolutionInfo& resolutionInfo, gfnd::ViewportDimensions (&viewportDimensions)[4], float unkParam, bool unkParam2);
    };
}
