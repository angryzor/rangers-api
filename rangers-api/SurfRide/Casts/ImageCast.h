#pragma once

namespace SurfRide {
    struct SRS_IMAGECAST {
        enum class PivotType {
            TOP_LEFT,
            TOP_CENTER,
            TOP_RIGHT,
            CENTER_LEFT,
            CENTER_CENTER,
            CENTER_RIGHT,
            BOTTOM_LEFT,
            BOTTOM_CENTER,
            BOTTOM_RIGHT,
            CUSTOM,
        };

        inline PivotType GetPivotType() const {
            return static_cast<PivotType>((flags >> 4) & 0xF);
        }

        inline void SetPivotType(PivotType pivotType) {
            flags = (flags & ~0xF0) | (static_cast<unsigned int>(pivotType) << 4);
        }

        unsigned int flags;
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
        SRS_CROPREF* cropRefs0;
        SRS_CROPREF* cropRefs1;
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
        void SetText(const char* str);
        Vector2 GetSize() const;
        static Vector2 CalcPivot(float width, float height, SRS_IMAGECAST::PivotType pivotType, const Vector2& customPivot);
        static Vector2 CalcPivot(float width, float height, const SRS_IMAGECAST& imageCastData);
    };
}
