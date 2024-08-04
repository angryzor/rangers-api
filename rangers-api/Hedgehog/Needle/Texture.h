#pragma once

#define NEEDLE_RESOURCE_TEXTURE 0x3045525554584554ui64 // '0ERUTXET'

namespace hh::needle {
    struct TextureCreationInfo {
    };

    struct TextureViewCreationInfo {
    };

    class Texture : public SurfaceBase {
        uint8_t unk101;
        void* view; // Copied ID3D11TextureView @ 0x155C55D2F
        void* unk103vftable; // streaming, see 0x155E91940
    public:
        static size_t constexpr resourceId = NEEDLE_RESOURCE_TEXTURE;
    };
}
