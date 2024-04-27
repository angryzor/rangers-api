#pragma once

namespace app {
    class IslandObjInfo : public hh::game::ObjInfo {
        char pad[0x270];

    public:
        IslandObjInfo(csl::fnd::IAllocator* allocator);
    };
}
