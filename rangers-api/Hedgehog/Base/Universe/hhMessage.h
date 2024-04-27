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
		CAMERA_OFF = 8353,
		NOTIFY_ACTION = 8748,
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
