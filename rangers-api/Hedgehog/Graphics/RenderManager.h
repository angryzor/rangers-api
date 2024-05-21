#pragma once

namespace hh::gfx {
    class RenderManager : public gfnd::RenderManagerBase {
    public:
        class Impl : public fnd::ReferencedObject {
        public:
            // Returns camera info based on viewportdata. id = viewport id
            class LocalFxCamera : public needle::FxCamera {
            public:
                Impl* renderManagerImplementation;
                uint32_t id;

                LocalFxCamera();

                virtual csl::math::Vector3 GetEyePos() const override;
                virtual void GetEyePosF(float* eyePos) const override;
                virtual csl::math::Vector3 GetLookAtPos() const override;
                virtual void GetLookAtPosF(float* lookAtPos) const override;
                virtual csl::math::Matrix44 GetViewMatrix() const override;
                virtual void GetViewMatrixF(float* viewMatrix) const override;
                virtual csl::math::Matrix44 GetProjectionMatrix() const override;
                virtual void GetProjectionMatrixF(float* projectionMatrix) const override;
                virtual void GetClipPlanes(float* near, float* far) const override;
            };
            needle::SupportFX::FxViewport viewports[4];
            LocalFxCamera fxCameras[4];
            uint64_t unk2;
            uint32_t numMainViewports;
            uint32_t unk3;
            float unk4;
            float unk5;
            uint32_t unk6;
            needle::SupportFX::FxRenderParam renderParam;
            uint32_t maybeSupportFXWidth;
            uint32_t maybeSupportFXHeight;
            uint64_t unk12;
            uint64_t unk13;
            float unk14;
            uint64_t unk15;
            uint32_t width;
            uint32_t height;
            uint32_t maybeRenderWidth;
            uint32_t maybeRenderHeight;
            uint64_t unk18;
            uint64_t unk19;
            uint64_t unk20;
            uint64_t unk21;
            uint8_t unk22;
            RenderingEngineNeedle* renderingEngine;
            uint64_t unk24;
            csl::math::Vector4 unk25;
            RenderManager* renderManager;
            uint64_t unk26;
            fnd::Reference<fnd::ResourceLoader> resourceLoader;
            uint8_t unk28;
            csl::ut::MoveArray<void*> unk29;
            uint8_t unk30[128];
            bool unk31;

            static Impl* Create(csl::fnd::IAllocator* allocator);
            Impl(csl::fnd::IAllocator* allocator, RenderManager* renderManager);
        };

        Impl* implementation;

        struct SModelCreationInfo {
            // Check GOCVisualModelImpl::Setup
            fnd::ManagedResource* unk325; // suspected
            fnd::ManagedResource* unk326; // suspected
            fnd::ManagedResource* unk327; // suspected
            void* unk1;
        };

        static RenderManager* instance;

        static RenderManager* Create(csl::fnd::IAllocator* allocator);

        RenderManager(csl::fnd::IAllocator* allocator);

        virtual uint64_t UnkFunc1() override;
        virtual uint64_t UnkFunc2() override;
        virtual uint64_t UnkFunc3() override;
        virtual void UnkFunc4() override;
        virtual uint64_t UnkFunc5() override;

        void CreateModelFromResource2(needle::Model** model, const SModelCreationInfo& modelCreationInfo);
        needle::ModelInstance* CreateModelInstance(needle::Model* model, const SModelCreationInfo& modelCreationInfo) const;
        gfx::RenderingEngineNeedle* GetNeedleResourceDevice();
    };
}
