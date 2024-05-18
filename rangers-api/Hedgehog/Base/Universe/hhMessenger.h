#pragma once

namespace app
{
	class GameManager;
}

namespace hh::fnd
{
	class Messenger : public RefByHandleObject
	{
	protected:
		/*
		 * Sends a message to one particular receiver.
		 */
		MessageAsyncHandler* SendMessage(Handle<Messenger>& receiver, Message& message);
		bool SendMessageImm(Handle<Messenger>& receiver, Message& message);
		bool ForwardMessageImm(Handle<Messenger>& receiver, Message& message);

	public:
		MessageManager* messageManager;
		uint32_t messageMask;
		uint32_t unk3;

		Messenger(csl::fnd::IAllocator* pAllocator);

		virtual void* GetRuntimeTypeInfo();
		virtual bool ProcessMessage(Message& message) { return !fUnk3(); }
		virtual bool fUnk3() { return false; }
		virtual bool ReceiveMessage(Message& message);
		virtual bool IsAcceptingMessages() { return 1; }
		
		bool SendMessageImm(Message& message);
	};
}
