#pragma once

namespace hh::needle {
    struct SCullGroupSetting {
        uint32_t renderParametersUnk107Index;
        uint32_t flags; // 0x8 is on when it's an occlusion culling view i think
        uint64_t pad1[3];
    };
}
