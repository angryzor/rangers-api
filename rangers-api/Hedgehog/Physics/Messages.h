#pragma once

namespace hh::physics {
    class MsgTriggerBase : public fnd::Message {
    public:
        void* subject;
        void* actor;

        MsgTriggerBase(fnd::MessageID id, const void* subject, const void* actor);
    };
    class MsgTriggerEnter : public MsgTriggerBase {
    public:
        MsgTriggerEnter(const void* subject, const void* actor) : MsgTriggerBase{ fnd::MessageID::TRIGGER_ENTER, subject, actor } {}
		virtual fnd::MessageAsyncHandler* CreateAsyncHandler(csl::fnd::IAllocator* allocator) override;
    };
    class MsgTriggerStay : public MsgTriggerBase {
    public:
        MsgTriggerStay(const void* subject, const void* actor) : MsgTriggerBase{ fnd::MessageID::TRIGGER_STAY, subject, actor } {}
		virtual fnd::MessageAsyncHandler* CreateAsyncHandler(csl::fnd::IAllocator* allocator) override;
    };
    class MsgTriggerLeave : public fnd::Message {
    public:
        fnd::Handle<GOCCollider> subject;
        fnd::Handle<GOCCollider> actor;
        MsgTriggerLeave(const fnd::Handle<GOCCollider>& subject, const fnd::Handle<GOCCollider>& actor);
		virtual fnd::MessageAsyncHandler* CreateAsyncHandler(csl::fnd::IAllocator* allocator) override;
    };
}
