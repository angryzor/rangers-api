#pragma once

namespace hh::dbg {
    class MsgParamChangedInEditor : public fnd::Message {
    public:
        MsgParamChangedInEditor() : fnd::Message(fnd::MessageID::PARAM_CHANGED_IN_EDITOR) {}
    };

    class MsgGetDebugCommentInEditor : public fnd::Message {
    public:
        char comment[512]{ "" };
        MsgGetDebugCommentInEditor() : fnd::Message(fnd::MessageID::GET_DEBUG_COMMENT_IN_EDITOR) {}
    };
}
