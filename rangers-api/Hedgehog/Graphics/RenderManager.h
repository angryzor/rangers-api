#pragma once

namespace hh::gfx {
    class RenderManager : public gfnd::RenderManagerBase {
        class Impl : public fnd::ReferencedObject {
            class LocalFxCamera : public needle::FxCamera {
                uint64_t vtbl1;
                uint64_t unk1;
                uint32_t unk2;
            // public:
            //     virtual int64_t UnkFunc1() override;
            //     virtual int64_t UnkFunc2() override;
            //     virtual int64_t UnkFunc3() override;
            //     virtual int64_t UnkFunc4() override;
            //     virtual int64_t UnkFunc5() override;
            //     virtual int64_t UnkFunc6() override;
            //     virtual int64_t UnkFunc7() override;
            //     virtual int64_t UnkFunc8() override;
            //     virtual int64_t UnkFunc9() override;
            //     virtual int64_t UnkFunc10() override;
            };
            void* unk1[24];
            LocalFxCamera fxCameras[4];
            uint64_t unk2;
            uint64_t unk3;
            float unk4;
            float unk5;
            uint32_t unk6;
            void* unk7[30];
            uint32_t unk8;
            uint64_t unk9;
            uint64_t unk10;
            uint64_t unk11;
            uint64_t unk12;
            uint64_t unk13;
            float unk14;
            uint64_t unk15;
            uint64_t unk16;
            uint64_t unk17;
            uint64_t unk18;
            uint64_t unk19;
            uint64_t unk20;
            uint64_t unk21;
            uint8_t unk22;
            RenderingEngine* renderingEngine;
            uint64_t unk24;
            csl::math::Vector4 unk25;
            RenderManager* renderManager;
            uint64_t unk26;
            fnd::ResourceLoader resourceLoader;
            uint8_t unk28;
            csl::ut::MoveArray<void*> unk29;
            uint8_t unk30[128];
            bool unk31;

        public:
            static Impl* Create(csl::fnd::IAllocator* allocator);
            Impl(csl::fnd::IAllocator* allocator, RenderManager* renderManager);
        };

        Impl* implementation;

    public:
        struct SModelCreationInfo {
            // Check GOCVisualModelImpl::Setup
            fnd::ManagedResource* unk325; // suspected
            fnd::ManagedResource* unk326; // suspected
            fnd::ManagedResource* unk327; // suspected
            void* unk1;
        };

    public:
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
