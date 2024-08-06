#pragma once

namespace hh::needle {
    struct GatherRenderingPassContext_ModelContainer {
        void* data;
        void* otherData;
        uint32_t otherDataCount; // context unk2
    };

    struct GatherRenderingPassContextImpl {
        class CResourceParseContextHolder {
            struct Unk1 {
                SGlobalParameterSceneSetting globalParameterSceneSetting;
                uint64_t unk1;
                uint64_t unk2;
                uint64_t unk3;
            };

            struct Unk2 {
                uint8_t unk1;
                uint8_t unk1a;
                uint16_t unk1b;
                uint32_t unk2;
                uint32_t unk3;
                uint32_t unk4;
            };

            struct Unk3 {
                uint64_t unk1;
                uint32_t unk2;
                uint32_t unk3[32];
                uint64_t unk4[32];
            };

            CScratchMemoryContext memCtx;
            CScratchMemoryContext memCtxs1[32];
            CScratchMemoryContext memCtxs2[32];
            void* unk1;
            Unk1 globalParameterSceneSettings[64];
            uint32_t unk2;
            uint8_t pad2[772];
            SCullGroupSetting cullGroupSettings[42];
            uint64_t pad2a;
            // uint8_t pad2[2124];
            uint32_t unk3;
            uint32_t unk3a;
            uint32_t unk3b;
            float lodLayerRanges[32]; 
            uint32_t unk3c;
            SDrawPassSceneSetting drawPassSettings[64];
            unsigned int drawPassSettingIndices[64];
            uint8_t pad3b[128];
            uint8_t pad3[128];
            uint32_t drawPassSettingCount;
            uint32_t unk4;
            Unk3 unk4a;
            uint32_t unk5;
            Unk2 unk5b[64];
            uint8_t unk5c[64];
            uint8_t pad5[292124];
            void** unk5a; // unk5 pointers to memory of size 144 x unk4
            uint8_t pad6[6];
            uint8_t unk6;
            uint32_t unk7;
            uint8_t pad7[36];
            void* unk8; // 256 bytes long
            uint32_t unk9;
            uint8_t pad[20];
        };
        CResourceParseContextHolder resourceParseContextHolder;
        uint64_t unk1;
        uint32_t unk2;
        uint32_t unk2a;
        GatherRenderingPassContext_ModelContainer modelContainer;
        uint8_t pad2[1060];
        uint8_t unk3;
        bool unk3a;
        float unk4;

        void SetupInitialize(RenderingDevice* renderingDevice, unsigned int totalGlobalParameterSize, unsigned int unkParam1, unsigned int unkParam2, unsigned int unkParam3, unsigned char unkParam4, unsigned int unkParam5);
        void SetCullingGroupSetting(unsigned int index, const SCullGroupSetting& cullingGroupSetting);
        void SetDrawPassGroupSetting(unsigned int index, const SDrawPassSceneSetting& drawPassGroupSetting);
        void SetGlobalParameter(unsigned int index, const SGlobalParameterSceneSetting& globalParameterSceneSetting);
        void SetLODLayerRanges(const float* ranges);
        void* GetParameterBuffer(size_t size);
        float* GetParameterFloatVector(size_t count, const float* vec);
    };

    struct GatherRenderingPassContext {
        GatherRenderingPassContextImpl* implementation;
        CScratchMemoryContext memCtx;
        uint32_t unk2;
        int unk3[128];

        virtual ~GatherRenderingPassContext();

        GatherRenderingPassContext(unsigned int unk2Param);
        void SetupInitialize(RenderingDevice* renderingDevice, unsigned int totalGlobalParameterSize, unsigned int unkParam1, unsigned int unkParam2, unsigned int unkParam3, unsigned char unkParam4, unsigned int unkParam5);
        void SetCullingGroupSetting(unsigned int index, const SCullGroupSetting& cullingGroupSetting);
        void SetDrawPassGroupSetting(unsigned int index, const SDrawPassSceneSetting& drawPassGroupSetting);
        void SetGlobalParameter(unsigned int index, const SGlobalParameterSceneSetting& globalParameterSceneSetting);
        void SetLODLayerRanges(const float* ranges);
        void* GetParameterBuffer(size_t size);
        float* GetParameterFloatVector(size_t count, const float* vec);
    };
}
