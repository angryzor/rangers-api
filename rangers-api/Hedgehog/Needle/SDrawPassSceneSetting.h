#pragma once

namespace hh::needle {
    struct SDrawPassSceneSetting {
        uint32_t pad1;
        uint32_t pad1a;
        uint64_t pad2;
        uint64_t pad3;
        uint32_t pad4;
        uint32_t someType; // see 0x1410D4AFF
        uint64_t pad5;
        uint64_t pad6;
    };
}
