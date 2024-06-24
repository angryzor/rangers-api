#pragma once

#define NEEDLE_RESOURCE_MESH_RESOURCE 0x305345524853454Dui64 // '0SERHSEM'

namespace hh::needle {
    class MeshResource : public TNeedleRefcountResource<NEEDLE_RESOURCE_MESH_RESOURCE, NeedleRefcountResource> {
    public:
        void GetAABB(float_vector3 (*aabb)[2]);
        CNameIDObject* GetMaterialNameID(unsigned int idx) const;
        MaterialResource* GetMaterialResource(unsigned int idx) const;
        MaterialResource* GetNodeMaterialResource(unsigned int idx) const;
    };
}
