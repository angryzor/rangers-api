#pragma once

#define NEEDLE_RESOURCE_RENDERING_DEVICE_CONTEXT 0x43564452444E4552ui64

namespace hh::needle {
    class ShaderObject;
    class InstanceParameterContainerData;
    class RenderingDeviceContext : public TNeedleRefcountResource<NEEDLE_RESOURCE_RENDERING_DEVICE_CONTEXT, NeedleRefcountResource> {
    public:
        virtual void BeginRendering() = 0;
        virtual void* EndRendering() = 0;
        virtual bool ExecuteRendering() = 0;
        virtual bool UnkFunc1() = 0;
        virtual bool UnkFunc2() = 0;
        virtual uint32_t UnkFunc3() = 0;
        virtual uint64_t UnkFunc4() = 0;
        virtual uint64_t UnkFunc5() = 0;
        virtual uint64_t UnkFunc6() = 0;
        virtual uint64_t UnkFunc7b() = 0;
        virtual uint64_t UnkFunc8() = 0;
        virtual uint64_t UnkFunc9() = 0;
        virtual uint64_t UnkFunc10() = 0;
        virtual uint64_t UnkFunc11() = 0;
        virtual uint64_t UnkFunc12() = 0;
        virtual uint64_t UnkFunc13() = 0;
        virtual uint64_t UnkFunc14() = 0;
        virtual void DrawIndexedVerticesUP(const unsigned short* indices, unsigned int indexCount, const void* vertices, unsigned int vertexCount, unsigned int vertexStride) = 0;
        virtual uint64_t UnkFunc16() = 0;
        virtual uint64_t UnkFunc17() = 0;
        virtual uint64_t UnkFunc18() = 0;
        virtual uint64_t UnkFunc19() = 0;
        virtual uint64_t UnkFunc20() = 0;
        virtual uint64_t UnkFunc21() = 0;
        virtual void SetShaderObject(const ShaderObject* shaderObject, const InstanceParameterContainerData** ipcd, unsigned int unkParam1, const unsigned char* unkParam2, unsigned int unkParam3) = 0;
        virtual void SetPrimitiveTopology(PrimitiveTopology primitiveTopology) = 0;
        virtual uint64_t UnkFunc24() = 0;
        virtual uint64_t UnkFunc25() = 0;
        virtual uint64_t UnkFunc26() = 0;
        virtual uint64_t UnkFunc27() = 0;
        virtual uint64_t UnkFunc28() = 0;
        virtual uint64_t UnkFunc29() = 0;
        virtual uint64_t UnkFunc30() = 0;
        virtual uint64_t UnkFunc31() = 0;
        virtual uint64_t UnkFunc32() = 0;
        virtual uint64_t UnkFunc33() = 0;
        virtual uint64_t UnkFunc34() = 0;
        virtual uint64_t UnkFunc35() = 0;
        virtual uint64_t UnkFunc36() = 0;
        virtual uint64_t UnkFunc37() = 0;
        virtual void UnkFunc37b() = 0;
        virtual uint64_t UnkFunc38() = 0;
        virtual uint64_t UnkFunc39() = 0;
        virtual uint64_t UnkFunc40() = 0;
        virtual uint64_t UnkFunc41() = 0;
        virtual uint64_t UnkFunc42() = 0;
        virtual uint64_t UnkFunc43() = 0;
        virtual uint64_t UnkFunc44() = 0;
        virtual uint64_t UnkFunc45() = 0;
        virtual uint64_t UnkFunc46() = 0;
        virtual uint64_t UnkFunc47() = 0;
        virtual uint64_t UnkFunc48() = 0;
        virtual uint64_t UnkFunc49() = 0;
        virtual uint64_t UnkFunc50() = 0;
        virtual uint64_t SetCullMode(CullMode cullMode) = 0;
        virtual uint64_t SetFillMode(FillMode fillMode) = 0;
        virtual uint64_t SetScissorEnable(bool enabled) = 0;
        virtual uint64_t UnkFunc54() = 0;
        virtual uint64_t SetDepthEnable(bool enabled) = 0;
        virtual uint64_t SetDepthWriteEnable(bool enabled) = 0;
        virtual uint64_t SetDepthComparisonFunc(ComparisonFunc comparisonFunc) = 0;
        virtual uint64_t SetTwoSidedStencil(bool unkParam1, ComparisonFunc comparisonFunc1, int unkParam21, unsigned int unkParam31, StencilOp stencilOp11, StencilOp stencilOp12, StencilOp stencilOp13, unsigned int unkParam41, ComparisonFunc comparisonFunc2, int unkParam22, unsigned int unkParam32, StencilOp stencilOp21, StencilOp stencilOp22, StencilOp stencilOp23, unsigned int unkParam42) = 0;
        virtual uint64_t SetStencil(bool unkParam1, ComparisonFunc comparisonFunc, int unkParam2, unsigned int unkParam3, StencilOp stencilOp1, StencilOp stencilOp2, StencilOp stencilOp3, unsigned int unkParam4) = 0;
        virtual uint64_t SetColorWriteEnable(bool unkParam1) = 0;
        virtual uint64_t UnkFunc61() = 0;
        virtual uint64_t SetBlendDescSetting() = 0;
        virtual uint64_t SetBlendMode(bool unkParam1, BlendMode mode1, BlendMode mode2, BlendOp operation) = 0;
        virtual uint64_t SetBlendMode(bool unkParam1, BlendMode mode11, BlendMode mode12, BlendOp operation1, BlendMode mode21, BlendMode mode22, BlendOp operation2) = 0;
        virtual uint64_t SetViewport(const ViewportSetting* viewportSetting, unsigned int unkParam1) = 0;
        virtual uint64_t MaybeSetScissor(Rectangle* scissorRect, unsigned int unkParam1) = 0;
        virtual uint64_t UnkFunc67() = 0;
        virtual uint64_t UnkFunc68() = 0;
        virtual uint64_t UnkFunc69() = 0;
        virtual uint64_t UnkFunc70() = 0;
        virtual uint64_t UnkFunc71() = 0;
        virtual uint64_t UnkFunc72() = 0;
        virtual uint64_t UnkFunc73() = 0;
        virtual uint64_t UnkFunc74() = 0;
        virtual uint64_t UnkFunc75() = 0;
        virtual uint64_t UnkFunc76() = 0;
        virtual uint64_t UnkFunc77() = 0;
        virtual uint64_t UnkFunc78() = 0;
        virtual uint64_t UnkFunc79() = 0;
        virtual uint64_t UnkFunc80() = 0;
        virtual uint64_t UnkFunc81() = 0;
        virtual uint64_t UnkFunc82() = 0;
        virtual uint64_t UnkFunc83() = 0;
        virtual bool UnkFunc84() = 0;
        virtual bool Maybe_IsCapturingNow() = 0;
        virtual void PushMarker(const char* id) = 0;
        virtual void PopMarker() = 0;
        virtual void SetMarker(const char* id) = 0;
        virtual uint64_t UnkFunc89() = 0;
        virtual uint64_t UnkFunc90() = 0;
        virtual uint64_t UnkFunc91() = 0;
        virtual uint64_t UnkFunc92() = 0;
        virtual uint64_t UnkFunc93() = 0;
        virtual uint64_t UnkFunc94() = 0;
        virtual uint64_t UnkFunc95() = 0;
        virtual uint64_t UnkFunc96() = 0;
        virtual uint64_t UnkFunc97() = 0;
        virtual uint64_t UnkFunc98() = 0;
        virtual uint64_t UnkFunc99() = 0;
        virtual uint64_t UnkFunc100() = 0;
        virtual uint64_t UnkFunc101() = 0;
        virtual uint64_t UnkFunc102() = 0;
        virtual uint64_t UnkFunc103() = 0;
        virtual uint64_t UnkFunc104() = 0;
        virtual uint32_t UnkFunc105() = 0;
        virtual uint64_t UnkFunc106() = 0;
        virtual uint64_t UnkFunc107() = 0;
        virtual bool UnkFunc108() = 0;
        virtual uint64_t UnkFunc109() = 0;
        virtual bool UnkFunc110() = 0;
        virtual void UnkFunc110b() = 0;
        virtual uint64_t UnkFunc111() = 0;
    };
}
