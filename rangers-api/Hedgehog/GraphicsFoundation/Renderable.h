#pragma once

namespace hh::gfnd {
    class RenderableContainer;

    class RenderableParameter {
    public:
        char unk1[136];
        needle::RenderingDeviceContext* renderingContext;
    };

    class Renderable : public fnd::ReferencedObject {
    public:
        RenderableContainer* renderableContainer;
        csl::ut::LinkListNode renderableContainerNode;
        uint8_t preferredContainer;
        uint8_t priority;
        uint16_t unk5;
        const char* name;
        uint32_t unk6;
        uint64_t unk7;
        Renderable(csl::fnd::IAllocator* pAllocator);

        void SetUnk4(bool unkParam);
        void SetUnk5(uint16_t unkParam);

        virtual void Render(const RenderableParameter* renderableParameter) = 0;
        virtual void UnkFunc2() {}
        virtual bool UnkFunc3() { return true; }
    };
}
