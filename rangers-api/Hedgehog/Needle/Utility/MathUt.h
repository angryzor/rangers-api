#pragma once

namespace hh::needle::mathut {
    void convert(float* dest, const csl::math::Matrix44& src);
    void convert(csl::math::Matrix44& dest, const float* src);
}
