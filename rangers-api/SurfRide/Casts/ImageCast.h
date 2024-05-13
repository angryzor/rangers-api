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
        short cropIndex[2];
        SrTexCoord cropRectMin[2];
        SrTexCoord cropRectMax[2];
        bool haveCropRect[2];
        uint64_t unk106;

        ImageCast(SRS_CASTNODE* castData, Cast* parentCast, Layer* layer);
        
        virtual void* GetRuntimeTypeInfo() const override;
        virtual bool UnkFunc2() override;
        virtual uint64_t UnkFunc3() override;
        virtual void CalcTrackTypeWidth(float time, const SRS_TRACK* track) override;
        virtual void CalcTrackTypeHeight(float time, const SRS_TRACK* track) override;
        virtual void CalcTrackTypeCropIndex0(float time, const SRS_TRACK* track) override;
        virtual void CalcTrackTypeCropIndex1(float time, const SRS_TRACK* track) override;
        virtual void* GetCellProbably() const override;
        virtual void SetCellProbably(void* cell) override;
        virtual unsigned int GetCellCount() const override;
        virtual void UpdateThis(float time, const Cast* parentCast) override;
        virtual uint64_t UnkFunc12() override;

        void InitializeText();
    };
}
