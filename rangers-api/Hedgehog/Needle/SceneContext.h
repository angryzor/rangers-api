#pragma once

namespace hh::needle {
    class SupportFXAll;
    class SceneContextManager;
    class SceneContext : public NeedleRefcountObject {
    public:
        struct InitializeInfo {
            RenderingDevice* renderingDevice;
            csl::fnd::IAllocator* allocator;
            SupportFXAll* supportFX;
        };

        uint32_t unk1;
        SceneContextManager* sceneContextManager;

        virtual uint64_t Initialize(const InitializeInfo& initializeInfo) = 0;
        virtual uint64_t UnkFunc1() = 0;
        virtual void UnkFunc2() {}
        virtual void UnkFunc3() {}
        virtual void UnkFunc4() {}
        virtual uint64_t UnkFunc5() = 0;
        virtual uint64_t UnkFunc6() = 0;
    };
}
