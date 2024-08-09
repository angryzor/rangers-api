#pragma once

namespace hh::needle {
    class SyncDrawContext : public NeedleRefcountObject {
    public:
        RenderingDeviceContext* deviceContext;
        uint64_t unk2;
        uint64_t unk3;
        uint16_t unk4;
        uint64_t unk5;

        SyncDrawContext();
    };
}
