#pragma once

namespace app::level {
    class PlayerInformation : public hh::fnd::BaseObject {
    public:
        template<typename T>
        struct Unk1 {
            T value{};
            bool isSet{};
        };

        struct Unk2 {
            hh::fnd::Handle<hh::fnd::Messenger> unk1;
            uint16_t unk2;
            uint32_t unk2a;
            hh::fnd::WorldPosition worldPos;
            uint64_t unk3;
            uint64_t unk4;
            csl::math::Vector3 unk5;
            csl::math::Vector3 unk6;
            uint64_t unk7;
            csl::math::Vector3 unk8;
            uint32_t unk9;
            Unk2();
        };

        struct Unk3 {
            float unk1;
            float unk2;
        };

        struct Unk4 {
            uint64_t unk1;
            uint64_t unk2;
        };

        Unk1<hh::fnd::Handle<hh::fnd::Messenger>> playerObject;
        Unk1<player::CharacterIdU8> characterId;
        Unk1<csl::math::Vector3> position;
        Unk1<csl::math::Vector3> vector440;
        Unk1<csl::math::Quaternion> rotation;
        Unk1<float> dword80;
        Unk1<csl::math::Vector3> vector490;
        Unk1<csl::math::Vector3> vector4B0;
        Unk1<csl::math::Vector3> vector4D0;
        Unk1<csl::math::Vector3> vector4F0;
        Unk1<csl::math::Vector3> vector4110;
        Unk1<csl::math::Vector3> vector4130;
        Unk1<csl::math::Vector3> vector4150;
        Unk1<csl::math::Vector3> vector4170;
        Unk1<csl::math::Vector3> vector4190;
        Unk1<csl::math::Vector3> vector41B0;
        Unk1<csl::math::Vector3> vector41D0;
        Unk1<csl::math::Vector3> vector41F0;
        Unk1<csl::math::Vector3> vector4210;
        Unk1<csl::math::Vector3> vector4230;
        Unk1<csl::math::Vector3> vector4250;
        Unk1<csl::math::Vector3> vector4270;
        Unk1<bool> word290;
        Unk1<Unk3> qword294;
        Unk1<Unk3> qword2A0;
        Unk1<uint32_t> boostGaugeCount;
        Unk1<float> stamina;
        Unk1<float> dword2BC;
        Unk1<uint8_t> word2C4;
        Unk1<float> dword2C8;
        Unk1<float> quickCyloopAmount;
        Unk1<uint64_t> qword2D8;
        Unk1<int> dword2E4;
        uint32_t dword2EC;
        uint32_t dword2F0;
        Unk1<csl::math::Vector3> groundNormal;
        Unk1<float> altitude;
        Unk1<csl::math::Vector3> vector4330;
        Unk1<uint32_t> dword350;
        Unk1<uint32_t> dword358;
        uint32_t dword360;
        uint32_t dword364;
        uint32_t dword368;
        uint32_t dword36C;
        uint32_t dword370;
        uint32_t dword374;
        uint32_t dword378;
        uint32_t dword37C;
        uint32_t dword380;
        uint32_t dword384;
        uint32_t dword388;
        uint32_t dword38C;
        uint32_t dword390;
        uint32_t dword394;
        uint64_t qword398;
        uint32_t dword3A0;
        uint32_t dword3A4;
        uint32_t dword3A8;
        uint32_t dword3AC;
        uint32_t dword3B0;
        uint32_t dword3B4;
        uint32_t dword3B8;
        uint32_t dword3BC;
        Unk1<Unk3> qword3C0;
        Unk1<uint32_t> maxRings;
        uint32_t dword3D4;
        uint32_t dword3D8;
        Unk1<Unk2> unk13241;
        Unk1<csl::math::Vector3> vector4480;
        Unk1<Unk3> qword4A0;
        Unk1<uint32_t> dword4AC;
        Unk1<uint8_t> word4B4;
        Unk1<uint32_t> dword4B8;
        Unk1<float> dword4C0;
        Unk1<csl::math::Transform> transform44F0;
        Unk4 qword510[3];

        PlayerInformation(csl::fnd::IAllocator* allocator);
    };
}
