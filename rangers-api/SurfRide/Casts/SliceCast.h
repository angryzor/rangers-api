#pragma once

namespace SurfRide {
    struct SRS_SLICE {
        uint32_t flags;
        Vector2 fixedSize;
        Color materialColor;
        Color illuminationColor;
        Color vertexColorTopLeft;
        Color vertexColorBottomLeft;
        Color vertexColorTopRight;
        Color vertexColorBottomRight;
        short cropIndex0;
        short cropIndex1;
    };

    struct SRS_SLICECAST {
        uint32_t flags;
        Vector2 size;
        Vector2 pivot;
        Color vertexColorTopLeft;
        Color vertexColorBottomLeft;
        Color vertexColorTopRight;
        Color vertexColorBottomRight;
        Vector2 fixedSize;
        short sliceHorizontalCount;
        short sliceVerticalCount;
        short horizontalFixedCount;
        short verticalFixedCount;
        short cropRef0Count;
        short cropRef1Count;
        size_t cropRef0Offset;
        uint32_t effectType;
        void* effectData;
        SRS_SLICE slices[1];
    };

    class Slice {
    public:
        SRS_SLICE* sliceData;
        uint64_t unk1;
        Vector2 fixedSize;
        uint32_t flags;
        short cropIndex0;

        Slice(SRS_SLICE* sliceData);
    };

    class SliceCast : public Cast {
    public:
        SRS_SLICECAST* sliceCastData;
        uint32_t type; // (data.flags >> 19) & 0xF
        uint64_t qwordE0;
        Vector2 size;
        Color vertexColorTopLeft;
        Color vertexColorBottomLeft;
        Color vertexColorTopRight;
        Color vertexColorBottomRight;
        bool bool100;
        csl::ut::MoveArray<Slice> slices;

        SliceCast(SRS_CASTNODE* castData, Cast* parentCast, Layer* layer);

        virtual void* GetRuntimeTypeInfo() const override;
        virtual bool UnkFunc2() override;
        virtual uint64_t UnkFunc3() override;
        virtual void CalcTrackTypeWidth(float time, const SRS_TRACK* track) override;
        virtual void CalcTrackTypeHeight(float time, const SRS_TRACK* track) override;
        virtual void* GetCellProbably() const override;
        virtual void SetCellProbably(void* cell) override;
        virtual unsigned int GetCellCount() const override;
        virtual uint64_t UnkFunc12() override;
    };
}
