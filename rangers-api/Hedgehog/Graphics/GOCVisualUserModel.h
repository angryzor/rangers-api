#pragma once

namespace hh::gfx {
    class GOCVisualUserModel : public GOCVisualTransformed {
    public:
        struct Unk1 {
            uint32_t unk1;
            uint32_t unk2;
            uint32_t unk3;
            uint32_t unk4;
            uint32_t unk5;

            char pad[0x1F80];
        };

        struct SetupInfo : GOCVisualTransformed::SetupInfo {
            struct Unk1 {
                uint64_t qword0;
                uint32_t dword8;
                uint64_t qword10;
                uint64_t qword18;
                uint32_t dword20;
                uint32_t qword24;
                uint32_t qword28;
                uint32_t dword2C;
                needle::CNameIDObject* renderingTypeOrSomething;
                uint64_t qword38;
                uint64_t qword40;
                uint64_t qword48;
                uint64_t qword50;

                Unk1();
            };

            uint32_t dword10;
            uint32_t dword14;
            uint32_t dword18;
            uint32_t dword1C;
            uint32_t dword20;
            uint64_t qword28;
            uint64_t qword30;
            uint64_t qword38;
            uint64_t qword40;
            uint64_t qword48;
            Unk1 unk1;
            needle::UserModelShaderParamter shaderParameter;
            uint8_t byteD0;
            uint64_t qwordD8;

            SetupInfo();
        };

        needle::PBRModelInstance* modelInstance;
        float unk301;
        float unk301a;
        float unk302;
        float unk302a;
        float unk303;
        float unk303a;
        int unk304;
        uint32_t unk305;
        uint32_t unk306;
        uint64_t unk307;
        uint64_t unk308;
        uint64_t unk309;
        Unk1 unk310;
        uint64_t unk311;

		virtual void* GetRuntimeTypeInfo() override;
		virtual void OnGOCEvent(GOCEvent event, game::GameObject& ownerGameObject, void* data) override;
        virtual void OnGOCVisualEvent(GOCVisualEvent unkParam1, unsigned int unkParam2, void* unkParam3) override;

        void Setup(const SetupInfo& setupInfo);

        GOCOMPONENT_CLASS_DECLARATION(GOCVisualUserModel);
    };
}
