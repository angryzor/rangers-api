#pragma once

namespace hh::needle {
    class RenderTargetManager : public NeedleObject {
    public:
        struct Unk1 {
            unsigned int unk1;
            bool unk2;
        };

        RenderingDeviceContext* renderingDeviceContext;
        RenderProperty* renderProperty;

        intrusive_ptr<RenderTarget> unk2[65];
        intrusive_ptr<Texture> unk3[65];
        intrusive_ptr<RenderTarget> unk4[24];
        intrusive_ptr<Texture> unk5[24];
        uint64_t pad1;
        uint64_t pad2;
        intrusive_ptr<RenderTarget> unk6[4];
        intrusive_ptr<Texture> unk7[4];
        Unk1 unk8[4];

        int unk9;
        csl::ut::StringMap<void*> unk10;
        unsigned int x;
        unsigned int y;
        unsigned int width;
        unsigned int height;
        uint8_t unk10a; // set in RenderManager::InitializeMainRenderTarget
        uint32_t unk11;
        uint32_t unk11a;
        uint32_t unk12;
        uint32_t unk12a;
        uint32_t unk13;
        uint32_t unk13a;
        uint32_t unk14;
        uint32_t unk14a;
        uint8_t unk15;

        RenderTargetManager(unsigned int x, unsigned int y, unsigned int width, unsigned int height, RenderProperty* renderProperty, csl::fnd::IAllocator* allocator);
        virtual ~RenderTargetManager();

        void Initialize(RenderingDevice* renderingDevice, RenderingDeviceContext* renderingDeviceContext, unsigned int x, unsigned int y, unsigned int width, unsigned int height);
    };
}
