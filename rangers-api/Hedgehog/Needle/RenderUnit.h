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
        CNameIDObject* nameId;
        CNameIDObject* sceneNameId;
        WorldRenderingPipeline* pipeline;
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
        bool unk12;
        bool paramsInitialized;
        bool createSceneParamListeners;
        Unk1 unk14;
        uint32_t cameraId;
        WorldRenderingPipelineExecContext* renderingPipelineExecContext;
        uint8_t unk17;
        uint32_t unk18;
        uint32_t flags;

        RenderUnit(const char* name, SupportFXAll* supportFX, bool unk12Param);
        RenderUnit(const char* name, SupportFXAll* supportFX, bool unk12Param, uint32_t flags);
        void LoadGlobalParams();
        void SetPipeline(RenderingPipeline* pipeline);
        void SetSceneName(const char* name);

        virtual uint64_t UnkFunc1();
        virtual uint64_t UnkFunc2();
        virtual bool UnkFunc3() { return true; }
        virtual void UnkFunc4() {}
        virtual void UnkFunc5() {}
        virtual uint64_t UnkFunc6();
        virtual uint64_t UnkFunc7();
    };
}
