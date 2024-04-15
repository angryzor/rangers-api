#pragma once

namespace hh::anim {
    struct AnimationData {
        const char* name;
        const char* resourceName;
        float unk1;
        float unk2;
        float speed;
        uint8_t unk4;
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

    struct StateData {
        const char* name;
        char isbool1;
        uint8_t unk1;
        bool isLoop;
        uint8_t unk2222;
        int16_t animReference;
        int16_t maxCycles;
        float speed;
        int16_t unk4444;
        int16_t isbool2;
        int16_t unk6;
        int16_t currentState;
        int16_t unk88888;
        int16_t nextState;
        float unk10;
        int16_t unk11;
        int16_t unk12;
        int16_t isbool3;
        int16_t unk14;
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
        // This value are weird for LAYER type blend nodes: the childNodeArraySize is then
        // expected to be 1, and the childNodeArrayOffset is the layer ID.
        int16_t childNodeArraySize;
        int16_t childNodeArrayOffset;
    };

    struct Unk2Data {
        const char* name;
        int16_t stateRef1;
        int16_t stateRef2;                         
        float unk3;
        int16_t unk4;
        int16_t unk5;
        uint32_t unk6;
    };

    // An array of transitions, defined as a slice of the large transition array in the top level struct.
    struct TransitionArrayData {
        // Where this array starts in the large array of transitions.
        int offset;
        // How many transitions this array contains.
        int size;
    };

    struct TransitionData {
        uint8_t unk1;
        uint8_t unk2;
        uint16_t stateId;
        float transitionTime;
        int16_t unk4;
        uint16_t unk5;
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

    struct Unk11Data {
        uint32_t unknown1;
        float unknown2;
        float unknown3;
        uint16_t unknown4;
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
        int animationCount;
        AnimationData* animations;
        int stateCount;
        StateData* states;
        int blendNodeCount;
        BlendNodeData* blendNodes;
        int unk2Count;
        Unk2Data* unk2;
        int transitionArrayCount;
        TransitionArrayData* transitionArrays;
        int transitionCount;
        TransitionData* transitions;
        uint16_t u5;
        int16_t u6;
        float u7;
        int16_t u8;
        uint16_t u9;
        int u10Count;
        uint16_t* u10;
        int u11Count;
        const char** u11;
        int variableCount;
        const char** variables;
        int layerCount;
        LayerData* layers;
        int u14Count;
        Unk9Data* u14;
        int layerBoneCount;
        const char** layerBones;
        int u16Count;
        Unk11Data* u16;
        int u17Count;
        const char** u17;
        int u18Count;
        const char** u18;
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
        csl::ut::MoveArray<void*> states;
        csl::ut::MoveArray<TransitionArray> transitionArrays;

        MANAGED_RESOURCE_CLASS_DECLARATION(ResAnimator)
        int GetStateId(const char* stateName);
        int GetVariableId(const char* variableName);
        int GetLayerId(const char* layerName);
        int GetTriggerId(const char* triggerName);
    };
}
