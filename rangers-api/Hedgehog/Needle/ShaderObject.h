#pragma once

namespace hh::needle {
    struct ShaderObjectCreationInfo {
        VertexLayout* vertexLayout;
        VertexShader* vertexShader;
        PixelShader* pixelShader;
        ComputeShader* computeShader;
        InstanceParameterContainerData* vertexShaderParameterValues; // tt
        InstanceParameterContainerData* pixelShaderParameterValues; // tt
        InstanceParameterContainerData* instanceParameterContainers[4];
        unsigned int instanceParameterContainerSizes[4]; //tt, maybe container type
        unsigned int instanceParameterContainerCount;
        // uint32_t unk9; // no reference seen yet, possibly padding.
    };

    class ShaderObject : public NeedleRefcountResource {
    public:
    };
}
