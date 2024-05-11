#pragma once

namespace SurfRide {
    struct SRS_TEXTDATA {

    };

    struct SRS_IMAGECAST;
    class ImageCast;
    class Text {
    public:
        ImageCast* imageCast;
        SRS_IMAGECAST* imageCastData;
        SRS_TEXTDATA* textData;
        uint32_t qword18;
        uint32_t count;
        uint64_t qword20;
        bool counted;
        uint64_t qword30;
        uint32_t dword38;
        Vector2 qword3C;
        Vector2 qword44;
        csl::ut::MoveArray<SRS_CELL3D> cells;

        Text(ImageCast* imageCast);

        size_t Count();
        void AllocateTextCells();
    };
}
