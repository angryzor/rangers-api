#pragma once

namespace hh::needle {
    class RenderManager : public NeedleRefcountObject {
    public:
        RenderingDeviceContext* renderingDeviceContext;
        RenderTargetManager* renderTargetManager;
        RenderProperty* renderProperty;
        uint64_t unk3;
        intrusive_ptr<NeedleResContainer> resourceContainer;
        float worldScale;

        RenderManager(unsigned int x, unsigned int y, unsigned int width, unsigned int height, csl::fnd::IAllocator* allocator);

        void Initialize(RenderingDevice* renderingDevice, RenderingDeviceContext* renderingDeviceContext);
        void InitializeMainRenderTarget(RenderingDevice* renderingDevice, unsigned int x, unsigned int y, unsigned int width, unsigned int height);
    };
}
