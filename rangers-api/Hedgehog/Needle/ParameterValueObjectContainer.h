#pragma once

namespace hh::needle {
    class ParameterValueObjectContainer {
    public:
        void SetShaderParameterFloat(unsigned int index, const float* value, unsigned int size);
    };
}
