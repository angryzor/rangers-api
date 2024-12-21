#pragma once

namespace hh::dv{
    class DvNodeCamera : public DvNodeBase {
    public:
        struct DvNodeCameraData {
            int flags;
            int frameProgressionCount;
            int captionCount;
            int field0c;
        };

        struct CameraData {
            csl::math::Vector3 position;
            csl::math::Vector3 target;
            float unk0;
            float unk1;
            float unk2;
            float unk3;
            hh::gfnd::ViewportData::FovProjectionParameters fovProjectionParams;
        };

        DvNodeCameraData binaryData;
        hh::game::CameraComponent* camComponent;
        int unk3;
        int unk4;
        CameraData data;
        csl::math::Vector4 unk5;
        csl::math::Vector4 unk6;
        float nearZ;
        float farZ;
        int64_t unk7;
        csl::math::Vector3 unk8;
        int unk9;
        int unk10;
        int64_t unk11;

        virtual void UnkFunc();
        virtual void DisableCameraComponent();
        virtual bool Setup();
        virtual void UpdateCameraLookAt();
        virtual bool IsUnkFlag0() override;

        DV_NODE_DECLARATION_BASE(DvNodeCamera)
    };
}