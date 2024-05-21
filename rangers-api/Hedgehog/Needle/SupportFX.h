#pragma once

namespace hh::needle {
    class PBRModelInstanceRenderer;
    class CopyColor;
    class RenderUnit;
    class RenderTextureHandle;
    class RenderTextureCreateArgs;
    class SupportFX {
    public:
        struct FxViewport {
            FxCamera* camera;
            uint32_t x;
            uint32_t y;
            uint32_t width;
            uint32_t height;
            uint32_t prevRenderWidth;
            uint32_t prevRenderHeight;
            uint32_t renderWidth;
            uint32_t renderHeight;
            uint32_t unk7;
        };

        struct FxRenderParam {
            // uint8_t unk1[240];
            // uint32_t unk2;
            // uint32_t unk3;
            // uint32_t unk4;
            // uint32_t unk5;
            // uint32_t unk6;
            FxViewport viewports[5];
            uint32_t numViewports;
            uint32_t unk32;
            uint32_t unk33;
            uint32_t unk34;
            float unk35;
        };
    
        uint32_t unk1Count;
        void* unk1[128];
        void* unk1a[128];
        uint32_t unk2Count;
        void* unk2[128];
        void* unk2a[128];
        uint32_t unk3Count;
        void* unk3[128];
        void* unk3a[128];
        void* unk4[128];
        void* unk5[128];
        void* unk6[128];
        void* unk6a[5];
        RenderingDevice* renderingDevice;
        VertexShader* vertexShaders[3];
        PixelShader* pixelShaders[3];
        void* unk9[3];
        uint64_t unk10_0;
        uint64_t unk10_1;
        uint64_t unk10_2;
        PBRModelInstanceRenderer* modelInstanceRenderer;
        uint64_t unk10_4;
        uint64_t unk10_5;
        csl::ut::MoveArray<intrusive_ptr<SceneContextManager>> sceneContextManagers;
        float unk11;
        Texture* textures[13];
        uint64_t unk13_0;
        uint64_t unk13_1;
        CopyColor* copyColor1;
        CopyColor* copyColor2;
        uint64_t unk13_4;
        uint64_t unk13_5;
        csl::ut::MoveArray<void*> unk13_6;
        uint64_t unk13b[7];
        uint64_t unk14;
        uint64_t unk15;
        uint64_t unk15a;
        uint32_t unk16;
        uint32_t unk16a;
        uint32_t unk16b;
        uint8_t unk17;
        uint32_t unk18;
        uint32_t unk19;
        uint64_t unk20;
        uint64_t unkVtbl1;
        uint64_t unk21;
        uint64_t unk22;
        int32_t unk23;
        uint64_t unk24;
        RenderingDeviceContext* renderingDeviceContext1;
        RenderingDeviceContext* renderingDeviceContext2;
        uint64_t unk27;
        PrimitiveRenderer* primitiveRenderer;
        SupportFX* unkBackRef;
        uint32_t unk29;
        uint64_t unk30;
        uint32_t unk31;

        class CaptureIBLListener {
        public:
            virtual ~CaptureIBLListener() = default;
            virtual void CIL_UnkFunc1();
            virtual void CIL_UnkFunc2();
        };

        RenderingDevice* GetRenderingDevice() const;
        RenderingDeviceContext* GetRenderingContext() const;
        RenderingDeviceContext* GetRenderingContext2() const;
        SceneContextManager* GetSceneContextManager(const char* name) const;
        void AddSceneContextManager(SceneContextManager* sceneContextManager);

        static SupportFX* instance;

        SupportFX();
        virtual ~SupportFX();
        virtual uint64_t UnkFunc1() = 0;
        virtual bool UnkFunc2() { return true; }
        virtual bool UnkFunc3();
        virtual void UnkFunc4(float unkParam1, uint32_t numCameras, FxCamera** cameras);
    };

    class SupportFXAll : public SupportFX {
    public:
        uint64_t unk101;
        uint64_t unk102;
        uint64_t unk103;
        uint64_t unk104;
        uint64_t unk105;
        uint64_t unk106;
        uint8_t unk109;
        csl::ut::LinkList<RenderUnit> renderUnits;
        const char* mainSceneName;
        csl::ut::MoveArray<void*> unk112;
        uint32_t globalUserParams[4][4];
        NeedleRefcountObject* unk114[3];

        SupportFXAll();

        virtual uint64_t UnkFunc1() override;
        virtual bool UnkFunc2() override;
        virtual bool UnkFunc3() override;
        virtual void UnkFunc4(float unkParam1, uint32_t numCameras, FxCamera** cameras) override;

        RenderTextureHandle* CreateRenderTextureHandle(const RenderTextureCreateArgs& createArgs);
    };
}
