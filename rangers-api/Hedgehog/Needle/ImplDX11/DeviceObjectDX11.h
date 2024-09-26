#pragma once

namespace hh::needle {
    namespace ImplDX11 {
        class DeviceObjectDX11 : public NeedleRefcountObject {
        public:
            struct Unk2 {
                SLIST_ENTRY slistEntry;
                uint64_t pad1[11];
            };

            struct Unk3 {
                SLIST_ENTRY slistEntry;
                uint64_t pad1[37];
            };

            template<typename T, size_t Len>
            struct Unk1 {
                uint64_t unk1;
                char unk2[0x2088];
                T slistEntries[Len];
                SLIST_HEADER slistHeader;
                uint64_t unk3;
                uint32_t unk4;
            };

            intrusive_ptr<DevicUniqueObjectContainerDX11> objContainer;
            uint64_t pad1;
            intrusive_ptr<NeedleRefcountObject> unk1[512];
            short unk2;
            Unk1<Unk2, 512> unk3;
            intrusive_ptr<NeedleRefcountObject> unk3a[48];
            Unk1<Unk2, 16> unk4;
            intrusive_ptr<NeedleRefcountObject> unk5[17];
            Unk1<Unk3, 256> unk6;
            intrusive_ptr<NeedleRefcountObject> unk7[1504];
            uint64_t pad2[86];
            uint32_t unk8;
            uint32_t unk9;
            intrusive_ptr<NeedleRefcountObject> unk10[32];
            csl::fnd::Mutex mutex;
            GpuTimer gpuTimer;
            PerfDiagnostics perfDiagnostics;

            enum class CreateDispatchFlags : unsigned int {
                NO_PARAMETER_BUFFER = 1,
                NO_INITIALIZE_UNK1 = 2,
            };

            DeviceObjectDX11(ID3D11Device* d3dDevice);

            RenderingDeviceDispatchDX11Impl* CreateDispatch(ID3D11DeviceContext* deviceContext, CreateDispatchFlags flags);
        };
    }
}