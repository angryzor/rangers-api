#pragma once

namespace hh::gfx {
    class DynamicResolutionController : public fnd::ReferencedObject {
    public:
        struct DynamicResolutionSettings {
            float unk1;
            float unk2;
            float unk3;
            float unk4;
            float unk5;
            float unk6;
            float unk7;
            float unk8;
            float unk9;
            uint8_t unk10;
        };

        struct ResolutionInfo {
            float unk1;
            unsigned int viewportCount;
        };

    protected:
        DynamicResolutionSettings settings;
    public:
        DEFAULT_CREATE_FUNC(DynamicResolutionController);
        virtual void CalculateDynamicResolution(ResolutionInfo& resolutionInfo, gfnd::ViewportDimensions (&viewportDimensions)[4]) = 0;
        virtual void SetDynamicResolutionSettings(const DynamicResolutionSettings& settings);
        virtual float UnkFunc3() const = 0;
    };
}
