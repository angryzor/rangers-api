#pragma once

#define NEEDLE_RESOURCE_RENDERING_DEVICE_CONTEXT_DX11 0x5F43313156454452ui64

namespace hh::needle::ImplDX11 {
    class RenderingDeviceContextDX11 : public RenderingDeviceContext {
        RenderingDeviceDispatchDX11Impl* renderingDeviceDispatch;
        uint64_t unk2;
        DeviceObjectDX11* deviceObject;
    public:
        RenderingDeviceContextDX11();
        virtual ~RenderingDeviceContextDX11();
        virtual void* QueryResource(size_t id) override;
        virtual const void* QueryResource(size_t id) const override;
        virtual void BeginRendering() override;
        virtual void* EndRendering() override;
        virtual bool ExecuteRendering(RenderingCommandList* commandList) override;
        virtual bool UnkFunc1() override { return true; }
        virtual bool UnkFunc2() override { return true; }
        virtual uint32_t UnkFunc3() override;
        virtual uint64_t UnkFunc4() override;
        virtual uint64_t UnkFunc5() override;
        virtual uint64_t UnkFunc6b() override;
        virtual void SetVertexBuffer(unsigned int bufferSize, SourceBufferSetting* unused, unsigned int totalSize) override;
        virtual uint64_t UnkFunc8() override;
        virtual uint64_t UnkFunc9() override;
        virtual uint64_t UnkFunc10() override;
        virtual uint64_t UnkFunc11() override;
        virtual uint64_t UnkFunc12() override;
        virtual uint64_t UnkFunc13() override;
        virtual void DrawVerticesUP(const void* vertices, unsigned int vertexCount, unsigned int vertexStride) override;
        virtual void DrawIndexedVerticesUP(const unsigned short* indices, unsigned int indexCount, const void* vertices, unsigned int vertexCount, unsigned int vertexStride) override;
        virtual void DrawIndexed(unsigned int indexCount, unsigned int startIndexLocation, int baseVertexLocation) override;
        virtual void DrawIndexedInstanced(unsigned int indexCountPerInstance, unsigned int instanceCount, unsigned int startIndexLocation, int baseVertexLocation, unsigned int startInstanceLocation) override;
        virtual void DrawIndexedInstancedIndirect(NeedleRefcountResource* bufferForArgs, unsigned int alignedByteOffsetForArgs) override;
        virtual void Draw(unsigned int vertexCount, unsigned int startVertexLocation) override;
        virtual void Dispatch(unsigned int threadGroupCountX, unsigned int threadGroupCountY, unsigned int threadGroupCountZ) override;
        virtual void DispatchIndirect(NeedleRefcountResource* bufferForArgs, unsigned int alignedByteOffsetForArgs) override;
        virtual void SetShaderObject(const ShaderObject* shaderObject, const InstanceParameterContainerData** ipcd, unsigned int unkParam1, const unsigned char* unkParam2, unsigned int unkParam3) override;
        virtual void SetPrimitiveTopology(PrimitiveTopology primitiveTopology) override;
        virtual void ResetShaderResource() override;
        virtual uint64_t UnkFunc25() override;
        virtual uint64_t UnkFunc26() override;
        virtual uint64_t UnkFunc27() override;
        virtual uint64_t UnkFunc28() override;
        virtual uint64_t UnkFunc29() override;
        virtual uint64_t UnkFunc30() override;
        virtual uint64_t UnkFunc31() override;
        virtual uint64_t UnkFunc32() override;
        virtual uint64_t UnkFunc33() override;
        virtual uint64_t UnkFunc34() override;
        virtual uint64_t UnkFunc35() override;
        virtual uint64_t UnkFunc36() override;
        virtual uint64_t UnkFunc37() override;
        virtual void UnkFunc37b() override {}
        virtual uint64_t SetVertexBufferDirect() override;
        virtual uint64_t SetIndexBufferDirect() override;
        virtual uint64_t SetConstantBufferDirect() override;
        virtual uint64_t SetRegularBufferDirect() override;
        virtual uint64_t UnkFunc42() override;
        virtual uint64_t UnkFunc43() override;
        virtual uint64_t UnkFunc44() override;
        virtual uint64_t UnkFunc45() override;
        virtual uint64_t UnkFunc46() override;
        virtual uint64_t UnkFunc47() override;
        virtual uint64_t UnkFunc48() override;
        virtual uint64_t UnkFunc49() override;
        virtual uint64_t UnkFunc50() override;
        virtual uint64_t SetCullMode(CullMode cullMode) override;
        virtual uint64_t SetFillMode(FillMode fillMode) override;
        virtual uint64_t SetScissorEnable(bool enabled) override;
        virtual uint64_t UnkFunc54() override;
        virtual uint64_t SetDepthEnable(bool enabled) override;
        virtual uint64_t SetDepthWriteEnable(bool enabled) override;
        virtual uint64_t SetDepthComparisonFunc(ComparisonFunc comparisonFunc) override;
        virtual uint64_t SetTwoSidedStencil(bool unkParam1, ComparisonFunc comparisonFunc1, int unkParam21, unsigned int unkParam31, StencilOp stencilOp11, StencilOp stencilOp12, StencilOp stencilOp13, unsigned int unkParam41, ComparisonFunc comparisonFunc2, int unkParam22, unsigned int unkParam32, StencilOp stencilOp21, StencilOp stencilOp22, StencilOp stencilOp23, unsigned int unkParam42) override;
        virtual uint64_t SetStencil(bool unkParam1, ComparisonFunc comparisonFunc, int unkParam2, unsigned int unkParam3, StencilOp stencilOp1, StencilOp stencilOp2, StencilOp stencilOp3, unsigned int unkParam4) override;
        virtual uint64_t SetColorWriteEnable(bool unkParam1) override;
        virtual uint64_t UnkFunc61() override;
        virtual uint64_t SetBlendDescSetting() override;
        virtual void SetBlendModeWithAlpha(bool enabled, BlendMode src, BlendMode dst, BlendOp op, BlendMode alphaSrc, BlendMode alphaDst, BlendOp alphaOp) override;
        virtual void SetBlendMode(bool enabled, BlendMode src, BlendMode dst, BlendOp op) override;
        virtual uint64_t SetViewport(const ViewportSetting* viewportSetting, unsigned int unkParam1) override;
        virtual uint64_t MaybeSetScissor(Rectangle* scissorRect, unsigned int unkParam1) override;
        virtual uint64_t UnkFunc67() override;
        virtual uint64_t UnkFunc68() override;
        virtual uint64_t UnkFunc69() override;
        virtual uint64_t UnkFunc70() override;
        virtual uint64_t UnkFunc71() override;
        virtual uint64_t UnkFunc72() override;
        virtual uint64_t UnkFunc73() override;
        virtual uint64_t UnkFunc74() override;
        virtual uint64_t UnkFunc75() override;
        virtual uint64_t UnkFunc76() override;
        virtual uint64_t UnkFunc77() override;
        virtual uint64_t UnkFunc78() override;
        virtual uint64_t UnkFunc79() override;
        virtual uint64_t UnkFunc80() override;
        virtual uint64_t UnkFunc81() override;
        virtual uint64_t UnkFunc82() override;
        virtual uint64_t UnkFunc83() override;
        virtual bool UnkFunc84() override { return true; }
        virtual bool Maybe_IsCapturingNow() override;
        virtual void PushMarker(const char* id) override;
        virtual void PopMarker() override;
        virtual void SetMarker(const char* id) override;
        virtual uint64_t UnkFunc89() override;
        virtual uint64_t UnkFunc90() override;
        virtual uint64_t UnkFunc91() override;
        virtual uint64_t UnkFunc92() override;
        virtual uint64_t UnkFunc93() override;
        virtual uint64_t UnkFunc94() override;
        virtual uint64_t UnkFunc95() override;
        virtual uint64_t UnkFunc96() override;
        virtual uint64_t UnkFunc97() override;
        virtual uint64_t UnkFunc98() override;
        virtual uint64_t UnkFunc99() override;
        virtual uint64_t UnkFunc100() override;
        virtual uint64_t UnkFunc101() override;
        virtual uint64_t UnkFunc102() override;
        virtual uint64_t UnkFunc103() override;
        virtual uint64_t UnkFunc104() override;
        virtual uint32_t UnkFunc105() override { return 0; }
        virtual uint64_t UnkFunc106() override;
        virtual uint64_t UnkFunc107() override;
        virtual bool UnkFunc108() override { return false; }
        virtual uint64_t UnkFunc109() override;
        virtual bool UnkFunc110() override { return false; }
        virtual void UnkFunc110b() override {}
        virtual uint64_t UnkFunc111() override;

        void SetDeviceObjectAndDispatch(DeviceObjectDX11* deviceObject, RenderingDeviceDispatchDX11Impl* dispatch);
    };
}
