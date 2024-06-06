#pragma once

namespace hh::hid {
    class InputDevice : public fnd::ReferencedObject {
    public:
        InputDevice(csl::fnd::IAllocator* pAllocator);

        virtual void* GetRuntimeTypeInfo() const;
        virtual unsigned int GetDeviceId() const;
        virtual float GetInputValue(unsigned int inputId) const;
        virtual csl::math::Vector4 GetTarget1() const;
        virtual csl::math::Vector4 GetTarget2() const;
        virtual void Update(float unkParam);
        virtual bool HasUpdated() { return true; }
        virtual bool UnkFunc7() { return false; } 
    };
}
