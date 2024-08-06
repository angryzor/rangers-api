#pragma once

namespace hh::needle {
    class GlobalParameterBuilder : public NeedleRefcountObject {
    public:
        unsigned int parameterCount;
        unsigned int unk2;
        unsigned int parameterSize;
        csl::ut::MoveArray<void*> unk4;
        csl::ut::MoveArray<SGlobalParameterSceneSetting> globalParameterSceneSettings;

        GlobalParameterBuilder(csl::fnd::IAllocator* allocator, unsigned int parameterCount, unsigned int parameterSize, unsigned int unk2Param);
    };
}
