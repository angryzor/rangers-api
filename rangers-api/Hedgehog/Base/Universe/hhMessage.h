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

		virtual Message* Clone()
		{
			return new Message(ID);
		}

		virtual ~Message() = default;
	};

	class MessageAsyncHandler : ReferencedObject
	{
	public:
		void* pUnk1{};
		char Unk2{};

		virtual ~MessageAsyncHandler() = default;
	};

	template <typename T>
	class MessageAsyncHandlerInplace : public MessageAsyncHandler
	{
		
	};
}

namespace app::fnd
{
	template <typename T>
	class AppMessage : public hh::fnd::Message
	{
	public:
		AppMessage(hh::fnd::MessageID in_id) : Message(in_id)
		{
			
		}
		
		AppMessage<T>* Clone() override
		{
			return new AppMessage<T>(ID);
		}
	};
}