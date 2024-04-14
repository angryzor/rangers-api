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

    enum class CullMode : uint32_t {
        NONE,
        FRONT,
        BACK,
    };

    enum class FillMode {

    };

    enum class BlendMode : uint32_t {
        ZERO,
        ONE,
    };

    enum class BlendOp : uint32_t {
        ADD,
    };

    enum class ComparisonFunc {

    };

    enum class StencilOp {

    };
}
