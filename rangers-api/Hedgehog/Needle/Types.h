#pragma once

// Reusing this here because I don't want to redefine this...
typedef csl::math::Position float_vector3;

namespace hh::needle {
    enum class PrimitiveTopology {
        POINT_LIST,
        LINE_LIST,
        LINE_STRIP,
        TRIANGLE_LIST,
        TRIANGLE_STRIP,
    };

    enum class CullMode {
        UNK1,
        UNK2,
    };

    enum class FillMode {

    };

    enum class BlendMode {

    };

    enum class BlendOp {

    };

    enum class ComparisonFunc {

    };

    enum class StencilOp {

    };
}
