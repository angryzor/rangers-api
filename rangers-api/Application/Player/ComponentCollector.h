#pragma once

namespace app::player {
    struct Component {
        uint64_t unk1[5];
        hh::gfx::GOCVisualModel* visual;
        hh::anim::GOCAnimator* animator;
        uint64_t unk2[5];
    };

    class ComponentCollector;
    struct ComponentCollection {
        csl::ut::MoveArray<Component> components;
        ComponentCollector* componentCollector;
        uint64_t unk3;
        uint8_t unk4;

        ComponentCollection();
        Component& GetComponent(int id);
    };

    class GOCPlayerVisual;
    class ComponentCollector : public hh::fnd::ReferencedObject {
    public:

    private:
        hh::game::GameObject* gameObject;
        GOCPlayerVisual* gocPlayerVisual;
        ComponentCollection componentCollections[4];
        hh::fnd::Reference<hh::fnd::HFrame> frame;
        uint64_t unk2;
        bool unk3;

    public:
        ComponentCollector(csl::fnd::IAllocator* allocator, hh::game::GameObject* gameObject, GOCPlayerVisual* gocPlayerVisual);
    };
}
