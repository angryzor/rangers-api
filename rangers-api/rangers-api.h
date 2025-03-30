#pragma once

// #include "External/helpers.h"
// #include "External/sigscan.h"

// // Lua 5.4.1
// #include "External/Lua541/include/lua.hpp"

// Common Sonicteam Library

#include <cstdint>
#include <d3d11.h>

#ifdef EXPORTING_TYPES

struct SLIST_HEADER_SHIM {
    unsigned long long Alignment;
    unsigned long long Region;
};
#define SLIST_HEADER SLIST_HEADER_SHIM

namespace std {
    template<typename T>
    class optional {
        T value;
        bool hasValue;
    };
}

#else

#include <new>
#include <cassert>
#include <cstring>
#include <type_traits>
#include <synchapi.h>

#endif

// Why does the Win32 API do this...
#ifdef UpdateResource
#undef UpdateResource
#endif
#ifdef SendMessage
#undef SendMessage
#endif
#ifdef max
#undef max
#endif
#ifdef VOID
#undef VOID
#endif
#ifdef CreateDirectory
#undef CreateDirectory
#endif
#ifdef GetUserName
#undef GetUserName
#endif

#include <ucsl/newtype.h>

#include "Sonicteam/math/math.h"
#include "Sonicteam/System/IAllocator.h"

namespace rangerssdk::ucsl {
    struct AllocatorSystem {
        using allocator_type = csl::fnd::IAllocator;

        inline static csl::fnd::IAllocator* get_allocator();
    };
}

#include "Sonicteam/Utility/collections/Array.h"
#include "Sonicteam/Utility/collections/FixedArray.h"
#include "Sonicteam/Utility/collections/HashMap.h"
#include "Sonicteam/Utility/collections/LinkList.h"
#include "Sonicteam/Utility/collections/MoveArray.h"
#include "Sonicteam/Utility/collections/MoveArray32.h"
#include "Sonicteam/Utility/collections/InPlaceMoveArray.h"
#include "Sonicteam/Utility/collections/InPlaceMoveArray32.h"
#include "Sonicteam/Utility/collections/BitArray.h"
#include "Sonicteam/Utility/collections/InPlaceBitArray.h"
#include "Sonicteam/Utility/collections/PointerMap.h"
#include "Sonicteam/Utility/collections/StringMap.h"
#include "Sonicteam/Utility/Hash.h"
#include "Sonicteam/Utility/BasicString.h"
#include "Sonicteam/Utility/Bitset.h"
#include "Sonicteam/Utility/Color.h"
#include "Sonicteam/Utility/NonCopyable.h"
#include "Sonicteam/Utility/Pair.h"
#include "Sonicteam/Utility/String.h"
#include "Sonicteam/Utility/VariableString.h"

#include "Sonicteam/System/Singleton.h"
#include "Sonicteam/System/Mutex.h"
#include "Sonicteam/System/HeapBase.h"
#include "Sonicteam/System/FreeListLikeHeapBase.h"
#include "Sonicteam/System/FreeListHeap.h"
#include "Sonicteam/System/OptimizedFreeListHeap.h"
#include "Sonicteam/System/TlsfHeap.h"
#include "Sonicteam/System/Delegate.h"
#include "Sonicteam/System/Function.h"
#include "Sonicteam/System/ThreadSleep.h"

#include "Hedgehog/rsdx/rsdx_noncopyable.h"
#include "Hedgehog/rsdx/core/algo/hhrsdxalgomutex.h"
#include "Hedgehog/rsdx/heapmemory/algo/memory_template_fixpool.hpp"
#include "Hedgehog/rsdx/heapmemory/algo/memory_template_tiny.hpp"
#include "Hedgehog/rsdx/heapmemory/allocator/hhrsdxmemoryallocatorcache.h"
#include "Hedgehog/rsdx/heapmemory/allocator/hhrsdxmemorymain_systemmemory_allocatormapper.hpp"
#include "Hedgehog/rsdx/heapmemory/allocator/hhrsdxmemorymain.h"
#include "Hedgehog/rsdx/heapmemory/allocator/hhrsdxmemorysystemmemory.h"
#include "Hedgehog/rsdx/heapmemory/util/hhrsdxmemorymapperutil.h"
#include "Hedgehog/rsdx/mtbase/util/hhmtjobmemoryutilities.h"
#include "Hedgehog/rsdx/mtbase/util/hhmtjobdispatchfunctions.h"
#include "Hedgehog/rsdx/os/system/hhrsdxsystemglobal.hpp"
#include "Hedgehog/rsdx/os/thread/hhrsdxservicethread.hpp"
#include "Hedgehog/rsdx/os/thread/hhrsdxthread.hpp"

#include "Hedgehog/System/hhAllocator.h"
#include "Hedgehog/System/SingletonInitNode.h"

// Hedgehog Library
#include "Hedgehog/Base/System/MemoryRouter.h"
#include "Hedgehog/Base/System/hhBaseObject.h"
#include "Hedgehog/Base/System/hhReferencedObject.h"
#include "Hedgehog/Base/System/RefByHandleObject.h"
#include "Hedgehog/Base/System/hhProperty.h"
#include "Hedgehog/Base/System/hhCollection.h"
#include "Hedgehog/Base/System/HFrame.h"
#include "Hedgehog/Base/System/HandleManager.h"
#include "Hedgehog/Base/System/hhHandle.h"
#include "Hedgehog/Base/System/ReloaderListener.h"
#include "Hedgehog/Base/System/SUpdateInfo.h"
#include "Hedgehog/Base/System/UpdatingPhase.h"

// Hedgehog Universe Library
#include "Hedgehog/Base/Universe/hhMessenger.h"
#include "Hedgehog/Base/Universe/hhMessage.h"
#include "Hedgehog/Base/Universe/MessageQueue.h"
#include "Hedgehog/Base/Universe/MessageManager.h"

#include "Hedgehog/Utility/TempString.h"
#include "Hedgehog/Utility/TempMoveArray.h"
#include "Hedgehog/Utility/FSM/TinyFsm.h"
#include "Hedgehog/Utility/FSM/StateDesc.h"
#include "Hedgehog/Utility/FSM/StateManager.h"
#include "Hedgehog/Utility/FSM/State.h"
#include "Hedgehog/Utility/FSM/Hsm.h"
#include "Hedgehog/Utility/BinaryFile.h"
#include "Hedgehog/Utility/AabbTree.h"
#include "Hedgehog/Utility/BvWorld.h"
#include "Hedgehog/Utility/KdTree.h"

#include "Hedgehog/Base/Type/WorldPosition.h"
#include "Hedgehog/Base/Type/LogData.h"
#include "Hedgehog/Base/Type/Triangle.h"
#include "Hedgehog/Base/Type/Geometry.h"
#include "Hedgehog/Base/Type/WireGeometry.h"
#include "Hedgehog/Base/Type/ResLightParameter.h"

#include "Hedgehog/Cri/CriSystem.h"

#include "Hedgehog/Filesystem/Uri.h"
#include "Hedgehog/Filesystem/InplaceUri.h"
#include "Hedgehog/Filesystem/InplaceTempUri.h"
#include "Hedgehog/Filesystem/FileInfo.h"
#include "Hedgehog/Filesystem/FileBind.h"
#include "Hedgehog/Filesystem/FileResource.h"
#include "Hedgehog/Filesystem/FileCache.h"
#include "Hedgehog/Filesystem/FileSystem.h"

// Resources
#include "Hedgehog/Resource/ManagedResource.h"
#include "Hedgehog/Resource/ResourceTypeRegistry.h"
#include "Hedgehog/Resource/ResourceNameResolver.h"
#include "Hedgehog/Resource/ResourceCriticalSection.h"
#include "Hedgehog/Resource/FilePathResolver.h"
#include "Hedgehog/Resource/ResourceContainer.h"
#include "Hedgehog/Resource/StaticResourceContainer.h"
#include "Hedgehog/Resource/UniqueResourceContainer.h"
#include "Hedgehog/Resource/UnpackedResourceContainer.h"
#include "Hedgehog/Resource/DynamicResourceContainer.h"
#include "Hedgehog/Resource/TagResourceContainer.h"
#include "Hedgehog/Resource/Packfile.h"
#include "Hedgehog/Resource/ResourceLoader.h"
#include "Hedgehog/Resource/ResourceManager.h"
#include "Hedgehog/Resource/ResourceResolver.h"
#include "Hedgehog/Resource/FilePathResolverUtil.h"

#include "Hedgehog/Game/ObjectId.h"

// Hedgehog Reflection Library
#include "Hedgehog/Reflection/ResReflection.h"
#include "Hedgehog/Reflection/RflSystem.h"
#include "Hedgehog/Reflection/hhRflTypeInfo.h"
#include "Hedgehog/Reflection/hhRflTypeInfoRegistry.h"
#include "Hedgehog/Reflection/hhRflClassNameRegistry.h"
#include "Hedgehog/Reflection/hhBuiltinTypeRegistry.h"
#include "Hedgehog/Reflection/DeepCopier.h"

#include "Heuristics/Reflection.h"

#include "Hedgehog/Needle/Utility/Binhash.h"
#include "Hedgehog/Needle/Utility/MathUt.h"
#include "Hedgehog/Needle/Types.h"
#include "Hedgehog/Needle/Rectangle.h"
#include "Hedgehog/Needle/Box.h"
#include "Hedgehog/Needle/EntryLink.h"
#include "Hedgehog/Needle/RsFlagMask.h"
#include "Hedgehog/Needle/CScratchMemoryContext.h"
#include "Hedgehog/Needle/NeedleObject.h"
#include "Hedgehog/Needle/NeedleRefcountObject.h"
#include "Hedgehog/Needle/Utility/intrusive_ptr.h"
#include "Hedgehog/Needle/NeedleSStr.h"
#include "Hedgehog/Needle/NeedleRefcountResource.h"
#include "Hedgehog/Needle/TNeedleRefcountResource.h"
#include "Hedgehog/Needle/TNeedleRefcountUniqueObjectBase.h"
#include "Hedgehog/Needle/NeedleObjectWithParameterBuffer.h"
#include "Hedgehog/Needle/NeedleBlob.h"
#include "Hedgehog/Needle/CNameIDObject.h"
#include "Hedgehog/Needle/CNameIDObjectStatic.h"
#include "Hedgehog/Needle/NeedleType.h"
#include "Hedgehog/Needle/GraphicsMemoryLayout.h"
#include "Hedgehog/Needle/SRawImageInfo.h"
#include "Hedgehog/Needle/ParameterValue.h"
#include "Hedgehog/Needle/UserModelShaderParamter.h"
#include "Hedgehog/Needle/MirageResource.h"
#include "Hedgehog/Needle/SurfaceBase.h"
#include "Hedgehog/Needle/Texture.h"
#include "Hedgehog/Needle/Buffer.h"
#include "Hedgehog/Needle/ConstantBuffer.h"
#include "Hedgehog/Needle/VertexShader.h"
#include "Hedgehog/Needle/PixelShader.h"
#include "Hedgehog/Needle/ComputeShader.h"
#include "Hedgehog/Needle/VertexLayout.h"
#include "Hedgehog/Needle/RenderTarget.h"
#include "Hedgehog/Needle/UnorderedAccessView.h"
#include "Hedgehog/Needle/DepthStencil.h"
#include "Hedgehog/Needle/MaterialResource.h"
#include "Hedgehog/Needle/MeshResource.h"
#include "Hedgehog/Needle/Model.h"
#include "Hedgehog/Needle/ViewportSetting.h"
#include "Hedgehog/Needle/UnorderedAccessViewsSetting.h"
#include "Hedgehog/Needle/RenderTargetsSetting.h"
#include "Hedgehog/Needle/SamplerStateSetting.h"
#include "Hedgehog/Needle/SDrawPassSceneSetting.h"
#include "Hedgehog/Needle/SGlobalParameterSceneSetting.h"
#include "Hedgehog/Needle/SCullGroupSetting.h"
#include "Hedgehog/Needle/InstanceParametersBuildParameter.h"
#include "Hedgehog/Needle/InstanceParameterContainerData.h"
#include "Hedgehog/Needle/InstanceParameterCounterUtil.h"
#include "Hedgehog/Needle/ParameterValueObjectContainer.h"
#include "Hedgehog/Needle/ParameterValueObject.h"
#include "Hedgehog/Needle/ParamValueOverrideHelper.h"
#include "Hedgehog/Needle/ShaderMeshMaterialBuilder.h"
#include "Hedgehog/Needle/ShaderObject.h"
#include "Hedgehog/Needle/ShaderMaterialContainer.h"
#include "Hedgehog/Needle/ShaderMaterialInstanceContainer.h"
#include "Hedgehog/Needle/PredicationObjectContainer.h"
#include "Hedgehog/Needle/PostEffectShader.h"
#include "Hedgehog/Needle/ModelInstance.h"
#include "Hedgehog/Needle/PBRModelInstance.h"
#include "Hedgehog/Needle/RenderingCommandList.h"
#include "Hedgehog/Needle/DisplaySwapDevice.h"
#include "Hedgehog/Needle/ShaderListInfo.h"
#include "Hedgehog/Needle/AnimController.h"

#include "Hedgehog/Needle/NeedleResContainer.h"
#include "Hedgehog/Needle/SceneParamContainer.h"
#include "Hedgehog/Needle/RenderProperty.h"
#include "Hedgehog/Needle/RenderingDeviceContext.h"
#include "Hedgehog/Needle/RenderingDevice.h"
#include "Hedgehog/Needle/SyncDrawContext.h"
#include "Hedgehog/Needle/RenderingContextManager.h"
#include "Hedgehog/Needle/RenderTargetManager.h"
#include "Hedgehog/Needle/RenderManager.h"
#include "Hedgehog/Needle/PrimitiveRenderer.h"
#include "Hedgehog/Needle/FxCamera.h"
#include "Hedgehog/Needle/Renderable.h"
#include "Hedgehog/Needle/ParamBuildJob.h"
#include "Hedgehog/Needle/GatherDrawPassInfoJob.h"
#include "Hedgehog/Needle/RenderJob.h"
#include "Hedgehog/Needle/CallbackJob.h"
#include "Hedgehog/Needle/ModelRenderJobBase.h"
#include "Hedgehog/Needle/ModelParamBuildJob.h"
#include "Hedgehog/Needle/DefaultModelRenderJob.h"
#include "Hedgehog/Needle/DeferredRenderJob.h"
#include "Hedgehog/Needle/DefaultDeferredRenderJob.h"
#include "Hedgehog/Needle/ModifiedCamera.h"
#include "Hedgehog/Needle/PostEffectRenderJob.h"
#include "Hedgehog/Needle/PostEffectPipelineJob.h"
#include "Hedgehog/Needle/PostEffectLitePipelineJob.h"
#include "Hedgehog/Needle/OcclusionCullingViewJob.h"
#include "Hedgehog/Needle/GatherDrawPassShadowMapJob.h"
#include "Hedgehog/Needle/ShadowMapParamBuildJob.h"
#include "Hedgehog/Needle/CachedShadowMapRenderJob.h"
#include "Hedgehog/Needle/SebastienSky.h"
#include "Hedgehog/Needle/SceneContext.h"
#include "Hedgehog/Needle/SceneContextManager.h"
#include "Hedgehog/Needle/SupportFX.h"
#include "Hedgehog/Needle/MaterialObjectContainer.h"
#include "Hedgehog/Needle/RenderingPipeline.h"
#include "Hedgehog/Needle/GatherRenderingPassContext.h"
#include "Hedgehog/Needle/GlobalParameterBuilder.h"
#include "Hedgehog/Needle/IRenderMeshHelper.h"
#include "Hedgehog/Needle/ModelRenderMeshHelper.h"
#include "Hedgehog/Needle/WorldRenderingPipeline.h"
#include "Hedgehog/Needle/WorldRenderingPipelineExecContext.h"
#include "Hedgehog/Needle/RenderingPipelineRangers.h"
#include "Hedgehog/Needle/RenderUnit.h"
#include "Hedgehog/Needle/RenderTexturePipeline.h"
#include "Hedgehog/Needle/RenderTexture.h"
#include "Hedgehog/Needle/RenderableRenderJob.h"
#include "Hedgehog/Needle/SceneContexts/SCAtmosphere.h"
#include "Hedgehog/Needle/SceneContexts/SCAtmosphericFog.h"
#include "Hedgehog/Needle/SceneContexts/SCColorGradingLUT.h"
#include "Hedgehog/Needle/SceneContexts/SCDebugPrimitive.h"
#include "Hedgehog/Needle/SceneContexts/SCDecal.h"
#include "Hedgehog/Needle/SceneContexts/SCDensity.h"
#include "Hedgehog/Needle/SceneContexts/SCDent.h"
#include "Hedgehog/Needle/SceneContexts/SCEnvironment.h"
#include "Hedgehog/Needle/SceneContexts/SCGlobalLight.h"
#include "Hedgehog/Needle/SceneContexts/SCIBL.h"
#include "Hedgehog/Needle/SceneContexts/SCInteractionCompute.h"
#include "Hedgehog/Needle/SceneContexts/SCInteractionWave.h"
#include "Hedgehog/Needle/SceneContexts/SCLightField.h"
#include "Hedgehog/Needle/SceneContexts/SCLocalLight.h"
#include "Hedgehog/Needle/SceneContexts/SCOcclusionCapsule.h"
#include "Hedgehog/Needle/SceneContexts/SCPostEffectResource.h"
#include "Hedgehog/Needle/SceneContexts/SCPostEffectVolume.h"
#include "Hedgehog/Needle/SceneContexts/SCRenderable.h"
#include "Hedgehog/Needle/SceneContexts/SCSkyCube.h"
#include "Hedgehog/Needle/SceneContexts/SCTerrain.h"
#include "Hedgehog/Needle/SceneContexts/SCWindCompute.h"
#include "Hedgehog/Needle/SceneContexts/SCWorld.h"
#include "Hedgehog/Needle/IBLParamBuildJob.h"

#include "Hedgehog/Needle/ImplDX11/Types.h"
#include "Hedgehog/Needle/ImplDX11/NeedleResourceContainer.h"
// #include "Hedgehog/Needle/ImplDX11/SDevStatus.h"
#include "Hedgehog/Needle/ImplDX11/CmdNeedleRefcountObject.h"
#include "Hedgehog/Needle/ImplDX11/MemoryLayoutContext.h"
#include "Hedgehog/Needle/ImplDX11/TextureDX11Impl.h"
#include "Hedgehog/Needle/ImplDX11/BufferDX11Impl.h"
#include "Hedgehog/Needle/ImplDX11/ShaderDX11Impl.h"
#include "Hedgehog/Needle/ImplDX11/VertexLayoutImpl.h"
#include "Hedgehog/Needle/ImplDX11/SMeshBuildCommonInfo.h"
#include "Hedgehog/Needle/ImplDX11/ShaderMaterialContainerDX11Impl.h"
#include "Hedgehog/Needle/ImplDX11/ShaderMaterialInstanceContainerDX11Impl.h"
#include "Hedgehog/Needle/ImplDX11/PredicationObjectContainerDX11.h"
#include "Hedgehog/Needle/ImplDX11/SResourceInfo.h"
#include "Hedgehog/Needle/ImplDX11/SResourceContext.h"
#include "Hedgehog/Needle/ImplDX11/SShaderContext.h"
#include "Hedgehog/Needle/ImplDX11/DevicUniqueObjectContainerDX11.h"
#include "Hedgehog/Needle/ImplDX11/SFlushParameterContext.h"
#include "Hedgehog/Needle/ImplDX11/StatusCacheOneStage.h"
#include "Hedgehog/Needle/ImplDX11/SParameterQueue.h"
#include "Hedgehog/Needle/ImplDX11/SParameterBuffer.h"
#include "Hedgehog/Needle/ImplDX11/RenderingDeviceDispatchDX11.h"
#include "Hedgehog/Needle/ImplDX11/GpuTimer.h"
#include "Hedgehog/Needle/ImplDX11/PerfDiagnostics.h"
#include "Hedgehog/Needle/ImplDX11/DeviceObjectDX11.h"
#include "Hedgehog/Needle/ImplDX11/RenderingDeviceContextDX11.h"
#include "Hedgehog/Needle/ImplDX11/RenderingDeviceDX11.h"
#include "Hedgehog/Needle/ImplDX11/DisplaySwapDeviceDX11.h"

#include "Cyan/System/IAllocator.h"
#include "Cyan/System/ArrayAllocator.h"
#include "Cyan/System/FreeListAllocator.h"
#include "Cyan/System/Random.h"
#include "Cyan/System/RandomTable.h"
#include "Cyan/System/AnimCtrl.h"
#include "Cyan/System/Job.h"
#include "Cyan/System/FSM.h"
#include "Cyan/Resource/Effect.h"
#include "Cyan/Resource/EffectParam.h"
#include "Cyan/Resource/Model.h"
#include "Cyan/Resource/NodeAnim.h"
#include "Cyan/Resource/ResObject.h"
#include "Cyan/Resource/Shader.h"
#include "Cyan/Resource/Skeleton.h"
#include "Cyan/Resource/Texture.h"
#include "Cyan/Graphics/DeviceContainer.h"
#include "Cyan/Graphics/ExternalMeshInstance.h"
#include "Cyan/Graphics/Renderer.h"
#include "Cyan/Graphics/MeshRenderer.h"
#include "Cyan/Graphics/ExternalMeshRenderer.h"
#include "Cyan/GPUTextureBuilder.h"
#include "Cyan/Utilities.h"
#include "Cyan/InheritChildParam.h"
#include "Cyan/NotifyData.h"
#include "Cyan/Effect.h"
#include "Cyan/Emitter.h"
#include "Cyan/Scene.h"
#include "Cyan/Manager.h"

#include "Hedgehog/GraphicsFoundation/ResTexture.h"
#include "Hedgehog/GraphicsFoundation/ResVertexShader.h"
#include "Hedgehog/GraphicsFoundation/ResFragmentShader.h"
#include "Hedgehog/GraphicsFoundation/ResComputeShader.h"
#include "Hedgehog/GraphicsFoundation/Renderable.h"
#include "Hedgehog/GraphicsFoundation/RenderableContainer.h"
#include "Hedgehog/GraphicsFoundation/ViewportData.h"
#include "Hedgehog/GraphicsFoundation/SharedDebugDrawResource.h"
#include "Hedgehog/GraphicsFoundation/SharedDebugDrawResourceNeedle.h"
#include "Hedgehog/GraphicsFoundation/DrawContext.h"
#include "Hedgehog/GraphicsFoundation/DrawContextNeedle.h"
#include "Hedgehog/GraphicsFoundation/GraphicsGeometry.h"
#include "Hedgehog/GraphicsFoundation/GraphicsGeometryNeedle.h"
#include "Hedgehog/GraphicsFoundation/GraphicsContext.h"
#include "Hedgehog/GraphicsFoundation/DrawSystem.h"
#include "Hedgehog/GraphicsFoundation/DrawSystemNeedle.h"

#include "Hedgehog/Font/ResBitmapFont.h"
#include "Hedgehog/Font/ResScalableFontSet.h"
#include "Hedgehog/Font/TextListener.h"
#include "Hedgehog/Font/FontContainer.h"

#include "Hedgehog/User/UserInfoEvent.h"
#include "Hedgehog/User/UserService.h"

// Hedgehog Framework
#include "Hedgehog/Framework/FrameworkConfig.h"
#include "Hedgehog/Framework/FrameworkOptions.h"
#include "Hedgehog/Framework/LocalHeap.h"
#include "Hedgehog/Framework/EventStack.h"
#include "Hedgehog/Framework/Window.h"
#include "Hedgehog/Framework/WindowD3D11.h"
#include "Hedgehog/Framework/FrameworkEnvironment.h"
#include "Hedgehog/Framework/BaseFramework.h"
#include "Hedgehog/Framework/FrameworkWin32.h"
#include "Hedgehog/Framework/Framework.h"
#include "Hedgehog/Framework/AppModule.h"
#include "Hedgehog/Framework/Application.h"
#include "Hedgehog/Framework/SaveManagerInterface.h"

// HID
#include "Hedgehog/HID/InputDevice.h"
#include "Hedgehog/HID/InputDeviceFactory.h"
#include "Hedgehog/HID/ActiveDeviceManager.h"
#include "Hedgehog/HID/InputMap.h"

#include "Hedgehog/HID/InputDevices/Keyboard.h"
#include "Hedgehog/HID/InputDevices/KeyboardWin32.h"
#include "Hedgehog/HID/InputDevices/Mouse.h"
#include "Hedgehog/HID/InputDevices/MouseWin32.h"
#include "Hedgehog/HID/InputDevices/Gamepad.h"
#include "Hedgehog/HID/InputDevices/GamepadSteam.h"
#include "Hedgehog/HID/InputDevices/Pointing.h"
#include "Hedgehog/HID/InputDevices/PointingWin32.h"
#include "Hedgehog/HID/InputDevices/Vibration.h"
#include "Hedgehog/HID/InputDevices/VibrationWin32.h"

#include "Hedgehog/HID/DeviceManager.h"
#include "Hedgehog/HID/DeviceManagerWin32.h"

// // // System Messages
// // #include "System/Messages/MsgRobChaosEmerald.h"

#include "Hedgehog/Debug/Messages.h"
#include "Hedgehog/Debug/ViewerContext.h"
#include "Hedgehog/Debug/Viewer.h"
#include "Hedgehog/Debug/ViewerContextManager.h"
#include "Hedgehog/Debug/ViewerManager.h"

// Hedgehog Game Library
#include "Hedgehog/Game/GameService.h"
#include "Hedgehog/Game/GameObject.h"
#include "Hedgehog/Game/GameObjectLayer.h"
#include "Hedgehog/Game/GOComponent.h"
#include "Hedgehog/Game/GameManager.h"
#include "Hedgehog/Game/GameJobQueue.h"
#include "Hedgehog/Game/GameUpdater.h"
#include "Hedgehog/Game/BucketedGameUpdater.h"
#include "Hedgehog/Game/GameApplication.h"
#include "Hedgehog/Game/InputManager.h"
#include "Hedgehog/Game/InputComponent.h"
#include "Hedgehog/Game/CameraComponent.h"
#include "Hedgehog/Game/CameraManager.h"
#include "Hedgehog/Game/ResLevel.h"
#include "Hedgehog/Game/Level.h"
#include "Hedgehog/Game/MasterLevel.h"
#include "Hedgehog/Game/LevelManager.h"
#include "Hedgehog/Game/LevelLoader.h"
#include "Hedgehog/Game/ObjInfo.h"
#include "Hedgehog/Game/ObjInfoContainer.h"
#include "Hedgehog/Game/GameObjectRegistry.h"
#include "Hedgehog/Game/GOComponentRegistry.h"
#include "Hedgehog/Game/ObjInfoRegistry.h"
#include "Hedgehog/Game/GameObjectSystem.h"
#include "Hedgehog/Game/ErrorViewer.h"
#include "Hedgehog/Game/GameViewerContext.h"
#include "Hedgehog/Game/ObjectViewerContext.h"
#include "Hedgehog/Game/ServiceViewerContextBase.h"
#include "Hedgehog/Game/GameViewerBase.h"
#include "Hedgehog/Game/MousePickingViewer.h"
#include "Hedgehog/Game/ResObjectWorld.h"
#include "Hedgehog/Game/ObjectMap.h"
#include "Hedgehog/Game/ObjectDataAccessor.h"
#include "Hedgehog/Game/WorldObjectStatus.h"
#include "Hedgehog/Game/ObjectWorldChunk.h"
#include "Hedgehog/Game/ObjectWorldChunkLayer.h"
#include "Hedgehog/Game/ObjectWorldChunk.def.h"
#include "Hedgehog/Game/ObjectWorldExtension.h"
#include "Hedgehog/Game/ObjectWorld.h"

#include "Hedgehog/Game/GOComponents/GOCInput.h"
#include "Hedgehog/Game/GOComponents/GOCTransform.h"
#include "Hedgehog/Game/GOComponents/GOCActivator.h"

#include "Hedgehog/Game/DevMenu/Menu.h"
#include "Hedgehog/Game/FreeCamera.h"

#include "Hedgehog/Game/Stats/StatsListener.h"

#include "Hedgehog/GraphicsFoundation/RenderManagerBase.h"

#include "Hedgehog/Graphics/NeedleRenderer.h"
#include "Hedgehog/Graphics/RenderingWorld.h"
#include "Hedgehog/Graphics/RenderingComponent.h"
#include "Hedgehog/Graphics/Components/CriComponent.h"
#include "Hedgehog/Graphics/Components/LightComponent.h"
#include "Hedgehog/Graphics/Components/CaptureComponent.h"
#include "Hedgehog/Graphics/Components/ScreenShotComponent.h"
#include "Hedgehog/Graphics/RenderingEngine.h"
#include "Hedgehog/Graphics/RenderingEngineNeedle.h"
#include "Hedgehog/Graphics/RenderingEngineRangers.h"
#include "Hedgehog/Graphics/DynamicResolutionController.h"
#include "Hedgehog/Graphics/DefaultDynamicResolutionController.h"
#include "Hedgehog/Graphics/RenderManager.h"
#include "Hedgehog/Graphics/VertexAnimationTextureController.h"
#include "Hedgehog/Graphics/ResDensitySetting.h"
#include "Hedgehog/Graphics/ResMaterial.h"
#include "Hedgehog/Graphics/ResModelParameterInterface.h"
#include "Hedgehog/Graphics/ResModelBase.h"
#include "Hedgehog/Graphics/ResModelNeedle.h"
#include "Hedgehog/Graphics/ResModel.h"
#include "Hedgehog/Graphics/ResTerrainModel.h"
#include "Hedgehog/Graphics/ResModelInstanceInfo.h"
#include "Hedgehog/Graphics/ResMirageTerrainInstanceInfo.h"
#include "Hedgehog/Graphics/ResMirageLight.h"
#include "Hedgehog/Graphics/ResMirageLightField.h"
#include "Hedgehog/Graphics/ResProbe.h"
#include "Hedgehog/Graphics/ResDecal.h"
#include "Hedgehog/Graphics/ResVertexAnimationTexture.h"
#include "Hedgehog/Graphics/ResPointcloud.h"
#include "Hedgehog/Graphics/ResOcclusionCapsule.h"
#include "Hedgehog/Graphics/GOCVisual.h"
#include "Hedgehog/Graphics/GOCVisualTransformed.h"
#include "Hedgehog/Graphics/GOCVisualModel.h"
#include "Hedgehog/Graphics/GOCVisualUserModel.h"
#include "Hedgehog/Graphics/GOCVisualDebugDraw.h"
#include "Hedgehog/Graphics/GOCRenderTexture.h"
#include "Hedgehog/Graphics/GOCOcclusionCapsule.h"
#include "Hedgehog/Graphics/ModelNodeHFrame.h"
#include "Hedgehog/Graphics/VisualManager.h"
#include "Hedgehog/Graphics/VisibilityManager.h"
#include "Hedgehog/Graphics/FxParamEditor.h"

#include "Hedgehog/Physics/ShapeHolder.h"
#include "Hedgehog/Physics/EventQueue.h"
#include "Hedgehog/Physics/GOCCollider.h"
#include "Hedgehog/Physics/GOCSphereCollider.h"
#include "Hedgehog/Physics/GOCBoxCollider.h"
#include "Hedgehog/Physics/GOCCapsuleCollider.h"
#include "Hedgehog/Physics/GOCCylinderCollider.h"
#include "Hedgehog/Physics/GOCMeshCollider.h"
#include "Hedgehog/Physics/PhysicsWorld.h"
#include "Hedgehog/Physics/PhysicsWorldBullet.h"
#include "Hedgehog/Physics/PhysicsQueryJob.h"
#include "Hedgehog/Physics/PhysicsRaycastJob.h"
#include "Hedgehog/Physics/PhysicsViewerContext.h"
#include "Hedgehog/Physics/PhysicsViewerBase.h"
#include "Hedgehog/Physics/PhysicsMousePickingViewer.h"
#include "Hedgehog/Physics/PhysicsPickedObjectViewer.h"
#include "Hedgehog/Physics/BulletPhysicsModule.h"
#include "Hedgehog/Physics/Messages.h"

#include "Hedgehog/Path/ResPathObject.h"
#include "Hedgehog/Path/PathComponent.h"
#include "Hedgehog/Path/PathCollisionHandler.h"
#include "Hedgehog/Path/PathManager.h"
#include "Hedgehog/Path/PathEvaluator.h"

#include "Hedgehog/Effect/CyanRenderHandler.h"
#include "Hedgehog/Effect/ResEffect.h"
#include "Hedgehog/Effect/EffectManager.h"
#include "Hedgehog/Effect/GOCEffect.h"

#include "Hedgehog/Sound/ResAtomConfig.h"
#include "Hedgehog/Sound/ResAtomCueSheet.h"
#include "Hedgehog/Sound/SoundHandle.h"
#include "Hedgehog/Sound/SoundManager.h"
#include "Hedgehog/Sound/SoundManagerCri.h"
#include "Hedgehog/Sound/GOCSound.h"

#include "Hedgehog/Text/ResText.h"
#include "Hedgehog/Text/ResTextMeta.h"
#include "Hedgehog/Text/ResTextProject.h"

#include "Hedgehog/Animation/Trigger.h"
#include "Hedgehog/Animation/Bindable.h"
#include "Hedgehog/Animation/BindableCollection.h"
#include "Hedgehog/Animation/SkeletalMeshBinding.h"
#include "Hedgehog/Animation/SkeletonBlender.h"
#include "Hedgehog/Animation/ResSkeleton.h"
#include "Hedgehog/Animation/ResSkeletonPxd.h"
#include "Hedgehog/Animation/ResAnimation.h"
#include "Hedgehog/Animation/ResAnimationPxd.h"
#include "Hedgehog/Animation/ResAnimator.h"
#include "Hedgehog/Animation/AsmResourceManager.h"
#include "Hedgehog/Animation/AnimationControl.h"
#include "Hedgehog/Animation/AnimationControlPxd.h"
#include "Hedgehog/Animation/SkeletonControl.h"
#include "Hedgehog/Animation/AsmControlCreator.h"
#include "Hedgehog/Animation/TransitionEffect.h"
#include "Hedgehog/Animation/BlendingTransitionEffect.h"
#include "Hedgehog/Animation/AnimationState.h"
#include "Hedgehog/Animation/BlendTreeSyncContext.h"
#include "Hedgehog/Animation/BlendNode.h"
#include "Hedgehog/Animation/Calc.h"
#include "Hedgehog/Animation/IkInfo.h"
#include "Hedgehog/Animation/IkSolver.h"
#include "Hedgehog/Animation/ResCharacterIk.h"
#include "Hedgehog/Animation/RaycastInterface.h"
#include "Hedgehog/Animation/AnimationInternalState.h"
#include "Hedgehog/Animation/AnimationStateMachine.h"
#include "Hedgehog/Animation/GOCAnimation.h"
#include "Hedgehog/Animation/GOCAnimationSingle.h"
#include "Hedgehog/Animation/GOCAnimationSimple.h"
#include "Hedgehog/Animation/GOCAnimationBlend.h"
#include "Hedgehog/Animation/GOCAnimator.h"
#include "Hedgehog/Animation/GOCCharacterIk.h"
#include "Hedgehog/Animation/AnimationManager.h"
#include "Hedgehog/Animation/AnimationInterface.h"

#include "Hedgehog/AnimationEffect/ResParticleLocation.h"
#include "Hedgehog/AnimationEffect/GOCParticleLocator.h"

#include "SurfRide/Types.h"
#include "SurfRide/Allocator.h"
#include "SurfRide/Base.h"
#include "SurfRide/ReferencedObject.h"
#include "SurfRide/UserData.h"
#include "SurfRide/Textures/Crop.h"
#include "SurfRide/Textures/Texture.h"
#include "SurfRide/Textures/TextureData.h"
#include "SurfRide/Textures/TextureList.h"
#include "SurfRide/Transform.h"
#include "SurfRide/Cell.h"
#include "SurfRide/Text.h"
#include "SurfRide/Camera.h"
#include "SurfRide/Effects/Blur.h"
#include "SurfRide/Effects/Reflect.h"
#include "SurfRide/Casts/Cast.h"
#include "SurfRide/Casts/ImageCast.h"
#include "SurfRide/Casts/ReferenceCast.h"
#include "SurfRide/Casts/SliceCast.h"
#include "SurfRide/Layer.h"
#include "SurfRide/Scene.h"
#include "SurfRide/Project.h"
#include "SurfRide/Calc.h"
#include "SurfRide/BinaryData.h"

#include "Hedgehog/Text/ConverseTextListener.h"
#include "Hedgehog/Text/ConverseData.h"
#include "Hedgehog/Text/ConverseDataCollection.h"
#include "Hedgehog/Text/TagReplaceable.h"
#include "Hedgehog/Text/TagReplaceableCollection.h"
#include "Hedgehog/Text/TagReplacer.h"
#include "Hedgehog/Text/TextLanguageData.h"
#include "Hedgehog/Text/TextLanguageDataCollection.h"
#include "Hedgehog/Text/TextAppModule.h"

#include "Hedgehog/UI/SurfRideTextureDataMIRAGE.h"
#include "Hedgehog/UI/ResSurfRideProject.h"
#include "Hedgehog/UI/SurfRideProjectContext.h"
#include "Hedgehog/UI/SurfRideHandle.h"
#include "Hedgehog/UI/Types.h"
#include "Hedgehog/UI/GOCSprite.h"
#include "Hedgehog/UI/LayerController.h"
#include "Hedgehog/UI/TextListenerObject.h"
#include "Hedgehog/UI/UITextInterface.h"
#include "Hedgehog/UI/TextObjectUpdater.h"
#include "Hedgehog/UI/GOCUICollider.h"
#include "Hedgehog/UI/GOCUIComposition.h"
#include "Hedgehog/UI/UIObject.h"
#include "Hedgehog/UI/UIElementBase.h"
#include "Hedgehog/UI/UIElement.h"
#include "Hedgehog/UI/UIElementGroup.h"
#include "Hedgehog/UI/UIElementGroupContainer.h"
#include "Hedgehog/UI/UITextElement.h"
#include "Hedgehog/UI/CastTextContainer.h"
#include "Hedgehog/UI/UIPanel.h"
#include "Hedgehog/UI/UIStackPanel.h"
#include "Hedgehog/UI/UIGridPanel.h"
#include "Hedgehog/UI/UIScrollBarElement.h"
#include "Hedgehog/UI/UIListViewElement.h"
#include "Hedgehog/UI/UIListener.h"
#include "Hedgehog/UI/UIManager.h"

#include "Hedgehog/Dv/DiEventManager.h"
#include "Hedgehog/Dv/DiEventPreviewManager.h"
#include "Hedgehog/Dv/DvSceneControl.h"

// #include "System/Player/PlayerInformation.h"
// #include "System/Player/Blackboard.h"
// #include "System/Player/BlackboardBattle.h"
// #include "System/Player/Player.h"
// #include "System/Player/Sonic.h"


// // System Game Object Components
// #include "System/Player/goc/goc_PlayerBlackboard.h"
// #include "System/Player/goc/goc_PlayerKinematicParams.h"

// #include "System/AppResourceManagerListener.h"

// // Save
// #include "System/Save/SaveManagerListener.h"

// // Services
// #include "System/Services/service_LevelInfo.h"
// #include "System/Services/service_PhotoMode.h"
// #include "System/Services/service_UIOverlay.h"

// // HUD
// #include "System/HUD/RequestOverlayBegin.h"
// #include "System/HUD/RequestOverlayTagReplace.h"
// #include "System/HUD/RequestOverlayCaption.h"

// #include "System/Script/ScriptSequence.h"

// Builtin RflCustomAttributes
// #include "ApplicationCommon/Reflection/CaptionAttribute.h"
// #include "ApplicationCommon/Reflection/RangeAttribute.h"
#include "ApplicationCommon/Reflection/GOCRflParameter.h"

#include "ApplicationCommon/FSM/GOCTinyFsm2.h"
#include "ApplicationCommon/FSM/GOCHsm2.h"

#include "ApplicationCommon/Camera/Types.h"
#include "ApplicationCommon/Camera/CameraExtension.h"
#include "ApplicationCommon/Camera/CameraController.h"
#include "ApplicationCommon/Camera/CameraInterpolator.h"
#include "ApplicationCommon/Camera/CameraFrame.h"
#include "ApplicationCommon/Camera/GOCCamera.h"
#include "ApplicationCommon/Camera/Messages.h"

#include "ApplicationCommon/Game/GOCMotor.h"
#include "ApplicationCommon/Game/GOCMotorConstant.h"
#include "ApplicationCommon/Game/GOCMotorRotate.h"
#include "ApplicationCommon/Game/GOCMotorOnPath.h"

#include "Application/Utilities/PriorityList.h"
#include "Application/Utilities/SendMessage.h"
#include "Application/Utilities/TransitionValue.h"

#include "Application/Foundation/AppHeapManager.h"
#include "Application/Foundation/AppMessage.h"

#include "Application/FSM/StateContext.h"

#include "Application/Resource/AppResourceManager.h"

#include "Application/Save/SaveDataLock.h"
#include "Application/Save/SaveDataAccessor.h"
#include "Application/Save/Accessors.h"
#include "Application/Save/UserElement.h"
#include "Application/Save/SaveDataLockImpl.h"
#include "Application/Save/SaveInterface.h"
#include "Application/Save/SaveManager.h"

#include "Application/Camera/CameraBridge.h"
#include "Application/Camera/CameraService.h"

#include "Application/Player/CharacterId.h"
#include "Application/Player/PlayerCounterTimer.h"
#include "Application/Player/PlayerHsmContext.h"
#include "Application/Player/Blackboard/BlackboardContent.h"
#include "Application/Player/Blackboard/BlackboardAmy.h"
#include "Application/Player/Blackboard/BlackboardSpeed.h"
#include "Application/Player/Blackboard/BlackboardItem.h"
#include "Application/Player/Blackboard/BlackboardBattle.h"
#include "Application/Player/Blackboard/BlackboardStatus.h"
#include "Application/Player/Blackboard/BlackboardTails.h"
#include "Application/Player/Blackboard/Blackboard.h"
#include "Application/Player/Blackboard/GOCPlayerBlackboard.h"
#include "Application/Player/StateParameter.h"
#include "Application/Player/RelayedFlagsParameter.h"
#include "Application/Player/PlayerStateParameter.h"
#include "Application/Player/StatePlugin/StatePlugin.h"
#include "Application/Player/StatePlugin/StatePluginManager.h"
#include "Application/Player/StatePlugin/StatePluginBoost.h"
#include "Application/Player/StatePlugin/StatePluginCyberStart.h"
#include "Application/Player/GravityController.h"
#include "Application/Player/GOCPlayerHsm.h"
#include "Application/Player/GOCPlayerState.h"
#include "Application/Player/GOCPlayerParameter.h"
#include "Application/Player/GOCPlayerKinematicParams.h"
#include "Application/Player/PlayerCollision.h"
#include "Application/Player/PlayerController.h"
#include "Application/Player/GOCPlayerCollider.h"
#include "Application/Player/ComponentCollector.h"
#include "Application/Player/PlayerEffect.h"
#include "Application/Player/EffectList.h"
#include "Application/Player/VisualLocator.h"
#include "Application/Player/VisualLocatorNormal.h"
#include "Application/Player/VisualLocatorManager.h"
#include "Application/Player/PlayerVisual.h"
#include "Application/Player/VisualHuman.h"
#include "Application/Player/GOCPlayerEffect.h"
#include "Application/Player/GOCPlayerVisual.h"
#include "Application/Player/PlayerStateBase.h"
#include "Application/Player/States.h"
#include "Application/Player/PlayerStateBase.h"
#include "Application/Player/Messages.h"

#include "Application/Player/Player.h"
#include "Application/Player/PlayerRaycastInterface.h"
#include "Application/Player/Characters/VisualSonic.h"
#include "Application/Player/Characters/SonicInfo.h"
#include "Application/Player/Characters/Sonic.h"
#include "Application/Player/Characters/Tails.h"
#include "Application/Player/Characters/VisualAmy.h"
#include "Application/Player/Characters/Amy.h"
#include "Application/Player/Characters/Knuckles.h"

#include "Application/Level/PlayerInformation.h"
#include "Application/Level/StageData.h"
#include "Application/Level/StageInfo.h"
#include "Application/Level/LevelInfo.h"
#include "Application/Level/ResMasterLevel.h"

#include "Application/Event/EventPlayer.h"

#include "Application/Sound/SoundDirector.h"
#include "Application/Sound/BgmIdExtension.h"
#include "Application/Sound/AmbSoundCoordinator.h"
#include "Application/Sound/AmbientSoundExtension.h"
#include "Application/Sound/CustomSound.h"

#include "Application/Text/AppTextListener.h"
#include "Application/Text/TextManager.h"

#include "Application/UI/AppUITextInterface.h"
#include "Application/UI/UIMusicSelect.h"
#include "Application/UI/RequestOverlayTagReplace.h"
#include "Application/UI/RequestOverlayBegin.h"
#include "Application/UI/RequestOverlayWindow.h"
#include "Application/UI/RequestOverlayCaption.h"
#include "Application/UI/UIOverlayService.h"
#include "Application/UI/Messages.h"

#include "Application/Game/Helpers.h"
#include "Application/Game/GameCondition.h"
#include "Application/Game/GameModeResourceModule.h"
#include "Application/Game/StageTerrainModule.h"
#include "Application/Game/StageObjectModule.h"
#include "Application/Game/GameModeResourceManager.h"
#include "Application/Game/GameMode.h"
#include "Application/Game/GameModeStage.h"
#include "Application/Game/GameModeExtension.h"
#include "Application/Game/GameModeLayerStatusExtension.h"
#include "Application/Game/Timestamp.h"
#include "Application/Game/TimeService.h"
#include "Application/Game/WeatherService.h"
#include "Application/Game/RespawnTimeManager.h"
#include "Application/Game/MonologueService.h"
#include "Application/Game/IslandRangeSpawningManager.h"
#include "Application/Game/ApplicationExtension.h"
#include "Application/Game/ApplicationSequenceExtension.h"
#include "Application/Game/MenuSelect.h"
#include "Application/Game/ResAIStateMachine.h"
#include "Application/Game/GOCEvent.h"
#include "Application/Game/GOCEventCollision.h"
#include "Application/Game/GOCActionNotifier.h"
#include "Application/Game/GOCCyloopPoint.h"
#include "Application/Game/GOCAI.h"
#include "Application/Game/GrindModelUpdater.h"
#include "Application/Game/GOCGrind.h"
#include "Application/Game/GOCLookAt.h"
#include "Application/Game/Messages.h"
#include "Application/Game/Posture.h"

#include "Application/Physics/GOCColliderQuery.h"
#include "Application/Physics/GOCMoveSphereColliderQuery.h"

#include "Application/Graphics/ResFxColFile2.h"
#include "Application/Graphics/SceneParameters.h"
#include "Application/Graphics/FxParamManager.h"
#include "Application/Graphics/FxParamTimeProgressExtension.h"
#include "Application/Graphics/FxColManager.h"

#include "Application/ResSvCol2.h"
#include "Application/Terrain/TerrainLoaderDynamic.h"
#include "Application/Terrain/TerrainManager.h"
#include "Application/Terrain/TerrainWorld.h"
#include "Application/Terrain/TerrainVisualResourceBinder.h"
#include "Application/Terrain/TerrainVisualObject.h"
#include "Application/Terrain/TerrainVisualCreator.h"
#include "Application/Terrain/TerrainGround.h"
#include "Application/Terrain/TerrainSky.h"

#include "Application/DLC/DLCManager.h"

#include "Application/Player/PlayerPosture.h"
#include "Application/Player/Postures/PostureSliding.h"

#include "Application/VolumeTrigger.h"
#include "Application/MyApplication.h"
#include "Application/IslandObjInfo.h"
#include "Application/ObjSwitchVolume.h"
#include "Application/ObjCamera.h"
#include "Application/ObjCameraVolume.h"
#include "Application/MeteorShowerEffect.h"

namespace rangerssdk::ucsl {
    inline csl::fnd::IAllocator* AllocatorSystem::get_allocator() { return hh::fnd::MemoryRouter::GetModuleAllocator(); }
	struct GameInterface {
        using AllocatorSystem = AllocatorSystem;
		using RflSystem = ::ucsl::rfl::rangers;
		using RflClassNameRegistry = typename hh::fnd::RflClassNameRegistry;
		using RflTypeInfoRegistry = typename hh::fnd::RflTypeInfoRegistry;
		using GameObjectClass = typename hh::game::GameObjectClass;
		using GameObjectSystem = typename hh::game::GameObjectSystem;
		using GameObjectRegistry = typename hh::game::GameObjectRegistry;
		using GOComponentRegistry = typename hh::game::GOComponentRegistry;
	};
}

namespace hh::needle {
    class StaticIDsTemp {
    public:
        static hh::needle::CNameIDObjectStatic diffuse;
        static hh::needle::CNameIDObjectStatic diffuse1;
        static hh::needle::CNameIDObjectStatic diffuse2;
        static hh::needle::CNameIDObjectStatic diffuse3;

        static hh::needle::CNameIDObjectStatic ignoreLightDiffuse;
        static hh::needle::CNameIDObjectStatic ignoreLightDiffuseColor;
        static hh::needle::CNameIDObjectStatic ignoreLightAmbientColor;
        static hh::needle::CNameIDObjectStatic ignoreLightEmissiveColor;
        static hh::needle::CNameIDObjectStatic ignoreLightLuminance;

        static hh::needle::CNameIDObjectStatic commonDDiffuse;
        static hh::needle::CNameIDObjectStatic commonDDiffuseColor;
        static hh::needle::CNameIDObjectStatic commonDAmbientColor;
        static hh::needle::CNameIDObjectStatic commonDEmissiveColor;
    };
}

namespace heur {
    float RandomBetween(float min, float max);
}
