#pragma once

namespace hh::anim {
    class BlendNodeBase : public fnd::ReferencedObject {
    public:
        enum class Flag : uint16_t {
            UNK1 = 1,
            UNK2 = 2,
            UNK3 = 3,
            UNK10 = 10,
        };
    public:

        BlendNodeType type;
        bool hasTargetNodeInTree; // hasTargetNode? see SetTargetNode
        csl::ut::Bitset<Flag> flags; // unsure if exists
        uint32_t unk3; // unsure if exists
        BlendNodeBase* parent;
        BlendNodeBase* hierarchyRoot;
        csl::ut::InplaceMoveArray<BlendNodeBase*, 2> children;

        BlendNodeBase(BlendNodeType type);

        virtual void* GetRuntimeTypeInfo() const;
        virtual bool Accept() { return true; }
        virtual bool always_false() { return false; }
        virtual uint64_t UnkFunc4();
        virtual void UpdateWeight(BlendTreeSyncContext& syncContext, float weight) = 0;
        virtual void UpdateMotionWeight(BlendTreeSyncContext& syncContext, float weight) = 0;
        virtual uint64_t GetLocalBlendMaskImpl() const = 0;
        virtual unsigned int SyncLocalBlendMask() const {}
        virtual void ResetBlendMask(const char* mask);
        virtual uint64_t UnkFunc10() { return false; }
        virtual uint64_t UnkFunc11();
        virtual void UnkFunc12() {}
        virtual void UnkFunc13() {}
        void SetHierarchyRoot(BlendNodeBase* root);
        void ClearChildren();

        // uint64_t Accept(BlendTreeVisitor& visitor);
        uint64_t CalcDescendantFlag();
        uint64_t CopyVariableToMember(float variable);
        uint64_t GetLocalBlendMask() const;
        bool HasBlendMask() const;
        uint64_t MarkBlendMaskDirty();
        uint64_t ResetBlendMask(const uint8_t* unkParam);
        uint64_t SetWeight(float weight);
        void SyncAll(BlendTreeSyncContext& syncContext);
        void AddChild(BlendNodeBase* child);
        void RemoveChild(BlendNodeBase* child);
    };

    class LayerBlendNode : public BlendNodeBase {
        BlendNodeBase* targetNode;
        void* unk5; // unk3 in asmresourcemgr indexed by unknown2 of the LayerData
        csl::ut::MoveArray<void*>* unk6; // -> refers to unk5 in asmresourcemanager
        csl::ut::MoveArray<void*> unk7; // sized by bone count

    public:
        CREATE_FUNC(LayerBlendNode, const AsmResourceManager& resourceManager, LayerData* layer)

        void SetTargetNode(BlendNodeBase* node);
    };

    class ClipNode : public BlendNodeBase {

    };

    class BranchBlendNode : public BlendNodeBase {

    };

    class LerpBlendNode : public BranchBlendNode {

    };

    class AdditiveBlendNode : public BranchBlendNode {
    public:
        CREATE_FUNC(AdditiveBlendNode, BlendNodeBase* node1, BlendNodeBase* node2, int unkParam)
    };

    class OverrideBlendNode : public BranchBlendNode {
    public:
        CREATE_FUNC(OverrideBlendNode, BlendNodeBase* node1, BlendNodeBase* node2, int unkParam)
    };

    class TwoPointLerpBlendNode : public BranchBlendNode {

    };

    class MulBlendNode : public BranchBlendNode {

    };

    class BlendSpaceNode : public BranchBlendNode {

    };
}
