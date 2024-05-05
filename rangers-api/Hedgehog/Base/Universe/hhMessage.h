#pragma once

namespace hh::fnd
{
	enum class MessageID : uint32_t {
		UPDATE_SET_EDITOR = 768,
		UPDATE_ACTIVE_OBJECT_IN_EDITOR = 769,
		START_ACTIVE_OBJECT_IN_EDITOR = 770,
		FINISH_ACTIVE_OBJECT_IN_EDITOR = 771,
		PARAM_CHANGED_IN_EDITOR = 772,
		GET_DEBUG_COMMENT_IN_EDITOR = 773,
		PUSH_CAMERA_CONTROLLER = 4097,
		CAMERA_OFF = 8353,
		IS_TAKE_RED_RING = 8676,
		NOTIFY_ACTION = 8748,
		NOTIFY_END_FALL_CYBERSPACE = 8765,
		NOTIFY_LEVEL_STATUS = 8779,
		NOTIFY_RETRY = 8788,
		PASS_POINT_MARKER = 8823,
		SET_MENU_ENABLED = 8947,
		UI_PAUSE_RESULT = 9198,
	};

	class Messenger;
	class Message
	{
	public:
		MessageID ID{};
		Handle<Messenger> Sender{};
		Handle<Messenger> Receiver{};
		char Handled{};
		bool Broadcasted{};
		const uint32_t Mask{ (uint32_t)-1 };

		Message(MessageID in_id)
		{
			ID = in_id;
		}

		virtual Message* Clone();
		virtual ~Message() = default;
	};

	class MessageAsyncHandler : ReferencedObject
	{
		Message* message{};
		uint8_t unk1{};

	public:
		virtual ~MessageAsyncHandler() = default;
		inline Message& GetMessage() const {
			return *message;
		}

		template<typename T>
		T& GetMessage() const {
			return static_cast<T&>(GetMessage());
		}
	};

	template <typename T>
	class MessageAsyncHandlerInplace : public MessageAsyncHandler
	{
		T messageInPlace;
	};
}
