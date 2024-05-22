#pragma once

namespace hh::needle::ImplDX11 {
    class SParameterBuffer : public NeedleRefcountObject {
    public:
        struct Unk1 {
            void* unk1;
            uint64_t unk2;

            Unk1();
        };

        struct SConstantContext {
            Unk1 unk1[14];
            uint64_t unk2[12544];
            uint32_t unk3;
            uint32_t unk4;
            uint32_t unk5;
            uint32_t unk6;
            uint32_t unk7;
            uint32_t unk8;
            uint32_t unk9;
            uint32_t unk10;
            uint64_t unk11;

            SConstantContext();
        };

        uint64_t unk1[1792];
        uint64_t unk2;
        uint32_t unk3;
        uint32_t unk4;
        SConstantContext vertexShaderConstantContexts;
        SConstantContext pixelShaderConstantContexts;
        SConstantContext computeShaderConstantContexts;

        SParameterBuffer();
    };
}
