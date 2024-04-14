#pragma once

namespace hh::physics {
    class GOCCapsuleCollider : public GOCCollider {
    public:
        float radius;
        float height;
        virtual void GetShape(ColliShape& shape) const override;

        void Setup(const SetupInfo& setupInfo);

        GOCOMPONENT_CLASS_DECLARATION(GOCCapsuleCollider);
    };
}
