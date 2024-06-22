#pragma once

namespace app::ui {
    class RequestOverlayBegin : public hh::fnd::ReferencedObject {
    public:
        uint32_t unk1;
        uint8_t unk2;
        uint8_t unk3;
        OverlayTextVariableCollection textVariables;

        RequestOverlayBegin(csl::fnd::IAllocator* allocator);
    };
}
