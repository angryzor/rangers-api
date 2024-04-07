#pragma once

namespace csl::ut {
    class String {
    public:
        csl::ut::MoveArray32<char> buffer;
        String(csl::fnd::IAllocator* pAllocator) : buffer{ pAllocator } {}
    };
}
