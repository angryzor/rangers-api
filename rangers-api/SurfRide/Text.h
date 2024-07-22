#pragma once

namespace SurfRide {
    struct SRS_TEXTDATA {
        enum class Flag : uint32_t {
            WRAP,
            NO_LINE_HEIGHT,
        };

        enum class VerticalAlignment {
            TOP,
            CENTER,
            BOTTOM,
        };

        inline bool GetFlagState(Flag flag) const {
            return flags & (1 << static_cast<unsigned int>(flag));
        }

        inline void SetFlagState(Flag flag, bool state) {
            unsigned int mask = 1 << static_cast<unsigned int>(flag);
            if (state)
                flags |= mask;
            else
                flags &= ~mask;
        }

        inline VerticalAlignment GetVerticalAlignment() const {
            return static_cast<VerticalAlignment>((flags >> 4) & 0xF);
        }

        inline void SetVerticalAlignment(VerticalAlignment alignment) {
            flags = (flags & ~0xF0) | ((static_cast<unsigned int>(alignment) & 0xF) << 4);
        }

        unsigned int flags;
        unsigned int fontIndex;
        const char* str; // UTF-8 encoded
        Vector2 scale;
        short paddingLeft;
        short paddingRight;
        short paddingTop;
        short paddingBottom;
        short tracking;
        short lineHeight;
        SRS_FONT* font;
    };

    struct SRS_IMAGECAST;
    class ImageCast;
    class Text {
    public:
        ImageCast* imageCast;
        SRS_IMAGECAST* imageCastData;
        SRS_TEXTDATA* textData;
        uint32_t lineCount;
        uint32_t glyphCount;
        Vector2 startPosition;
        bool counted;
        const char* buffer; // UTF-8 encoded
        uint32_t bufferSize;
        Vector2 calculatedTextSize;
        Vector2 textAreaSize;
        csl::ut::MoveArray<SRS_CELL3D> cells;

        Text(ImageCast* imageCast);

        void SetText(const char* str);
        void Count();
        void AllocateTextCells();
    };
}
