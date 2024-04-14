#pragma once

#pragma once

namespace hh::physics {
    class GOCSphereCollider : public GOCCollider {
    public:
        float radius;
        virtual void GetShape(ColliShape& shape) const override;

        void Setup(const SetupInfo& setupInfo);

        GOCOMPONENT_CLASS_DECLARATION(GOCSphereCollider);
    };
}
