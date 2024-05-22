#pragma once

namespace hh::needle {
    namespace ImplDX11 {
        class DeviceObjectDX11 {
        public:
            void* unk[2];
            DevicUniqueObjectContainerDX11* objContainer;

            enum class CreateDispatchFlags : unsigned int {
                NO_PARAMETER_BUFFER = 1,
                NO_INITIALIZE_UNK1 = 2,
            };

            RenderingDeviceDispatchDX11Impl* CreateDispatch(ID3D11DeviceContext* deviceContext, CreateDispatchFlags flags);
        };
    }
}