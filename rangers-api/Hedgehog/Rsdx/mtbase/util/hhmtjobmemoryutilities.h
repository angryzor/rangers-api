#pragma once

namespace hh::rsdx {
    struct SEventHolder {
        SLIST_ENTRY slistEntry;
        HANDLE eventHandle;
    };

    // size 256
    struct SJobJoint {
        SLIST_HEADER slistHeader;
        volatile int semaphore;
        SEventHolder* evhandle;
        volatile int isLocked;
        unsigned short unk2;
        unsigned short isFired;
        const char* name;
    };

    struct SJobExecParam {
        SLIST_ENTRY slistEntry;
        unsigned int mask;
        SJobJoint* JobJoint;
    };

    // size 256
    struct SJobType256 {
        SJobExecParam ExecContext;
    };

    void RsdxSetEvent(HANDLE event);
    bool RsdxCheckEvent(HANDLE event);
    bool RsdxWaitEvent(HANDLE event);
    void RsdxResetEvent(HANDLE event);

    void hhMTExecuteJob(SJobExecParam* pjob_current, bool unkParam);
    void hhMTSimpleJobBind(SJobExecParam* pjob_current, SJobJoint* jobJoint);
    void hhMTSimpleJobBind(SJobType256* jobType, SJobJoint* jobJoint);
    void hhMTSimpleJobBlockUntilSignal(SJobJoint* jobJoint);
    void hhMTSimpleJobBlockUntilSignalInside(SJobJoint* jobJoint, unsigned int mask);
    bool hhMTSimpleJobCheckEnable();
    SJobType256* hhMTSimpleJobCreateDefault();
    void hhMTSimpleJobDestroyDefault(SJobType256* jobType);
    void hhMTSimpleJobEnd();
    void hhMTSimpleJobEntry(SJobType256* jobType, unsigned int mask);
    SJobJoint* hhMTSimpleJobJointCreate();
    SJobJoint* hhMTSimpleJobJointDynamicCreate(char const* name);
    void hhMTSimpleJobJointLock(SJobJoint* jobJoint);
    void hhMTSimpleJobJointRelease(SJobJoint* jobJoint);
    SJobJoint* hhMTSimpleJobJointStaticCreate(char const* name);
    void hhMTSimpleJobJointUnlock(SJobJoint* jobJoint);
    void hhMTSimpleJobLinkNext(SJobExecParam* pjob_current, SJobJoint* jobJoint, unsigned int mask);
    void hhMTSimpleJobLinkNext(SJobType256* jobType, SJobJoint* jobJoint, unsigned int mask);
    void hhMTSimpleJobLinkJoint(SJobJoint* jobJoint1, SJobJoint* jobJoint2);
    void hhMTSimpleJobStart(size_t count, void* unkParam, bool unkParam2, unsigned int unkParam3);
    void jobJointFinish(SJobJoint* jobJoint);

    class CMTJobMemorySystemUtil {
        static size_t g_MemoryCount;
        static void* g_Memory;
    public:
        static void InitializeJobMemory(size_t size);
    };

    class CMTSimpleJobInternal {
    public:
        CMTSimpleJobInternal();
    };
}
