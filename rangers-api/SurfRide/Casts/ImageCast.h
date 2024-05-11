#pragma once

namespace SurfRide {
    struct SRS_IMAGECAST {
        uint32_t flags;
        csl::math::Vector2 size;
        csl::math::Vector2 pivot;
        Color vertexColorTopLeft;
        Color vertexColorBottomLeft;
        Color vertexColorTopRight;
        Color vertexColorBottomRight;
        short cropIndex0;
        short cropIndex1;
        short cropRef0Count;
        short cropRef1Count;
        size_t cropRef0Offset;
        size_t cropRef1Offset;
        SRS_TEXTDATA* textData;
        uint32_t effectType;
        void* effectData;
    };

    class Text;
    class ImageCast : public Cast {
    public:
        SRS_IMAGECAST* imageCastData;
        uint32_t flags;
        Text* text;
        Vector2 size;
        Color vertexColorTopLeft;
        Color vertexColorBottomLeft;
        Color vertexColorTopRight;
        Color vertexColorBottomRight;
        short cropIndex0;
        short cropIndex1;
        SrTexCoord texCoords0[2];
        SrTexCoord texCoords1[2];
        short unk107;
        uint64_t unk106;

        ImageCast(SRS_CASTNODE* castData, Cast* parentCast, Layer* layer);
        void InitializeText();
    };
}
