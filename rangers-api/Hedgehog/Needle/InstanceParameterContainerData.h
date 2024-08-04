#pragma once

namespace hh::needle {
    class InstanceParameterContainerData {
    public:
        CNameIDObject*** names;
        void* unk2;
        uint32_t* counts;
    };
}
