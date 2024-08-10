#pragma once

namespace hh::needle {
    class SceneParamContainer;
    class RenderProperty : public NeedleObject {
    public:
        bool renderTargetMustBeRecreated;
        uint8_t unka1;
        uint32_t unk2;
        uint32_t unk3;
        uint64_t unk4;
        csl::ut::MoveArray<SceneParamContainer*> sceneParamContainers;

        RenderProperty(csl::fnd::IAllocator* allocator);
        virtual ~RenderProperty();

        void AddSceneParamContainer(SceneParamContainer* container);
    };
}
