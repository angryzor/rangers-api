#pragma once

namespace hh::needle {
    template<typename T>
    struct NeedleType {
        static CNameIDObjectStatic ID;

        uint64_t unk1;
        uint8_t unk2;
        T data;
    };
}
