#pragma once

namespace hh::needle {
    class GlobalParameterBuilder;
    class PipelineInfo : public NeedleObject {
    public:
        uint32_t dword8;
        uint64_t qword10;
        uint64_t qword18;
        uint64_t qword20;
        SupportFX::FxRenderParam renderParam;
        SupportFXAll* supportFX;
        uint64_t qword138;
        GlobalParameterBuilder* globalParameterBuilder;
        uint64_t qword148;
        uint64_t qword150;
        CNameIDObject* renderUnitNameId;
        CNameIDObject* sceneNameId;
        uint32_t cameraId;
        SceneParamContainer* sceneParamContainer;
        uint64_t qword178;
        uint64_t qword180;
        uint32_t dword188;
        RenderUnit* renderUnit;
        uint64_t qword198;
        uint64_t qword1A0;

        PipelineInfo(CNameIDObject* renderUnitNameId);

        virtual uint64_t UnkFunc1();
    };

    class RenderingPipeline : public NeedleRefcountObject {
    public:
        csl::ut::MoveArray<void*> renderJobs;
        csl::fnd::IAllocator* allocator;
        const char* name;
        uint16_t unk2;

        RenderingPipeline(csl::fnd::IAllocator* allocator, const char* name);

        virtual uint64_t UnkFunc1();
        virtual uint64_t UnkFunc2();
        virtual uint64_t UnkFunc3() {}
        virtual uint64_t UnkFunc4();
        virtual uint64_t UnkFunc5();
        virtual uint64_t UnkFunc6();
        virtual uint64_t UnkFunc7();
        virtual uint64_t UnkFunc8();
        virtual uint64_t UnkFunc9() {}
        virtual uint64_t UnkFunc10();
        virtual uint64_t UnkFunc11() {}
        virtual uint64_t UnkFunc12() {}
    };
}
