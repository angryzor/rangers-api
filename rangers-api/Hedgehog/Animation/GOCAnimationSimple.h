#pragma once

namespace hh::anim {
    struct GOCSimpleAnimationSpawner {
        csl::ut::VariableString resSkeleton;
        csl::ut::VariableString resAnimation;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(GOCSimpleAnimationSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(GOCSimpleAnimationSpawner* pInstance);
        static void Clean(GOCSimpleAnimationSpawner* pInstance);
    };

    inline const hh::fnd::RflTypeInfo GOCSimpleAnimationSpawner::typeInfo{
        "GOCSimpleAnimationSpawner",
        "GOCSimpleAnimationSpawner",
        [](void* instance, csl::fnd::IAllocator* allocator) {
            auto* inst = static_cast<GOCSimpleAnimationSpawner*>(instance);
            new (&inst->resAnimation) csl::ut::VariableString{ allocator };
            new (&inst->resSkeleton) csl::ut::VariableString{ allocator };
            return instance;
        },
        [](void* instance) {},
        [](void* instance) {
            auto* inst = static_cast<GOCSimpleAnimationSpawner*>(instance);
            inst->resAnimation.~VariableString();
            inst->resSkeleton.~VariableString();
        },
        sizeof(GOCSimpleAnimationSpawner),
    };
}
