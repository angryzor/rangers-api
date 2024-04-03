#pragma once

namespace hh::needle {
    class PrimitiveRenderer {
        RenderingDeviceContext* renderingDeviceContext;

    public:
        typedef csl::math::Vector4 Vertex;
    
    public:
        void Begin(void* unkParam1, const float* unkParam2, const float* unkParam3);
        void DrawVertices(PrimitiveTopology topology, const float* unkParam1, unsigned int indexCount, unsigned int vertexCount, const unsigned short* indices, const Vertex* vertices, unsigned int unkParam5);
        void SetMaterial(int unkParam);
    };
}
