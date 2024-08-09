#pragma once

namespace hh::needle {
    // rsdx_noncopyable...
    class ParamBuildJob : public NeedleRefcountObject {
    public:
        // guessed
        virtual void Run() = 0;
        virtual void OnSetEnable(bool enabled) = 0;
    };
}
