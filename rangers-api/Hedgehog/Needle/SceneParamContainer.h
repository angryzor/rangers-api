#pragma once

namespace hh::needle {
    class RenderUnit;
    class SceneParamContainer : public NeedleRefcountObject {
    public:
        template<typename T>
        class ParamHolder : public NeedleObject {
        public:
            class Listener : public NeedleObject {
                RenderProperty* renderProperty;
            public:
                virtual ~Listener() = default;
                virtual void ParamChangedCallback(const T& previousValue, const T& newValue) = 0;
            };

            Listener* listener;
            bool isSet;
            T data;
        };

        csl::ut::PointerMap<CNameIDObject*, void*> params;
        RenderUnit* renderUnit;
        uint32_t unk1;

        void InitGlobalParams();
        void CreateGlobalParamListeners();

        template<typename T> ParamHolder<T>* GetSceneParam();
        template<> ParamHolder<FxBloomParameter>* GetSceneParam();
        template<> ParamHolder<FxDOFParameter>* GetSceneParam();
        template<> ParamHolder<FxColorContrastParameter>* GetSceneParam();
        template<> ParamHolder<FxToneMapParameter>* GetSceneParam();
        template<> ParamHolder<FxCameraControlParameter>* GetSceneParam();
        template<> ParamHolder<FxShadowMapParameter>* GetSceneParam();
        template<> ParamHolder<FxShadowHeightMapParameter>* GetSceneParam();
        template<> ParamHolder<FxVolumetricShadowParameter>* GetSceneParam();
        template<> ParamHolder<FxScreenBlurParameter>* GetSceneParam();
        template<> ParamHolder<FxSSAOParameter>* GetSceneParam();
        template<> ParamHolder<FxSHLightFieldParameter>* GetSceneParam();
        template<> ParamHolder<FxLightScatteringParameter>* GetSceneParam();
        template<> ParamHolder<FxRLRParameter>* GetSceneParam();
        template<> ParamHolder<FxSSGIParameter>* GetSceneParam();
        template<> ParamHolder<FxPlanarReflectionParameter>* GetSceneParam();
        template<> ParamHolder<FxOcclusionCapsuleParameter>* GetSceneParam();
        template<> ParamHolder<FxGodrayParameter>* GetSceneParam();
        template<> ParamHolder<FxScreenSpaceGodrayParameter>* GetSceneParam();
        template<> ParamHolder<FxHeatHazeParameter>* GetSceneParam();
        template<> ParamHolder<FxSceneEnvironmentParameter>* GetSceneParam();
        template<> ParamHolder<FxRenderOption>* GetSceneParam();
        template<> ParamHolder<FxSGGIParameter>* GetSceneParam();
        template<> ParamHolder<FxTAAParameter>* GetSceneParam();
        template<> ParamHolder<FxEffectParameter>* GetSceneParam();
        template<> ParamHolder<FxAtmosphereParameter>* GetSceneParam();
        template<> ParamHolder<FxDensityParameter>* GetSceneParam();
        template<> ParamHolder<FxWindComputeParameter>* GetSceneParam();
        template<> ParamHolder<FxGpuEnvironmentParameter>* GetSceneParam();
        template<> ParamHolder<FxInteractiveWaveParameter>* GetSceneParam();
        template<> ParamHolder<FxChromaticAberrationParameter>* GetSceneParam();
        template<> ParamHolder<FxVignetteParameter>* GetSceneParam();
        template<> ParamHolder<FxTerrainMaterialBlendingParameter>* GetSceneParam();
        template<> ParamHolder<FxWeatherParameter>* GetSceneParam();
        template<> ParamHolder<FxColorAccessibilityFilterParameter>* GetSceneParam();
        template<> ParamHolder<FxCyberNoiseEffectParameter>* GetSceneParam();
        template<> ParamHolder<FxCyberSpaceStartNoiseParameter>* GetSceneParam();
        template<> ParamHolder<FxCyberNPCSSEffectRenderParameter>* GetSceneParam();
        template<> ParamHolder<FxFieldScanEffectRenderParameter>* GetSceneParam();
        template<> ParamHolder<FxSeparableSSSParameter>* GetSceneParam();
    };
}
