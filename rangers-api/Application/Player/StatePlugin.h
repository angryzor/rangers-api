#pragma once

namespace app::gfx {
    class SceneParameters;
}

namespace app::player {
    class StatePluginBase : public hh::fnd::ReferencedObject {
        // I currently don't have a way to know where in the hierarchy these belong...
        uint8_t unk1;
        uint8_t unk2;
        gfx::SceneParameters* sceneParameters;
    public:
        StatePluginBase(csl::fnd::IAllocator* allocator) : hh::fnd::ReferencedObject{ allocator, true } {}
    };

    template<typename Ctx>
    class StatePlugin : public StatePluginBase {
    public:
        StatePlugin(csl::fnd::IAllocator* allocator) : StatePluginBase{ allocator } {}
    };

    template<typename Ctx>
    class StatePluginManager : public hh::fnd::BaseObject {
        Ctx* context;
        csl::ut::MoveArray<hh::fnd::Reference<StatePlugin<Ctx>>> plugins;
        bool unk1;
    public:
        StatePluginManager(csl::fnd::IAllocator* allocator);
        static StatePluginManager* Create(csl::fnd::IAllocator* allocator);
    };
}
