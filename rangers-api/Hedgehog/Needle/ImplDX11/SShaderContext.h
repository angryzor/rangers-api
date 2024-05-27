#pragma once

namespace hh::needle::ImplDX11 {
    struct SShaderOptionsDeclaration {
        CNameIDObject** optionNames;
        uint16_t numOptions;
        uint16_t unk;
        uint16_t optionsBits;
    };

    // Not a cache, created in UnkFunc27 or something on the device (context?)
    struct SShaderCache {
        void* shaderVtable; // see shader_vtable
        uint32_t unk1;
        uint32_t unk2;
        char filename[256];
        void** parameterDeclarations;
        uint64_t unk0a;
        uint32_t* cachedShaderOffsetToParameterDeclarationMap;
        ShaderPtr* cachedShaders;
        SShaderOptionsDeclaration optionsDeclaration;
        uint16_t* optionHashToCachedShaderOffsetMap;
    };

    struct Unk10 {
        uint8_t itemCount;
        uint32_t items[1];
    };

    struct Unk11 {
        uint32_t itemCount;

        // lower byte = constant buffer index, upper 16 bits: index into something else
        uint32_t items[1];
    };

    struct Unk14 {
        void* unk1[4];
        uint32_t* unk2;
    };

    struct Unk15 {
        uint16_t unk1;
        uint16_t unk2;
        uint16_t unk3;
    };

    struct Unk13 {
        uint16_t flags;
        uint16_t somethingSize;
        uint16_t unk3;
        uint16_t start;
        uint16_t end;
        uint16_t unk6;
        uint16_t unk7;
        uint16_t unk8;
        uint16_t unk9;
        uint16_t unk10;
        Unk15 unk11[1];
    };

    struct Unk12 {
        uint64_t unk1;
        uint64_t unk2;
        Unk13* unk3;
    };

    struct SShaderConfig {
        SShaderCache* shaderCache;
        uint16_t optionsIncludedInHashBits;
        uint16_t shaderEnabledOptionsBits;
        Unk10* unk1;
        uint16_t* optionsHashToUnk3OffsetMap;
        uint32_t* unk3;

        unsigned short CalculateCacheHash(uint16_t enabledOptionsBits);
    };

    struct SEffect {
        uint64_t unk1;
        uint64_t unk2;
        uint64_t unk3;
        SShaderConfig* shaderConfigurations[3];
        csl::ut::Bitset<ShaderStage> enabledShaderStagesFlags;
        uint64_t unk8;
        uint64_t unk9;
    };

    struct SEffectRepository {
        uint64_t unk1[5];
        Unk12* unk3;
        uint64_t unk1a[4];
        SEffect* effects;
    };

    struct SShaderContext {
        SEffectRepository* unk1;
        uint64_t unk2a[4];
        uint64_t unk2c;
        uint64_t unk2b[7];
        uint8_t currentEffect;
    };
}