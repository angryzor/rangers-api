#pragma once

namespace app::player {
    struct ComponentCollection;
    struct Component {
        ComponentCollection* collection;
        csl::ut::MoveArray<hh::fnd::Reference<hh::game::GOComponent>> components;
        hh::fnd::Reference<hh::gfx::GOCVisualModel> visual;
        hh::fnd::Reference<hh::anim::GOCAnimator> animator;
        csl::ut::MoveArray<hh::eff::EffectHandle> effects;
        uint64_t unk3;

        void AddComponent(hh::game::GOComponent* component);
        void RemoveComponent(hh::game::GOComponent* component);
    };

    class ComponentCollector;
    struct ComponentCollection {
        csl::ut::MoveArray<Component> components;
        ComponentCollector* componentCollector;
        uint64_t unk3;
        uint8_t unk4;

        ComponentCollection();
        void Initialize(hh::game::GameObject* gameObject, unsigned int componentCount);
        Component& GetComponent(int id);
        hh::fnd::HFrame* GetFrame() const;
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
