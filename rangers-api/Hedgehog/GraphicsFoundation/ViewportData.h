#pragma once

namespace hh::gfnd {
    struct ViewportDimensions {
        float x;
        float y;
        float width;
        float height;
        float maybeRenderWidth;
        float maybeRenderHeight;
    };

    struct alignas(16) ViewportData {
        csl::math::Matrix44 viewMatrix;
        csl::math::Matrix44 inverseViewMatrix;
        ViewportDimensions viewportDimensions;
        csl::math::Matrix44 projMatrix;
        uint32_t clipPlanesToUse; // probably more involved. 0 = near/farClip, 1 & 2 = near/farClip2
        csl::math::Vector3 lookAtPos;
        float fov;
        float aspectRatio;
        float nearClip;
        float farClip;
        float nearClip2;
        float farClip2;
        uint64_t unk8;

        ViewportData();
        ViewportData& operator=(const ViewportData& other);
        void SetDimensions(const ViewportDimensions& other);
        void SetPerspectiveProjectionMatrix(float fov, float aspectRatio, float nearClip, float farClip);
    };
}
