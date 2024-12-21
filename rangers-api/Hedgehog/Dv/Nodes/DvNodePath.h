#pragma once

namespace hh::dv{
    class DvNodePath : public DvNodeBase {
    public:
        struct DvNodePathData {
            csl::math::Matrix44 matrix;
        };

        float unk0;
        float unk1;
        DvNodePathData binaryData;
        csl::math::Matrix44 worldMat;
        csl::math::Transform transform;
        long nodeSize;

        virtual void Setup();
        virtual void SetUnkFlag1() override;
        virtual bool SomethingWithWorldMatrix();

        DV_NODE_DECLARATION_BASE(DvNodePath)
    };
}