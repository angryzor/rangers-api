#pragma once

namespace app::game {
    class GOCMotor : public hh::game::GOComponent {
    public:
        enum class TimeType : uint32_t {
            GLOBAL,
            LOCAL,
        };

        csl::math::Transform transform;
        hh::fnd::HFrame* frame;
        uint8_t flags;
        TimeType timeType;
        float maybeLoopTime;
        float time;
        int unk106;
        bool stopped;

        struct SetupInfo {
            TimeType timeType{};
            hh::fnd::HFrame* frame{};
        };

        GOCMotor(csl::fnd::IAllocator* allocator);
		virtual void* GetRuntimeTypeInfo() override;
		virtual void Update(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo) override;
		virtual void OnGOCEvent(GOCEvent event, hh::game::GameObject& ownerGameObject, void* data) override;
        virtual void InitTransform(csl::math::Transform& transform);
        virtual void UpdateSetEditor() {}
        virtual void InitConfig() {}
        virtual void UpdateTransform(float time, csl::math::Transform& transform) = 0;

        void Setup(const SetupInfo& setupInfo);

        GOCOMPONENT_CLASS_DECLARATION(GOCMotor);
    };
}
