#pragma once

namespace hh::game {
    class GOCActivator : public hh::game::GOComponent, public hh::fnd::HFrame::Listener {
        float range;
        float distance;
        bool unk101;
        csl::math::Vector3 z;
        float unk103;
    public:
        bool enabled;

        GOCActivator(csl::fnd::IAllocator* allocator);
		virtual void* GetRuntimeTypeInfo() override;
		virtual void LoadReflection(const fnd::RflClass& rflClass) override;
		virtual void OnGOCEvent(GOCEvent event, GameObject& ownerGameObject, void* data) override;
        virtual void HFrameUpdatedCallback(const fnd::HFrame* frame, bool unkParam) override;

        GOCOMPONENT_CLASS_DECLARATION(GOCActivator)
    };
}
