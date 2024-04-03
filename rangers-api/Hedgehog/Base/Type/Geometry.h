#pragma once

namespace hh::fnd {
    struct Geometry {
        csl::ut::MoveArray<csl::math::Vector3> vertices;
        csl::ut::MoveArray<fnd::Triangle> triangles;
        Geometry(csl::fnd::IAllocator* allocator) : vertices{ allocator }, triangles{ allocator } {}
    };
}
