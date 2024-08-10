#pragma once

namespace hh::needle {
    class RenderUnit : public NeedleRefcountObject {
    public:
        struct Unk1 {
            uint8_t unk1;
            uint8_t unk2;
            uint32_t frameCounter;
            csl::math::Matrix44 viewMatrices[2];
            csl::math::Matrix44 projectionMatrices[2];
            uint64_t unk4;
            uint64_t unk5;

            Unk1();
        };

        uint64_t unk1;
        uint64_t unk2;
        SupportFXAll* supportFX;
        intrusive_ptr<CNameIDObject> nameId;
        intrusive_ptr<CNameIDObject> sceneNameId;
        intrusive_ptr<WorldRenderingPipeline> pipeline;
        PipelineInfo* pipelineInfo;
        uint64_t unk6;
        uint64_t unk7;
        uint32_t unk8;
        uint32_t unk8b;
        uint64_t unk9;
        uint32_t unk10;
        uint32_t unk10b;
        uint64_t unk11;
        intrusive_ptr<SceneParamContainer> sceneParamContainer;
        uint8_t priority;
        bool paramsInitialized;
        bool createSceneParamListeners;
        Unk1 unk14;
        uint32_t cameraId;
        WorldRenderingPipelineExecContext* renderingPipelineExecContext;
        bool renders;
        uint32_t unk18;
        uint32_t flags;

        struct RenderInfo {
            SupportFX::FxRenderParam renderParam;
            RenderTarget* renderTarget;
        };

        RenderUnit(const char* name, SupportFXAll* supportFX, uint8_t priority);
        RenderUnit(const char* name, SupportFXAll* supportFX, uint8_t priority, uint32_t flags);
        ~RenderUnit() {
            if (renderingPipelineExecContext) delete renderingPipelineExecContext;
            if (pipelineInfo) delete pipelineInfo;
        }

        void LoadGlobalParams();
        void SetPipeline(RenderingPipeline* pipeline);
        void SetSceneName(const char* name);
        bool HasHigherPriority(const RenderUnit* other) const;

        virtual void Initialize();
        virtual void Deinitialize();
        virtual bool IsEnabled(const RenderInfo& renderInfo) { return true; }
        virtual void SetRenderDimensions(const RenderInfo& renderInfo) {}
        virtual void UnkFunc5() {}
        virtual void LoadRenderParams(const RenderInfo& renderInfo);
        virtual void Render();
    };
}
