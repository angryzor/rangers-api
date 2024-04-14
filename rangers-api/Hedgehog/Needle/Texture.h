#pragma once

#define NEEDLE_RESOURCE_TEXTURE 0x3045525554584554ui64 // '0ERUTXET'

namespace hh::needle {
    class Texture : public SurfaceBase {
        uint8_t unk101;
        void* unk102;
        void* unk103vftable;
    public:
        static size_t constexpr resourceId = NEEDLE_RESOURCE_TEXTURE;
    };
}
