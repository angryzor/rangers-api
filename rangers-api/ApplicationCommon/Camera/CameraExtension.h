#pragma once

namespace app_cmn::camera {
    class CameraFrame;
    class CameraExtension : hh::fnd::ReferencedObject {
    public:
        CameraFrame* cameraFrame;
    };
}
