#pragma once

namespace hh::fnd {
    class MessageQueue {
    public:
        class Entry : public ReferencedObject {
        public:
            enum class Flags {
                PENDING,
                IN_FLIGHT,
                HANDLED_FAILURE,
                HANDLED_SUCCESS,
            };
            fnd::Message* message;
            Flags flags;
        };
		struct Buffer {
			void* unk10;
			Entry** results;
			uint32_t messageCount;
			uint32_t bufferSize;
		};

		void* unk15;
		Buffer messageBuffers[2];
		int currentBuffer;
    
        void EnqueueMessage(const Message& message);
        void Dispatch(bool (*func)(const Message& message, void* userData), void* userData);
    };
}
