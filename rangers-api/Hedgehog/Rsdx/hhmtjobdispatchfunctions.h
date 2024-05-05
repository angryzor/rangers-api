#pragma once

namespace hh::rsdx {
    template<typename JobDesc, typename JobDispatcher, typename JobInitializer>
    class CSimpleJobDispatcher {
    public:
        rsdx::hhMTSimpleJobJoint* unk1;
        rsdx::hhMTSimpleJobJoint* unk2;
        JobDesc* desc;
        JobDispatcher* dispatcher;
        uint32_t m_currDispatchCount;
        uint32_t unk4;
        uint32_t unk4b;
        uint32_t unk4c;
        uint32_t unk4d;
        rsdx::hhMTSimpleJobJoint* unk5;
        rsdx::hhMTSimpleJobJoint* unk6;
        JobInitializer* initializer;
        const char** name;
    };
}