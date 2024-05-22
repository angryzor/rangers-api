#pragma once

namespace hh::needle::ImplDX11 {
    class DeviceObjectDX11;
    class RenderingDeviceContextDX11;
    class RenderingDeviceDispatchDX11Impl : public NeedleRefcountObject {
    public:
        struct Unk1 {
            uint64_t unk1;
            int unk2;
            uint32_t unk3;
        };
        struct Unk3 {
            uint64_t unk1[2][7];
            uint32_t count;
        };
        struct Unk5 {
            uint64_t unk1;
            uint64_t unk2;

            Unk5();
        };
        struct Unk4 {
            int unk1;
            char unk2[60];
            RsFlagMask rsFlagMask;
            uint64_t unk4;
            uint64_t unk5;
            uint64_t unk6;
            uint64_t unk7;
            uint32_t unk8;
            uint32_t unk9;
            int64_t unk10;
            uint64_t unk11;
            uint32_t unk12;
            int unk13;
            uint32_t unk14;
            int unk15;
            int unk16;
            uint32_t unk17;
            uint32_t unk18;
            uint32_t unk19;
            int unk20;
            int unk21;

            Unk4();
        };
        struct Unk2 {
            DeviceObjectDX11* deviceObject;
            SParameterBuffer* parameterBuffer;
            uint64_t unk1;
            uint64_t unk2[49];
            uint64_t unk2a[132];
            DeviceObjectDX11* deviceObject2;
            uint64_t unk2b;
            uint64_t unk2c[38];
            Unk4 unk3;
            uint32_t qword7AC;
            uint32_t qword7B0;
            Unk3 qword7B8;
            uint64_t unk4;
            uint64_t unk5;
            uint64_t unk6;
            uint64_t unk7;
            void* unk8;
            void* unk9;
            uint64_t qword860[10];
            uint64_t qword8B0[24];
            uint32_t qword970;
            uint32_t qword974[32];
            uint32_t qword9F4;

            Unk2();

            void Setup();
            void InvalidateStatus();
        };

        ID3D11DeviceContext* deviceContext;
        Unk1 unk1;
        uint64_t* unk28;
        Unk2 unk2;
        uint64_t qword738;
        uint64_t qword740;
        uint64_t qword748;
        uint64_t qword750;
        uint64_t qword758;
        uint64_t qword760;
        uint64_t qword768;
        char gap770[276];
        UINT vertexCount; 
        char gap770a[792];
        uint64_t qwordBA0;
        uint32_t dwordBA8;
    };
}
