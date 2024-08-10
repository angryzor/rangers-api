#pragma once

namespace hh::needle {
    class SyncDrawContext : public NeedleRefcountObject {
    public:
        RenderingDeviceContext* deviceContext;
        uint64_t unk2;
        intrusive_ptr<RenderingCommandList> commandList;
        bool isRendering;
        bool finished;
        SyncDrawContext* next;

        SyncDrawContext();
    };
}
