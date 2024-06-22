#pragma once

namespace app::ui {
    class RequestOverlayCaption : public RequestOverlayBegin {
    public:
        csl::ut::MoveArray<void*> unk201;
        uint8_t unk202;
        uint8_t unk203;
        uint8_t unk204;
        uint8_t unk205;
        uint8_t unk206;
        uint8_t unk207;
        uint8_t unk208;
        uint8_t unk209;
        uint8_t unk210;
        uint8_t unk211;

        DEFAULT_CREATE_FUNC(RequestOverlayCaption);
        void Setup(const char* line1, const char* line2, float time);
    };
}
