#pragma once

namespace app::trr {
    class TerrainLoadListener {
    public:
        virtual void TLL_UnkFunc1(const char* name) {}
        virtual void TLL_UnkFunc2(void* unkParam1) {}
        virtual void TLL_UnkFunc3(void* unkParam1, uint32_t unkParam2) {}
    };
}
