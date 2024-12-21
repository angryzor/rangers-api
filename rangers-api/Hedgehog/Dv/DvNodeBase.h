#pragma once

namespace hh::dv{
    class DvSceneNodeTree;
    class DvNodeBase;

    class DvNodeProperties{
    public:
        enum class NodeType : uint32_t{
            PATH = 1,
            PATH_MOTION,
            CAMERA,
            CAMERA_MOTION,
            CHARACTER,
            CHARACTER_MOTION,
            CHARACTER_BEHAVIOR,
            MODEL_CUSTOM,
            MOTION_MODEL = 10,
            MODEL_NODE,
            ELEMENT
        };

        uint32_t flags; //prolly a bitset
        NodeType nodeType;
        char guid[16];
        char padding[16];
        csl::ut::String nodeName;
        csl::fnd::IAllocator* idkallocator;
        csl::math::Transform transform;
        csl::math::Matrix44 matrix;
        char padding1[8];
        DvNodeBase* parent;
        csl::ut::MoveArray<DvNodeBase*> childrenElements0;
        csl::ut::MoveArray<DvNodeBase*> childrenPaths;
        csl::ut::MoveArray<DvNodeBase*> childrenCameras;
        csl::ut::MoveArray<void*> unkArray2;
        csl::ut::MoveArray<DvNodeBase*> childrenElements1;
        csl::ut::MoveArray<DvNodeBase*> childrenElements2;
        DvSceneNodeTree* dvsceneNodeTree;
    };

    class DvNodeBase : public hh::fnd::ReferencedObject{
    public:
        DvNodeProperties properties;

        virtual void SetUnkFlag0();
        virtual void SetUnkFlag1();
        virtual bool IsUnkFlag0();

        DvNodeBase(csl::fnd::IAllocator* allocator);
    };
}