#pragma once

namespace hh::rsdx {
    struct hhMTSimpleJob {
        SLIST_ENTRY slistEntry;
        uint64_t unk1;
        HANDLE event;
    };
    struct hhMTSimpleJobJoint {
        SLIST_HEADER slistHeader;
        volatile int unk1;
        hhMTSimpleJob* job;
        volatile int isLocked;
        uint16_t isFired;
        uint64_t unk5;
    };
}