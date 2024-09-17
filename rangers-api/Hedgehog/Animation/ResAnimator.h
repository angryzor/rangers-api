#pragma once

namespace hh::anim {
    struct ClipData {
        const char* name;
        const char* resourceName;
        float unk1;
        float unk2;
        float speed;
        uint8_t flags;
        bool isLoop;
        uint16_t padding;
        uint16_t unk7;
        uint16_t unk8;
        uint16_t unk9;
        uint16_t padding2;
        uint16_t unk10;
        uint16_t padding3;
        uint32_t unk11;
    };

    enum class StateType : uint8_t {
        CLIP,
        BLEND_TREE,
        SPEED,
    };

    struct StateData {
        const char* name;
        StateType type;
        uint8_t unk1;
        uint8_t flags;
        uint8_t defaultLayerIndex;
        int16_t rootBlendNodeIndex;
        int16_t maxCycles;
        float speed;
        int16_t speedVariableIndex;
        int16_t eventCount;
        int16_t eventOffset;
        int16_t transitionArrayIndex;
        int16_t unk88888;
        int16_t nextState;
        float unk10;
        int16_t unk11;
        int16_t unk12;
        int16_t flagIndexCount;
        int16_t flagIndexOffset;
        uint32_t unk15;
    };

    enum class BlendNodeType : uint8_t {
        LERP,
        ADDITIVE,
        CLIP,
        OVERRIDE,
        LAYER,
        MULTIPLY,
        BLEND_SPACE,
        TWO_POINT_LERP,
    };

    struct BlendNodeData {
        BlendNodeType type;
        uint8_t unk2;
        int16_t unk3;
        int16_t unk4;
        int16_t unk5;
        float unk6;
        // Points back into the blendNode array to specify this node's children.
        // This value is weird for LAYER type blend nodes: the childNodeArraySize is then
        // expected to be 1, and the childNodeArrayOffset is the layer ID.
        int16_t childNodeArraySize;
        int16_t childNodeArrayOffset;
    };

    // An array of transitions, defined as a slice of the large transition array in the top level struct.
    struct TransitionArrayData {
        // Where this array starts in the large array of transitions.
        int offset;
        // How many transitions this array contains.
        int size;
    };

    enum class TransitionType : uint8_t {
        UNK0,
        UNK1,
        UNK2,
        UNK3,
        UNK4,
        UNK5,
        UNK6,
        UNK7,
    };

    struct TransitionData {
        struct TransitionInfo {
            TransitionType type;
            uint8_t unk2;
            short targetStateIndex;
            float transitionTime;
        };

        struct VariableInfo {
            int16_t transitionTimeVariableIndex;
            uint16_t unk5; // may not exist
        };

        TransitionInfo transitionInfo;
        VariableInfo variableInfo;
    };

    struct EventData {
        const char* name;
        TransitionData transition;
        uint32_t unk6; // may not exist
    };

    struct LayerData {
        const char* name;
        uint16_t unknown1;
        int16_t unknown2;
        uint32_t unknown3;
    };

    struct Unk9Data {
        const char* name;
        uint16_t unknown1;
        int16_t unknown2;
        uint32_t unknown3;
    };

    struct TriggerData {
        uint32_t unknown1;
        float unknown2;
        float unknown3;
        unsigned short triggerTypeIndex;
        int16_t unknown5;
        const char* name;
    };

    struct Unk17Data {
        uint16_t unknown1;
        uint16_t unknown2;
        uint16_t unknown3;
        uint16_t unknown4;
    };

    struct Unk14Data {
        uint16_t unknown1;
        uint16_t unknown2;
        float unknown3;            
        float unknown4;
        float unknown5;
        float unknown6;
        uint16_t unk9And10Count;
        uint16_t unk17Count;
        csl::math::Vector2* unknown9;
        uint16_t* unknown10;
        Unk17Data* unknown11;
    };

    struct AnimatorData {
        char magic[4];
        int version;
        int clipCount;
        ClipData* clips;
        int stateCount;
        StateData* states;
        int blendNodeCount;
        BlendNodeData* blendNodes;
        int eventCount;
        EventData* events;
        int transitionArrayCount;
        TransitionArrayData* transitionArrays;
        int transitionCount;
        TransitionData* transitions;
        TransitionData nullTransition;
        int flagIndexCount;
        uint16_t* flagIndices;
        int flagCount;
        const char** flags;
        int variableCount;
        const char** variables;
        int layerCount;
        LayerData* layers;
        int u14Count;
        Unk9Data* u14;
        int nodeCount;
        const char** nodes;
        int triggerCount;
        TriggerData* triggers;
        int triggerTypeCount;
        const char** triggerTypes;
        int colliderCount;
        const char** colliders;
        uint32_t blendTreeRootNodeId;
        int u20Count;
        Unk14Data* u20;
    };

    // A map of state id -> TransitionData
    class TransitionArray : public csl::ut::PointerMap<size_t, TransitionData> {
    public:
        const TransitionData& GetTransitionData(int stateId) const;
    };

    class ResAnimator : public fnd::ManagedResource {
    public:
        AnimatorData* binaryData;
        void* unk2;
        csl::ut::StringMap<int> stateIdsByName;
        csl::ut::StringMap<int> variableIdsByName;
        csl::ut::MoveArray<EventArray> eventArrays;
        csl::ut::MoveArray<TransitionArray> transitionArrays;

        MANAGED_RESOURCE_CLASS_DECLARATION(ResAnimator)
        int GetStateId(const char* stateName);
        int GetVariableId(const char* variableName);
        int GetLayerId(const char* layerName);
        int GetTriggerId(const char* triggerName);
    };
}
