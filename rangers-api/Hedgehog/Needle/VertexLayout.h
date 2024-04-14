#pragma once

#define NEEDLE_RESOURCE_VERTEX_LAYOUT 0x304F59414C585456ui64 // '0OYALXTV'

namespace hh::needle {
    struct SInputElement {
        uint8_t unk1;
        
    };

    class VertexLayout : public TNeedleRefcountUniqueObjectBase<NeedleRefcountResource> {
        uint64_t unk101;
        uint64_t unk102;
        uint64_t unk103;
    public:
        static size_t constexpr resourceId = NEEDLE_RESOURCE_VERTEX_LAYOUT;

        virtual uint64_t GetInputElementCount() const = 0;
        virtual uint64_t GetInputElement() const = 0;
    };
}
