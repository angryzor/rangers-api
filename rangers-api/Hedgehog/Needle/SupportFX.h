#pragma once

namespace hh::needle {
    class PBRModelInstanceRenderer;
    class CopyColor;
    class SupportFX {
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
        csl::ut::MoveArray<void*> unk10_6;
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
        uint64_t unk25;
        RenderingDeviceContext* renderingDeviceContext;
        uint64_t unk27;
        PrimitiveRenderer* primitiveRenderer;
        SupportFX* unkBackRef;
        uint32_t unk29;
        uint64_t unk30;
        uint32_t unk31;

    public:
        class CaptureIBLListener {
        public:
            virtual ~CaptureIBLListener() = default;
            virtual void CIL_UnkFunc1();
            virtual void CIL_UnkFunc2();
        };

        RenderingDevice* GetRenderingDevice() const;
        RenderingDeviceContext* GetRenderingContext() const;

        static SupportFX* instance;

        SupportFX();
        virtual ~SupportFX();
    };
    class SupportFXAll : public SupportFX {};
}
