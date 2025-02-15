#pragma once

namespace hh::needle {
    class SCIBL : public SceneContext {
    public:
        class Impl : public NeedleRefcountObject {
            SCIBL& sceneContext;
            uint64_t qword18;
            uint64_t probeBVH;
            RenderingDeviceContext* renderingDeviceContext;

        public:
            Impl(SCIBL& sceneContext);
        };

        intrusive_ptr<Impl> implementation;

        SCENECONTEXT_CLASS_DECLARATION(SCIBL);

        virtual void Initialize(const InitializeInfo& initializeInfo) override;
        virtual void UnkFunc1() override;
        virtual void UnkFunc2() override;
        virtual unsigned int GetNameHash() override;
        virtual const char* GetName() override;
    };
}
