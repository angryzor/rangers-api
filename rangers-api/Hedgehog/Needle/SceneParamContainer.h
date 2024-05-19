#pragma once

namespace hh::needle {
    class RenderUnit;
    class SceneParamContainer : public NeedleRefcountObject {
    public:
        csl::ut::PointerMap<CNameIDObject*, void*> params;
        RenderUnit* renderUnit;
        uint32_t unk1;

        void InitGlobalParams();
        void CreateGlobalParamListeners();
    };
}
