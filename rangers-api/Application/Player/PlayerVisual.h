#pragma once

#define PLAYER_VISUAL_CLASS_DECLARATION_BASE(ClassName) private:\
		static const app::player::PlayerVisualClass playerVisualClass;\
    public:\
		static app::player::PlayerVisual* Create(csl::fnd::IAllocator* allocator, hh::game::GameObject* gameObject, ComponentCollection* componentCollection);\
		ClassName(csl::fnd::IAllocator* allocator, hh::game::GameObject* gameObject, ComponentCollection* componentCollection);

#define PLAYER_VISUAL_CLASS_DECLARATION(ClassName) PLAYER_VISUAL_CLASS_DECLARATION_BASE(ClassName)\
	public:\
		static const app::player::PlayerVisualClass* GetClass();

#define PLAYER_VISUAL_CLASS_DECLARATION_INLINE_GET_CLASS(ClassName) PLAYER_VISUAL_CLASS_DECLARATION_BASE(ClassName)\
	public:\
		static inline const app::player::PlayerVisualClass* GetClass() {\
			return &RESOLVE_STATIC_VARIABLE(playerVisualClass);\
		}

namespace app::player {
    class PlayerVisual;

    struct PlayerVisualClass {
        unsigned int nameHash;
        PlayerVisual* (*instantiator)(csl::fnd::IAllocator* allocator);
    };

    class GOCPlayerVisual;
    class PlayerVisual : public hh::fnd::ReferencedObject {
        hh::game::GameObject* gameObject;
        GOCPlayerVisual* gocPlayerVisual;
        ComponentCollection* componentCollection;
        uint64_t unk1;
        uint16_t unk2;
    public:
        PlayerVisual(csl::fnd::IAllocator* allocator, hh::game::GameObject* gameObject, ComponentCollection* componentCollection);

        virtual unsigned int GetNameHash() const = 0;
        virtual void Initialize(hh::game::GameObject* gameObject, ComponentCollection* componentCollection) = 0;
        virtual uint64_t UnkFunc3() {}
        virtual uint64_t UnkFunc4() {}
        virtual uint64_t UnkFunc5();
        virtual uint64_t UnkFunc6();
        virtual uint64_t UnkFunc7() = 0;
        virtual uint64_t UnkFunc8() = 0;

        Component& GetComponent(int id) const;
        hh::anim::GOCAnimator* GetComponentAnimator(char componentId) const;

        bool ChangeComponentAnimatorState(char componentId, const char* state);
        bool ChangeComponentAnimatorStateWithoutTransition(char componentId, const char* state);
        bool ChangeComponentAnimatorToNull(char componentId);
        bool ChangeComponentAnimatorToNull(char componentId, int unkParam);
        void SetComponentAnimatorActiveStateLocalTime(char componentId, float time);
        void SetComponentAnimatorPlaybackSpeed(char componentId, float speed);
        bool GetComponentAnimatorFloat(char componentId, const char* variableName, float* value);
        bool SetComponentAnimatorFloat(char componentId, const char* variableName, float value);
        // bool SetDefaultComponentAnimatorFloat(const char* variableName, float value);
        void AttachComponent(char componentId, hh::fnd::HFrame* frame);
        void DetachComponent(char componentId);
    };
}
