#pragma once

namespace hh::ui::surfride {
    class SurfRideTextureDataMIRAGE : SurfRide::TextureData {
        csl::ut::MoveArray<hh::needle::Texture*> textures;
        csl::ut::MoveArray<unsigned int> unk2;
        SurfRideTextureDataMIRAGE* original;
        csl::ut::MoveArray<uint8_t> unk5;

    public:
        SurfRideTextureDataMIRAGE(unsigned int count, csl::fnd::IAllocator* allocator);
        SurfRideTextureDataMIRAGE* CreateInstance(csl::fnd::IAllocator* allocator);
    };
}
