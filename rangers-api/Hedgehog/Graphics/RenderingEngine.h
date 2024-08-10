#pragma once

namespace hh::gfx {
    class RenderingEngine : public fnd::ReferencedObject {
        csl::ut::MoveArray<RenderingComponent*> components;
        bool callUnkFunc1OnNewComponents;
    public:
        RenderingEngine(csl::fnd::IAllocator* allocator);
        virtual unsigned int GetModelGatherBufferSize();
        virtual bool Setup(const gfnd::RenderManagerBase::SetupInfo& setupInfo) = 0;
        virtual void UnkFunc2() = 0;
        virtual bool Render(const needle::SupportFX::FxRenderParam& renderParam) = 0;
        virtual uint64_t UnkFunc4() = 0;
        virtual ID3D11Device* GetNativeDevice() = 0;
        virtual uint64_t Startup() = 0;
        virtual uint64_t Shutdown() = 0;
        virtual uint64_t UnkFunc8();
    };
}
