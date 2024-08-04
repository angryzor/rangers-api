#pragma once

namespace hh::needle {
    struct ShaderObjectCreationInfo {
        VertexLayout* vertexLayout;
        VertexShader* vertexShader;
        PixelShader* pixelShader;
        ComputeShader* computeShader;
        InstanceParameterContainerData* vertexShaderParameterValues; // tt
        InstanceParameterContainerData* pixelShaderParameterValues; // tt
        InstanceParameterContainerData* computeShaderParameterValues[4];
        unsigned int someComputeShaderParams[4];
        unsigned int someCount;
        // uint32_t unk9; // no reference seen yet, possibly padding.
    };

    class ShaderObject : public NeedleRefcountResource {
    public:
    };
}
