#pragma once

namespace hh::needle {
    struct RenderTargetsSetting {
        DepthStencil* depthStencil;
        RenderTarget* renderTargets[8];
        uint32_t renderTargetCount;
    };
}
