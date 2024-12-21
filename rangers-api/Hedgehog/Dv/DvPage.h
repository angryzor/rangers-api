#pragma once

namespace hh::dv{
    class DvSceneControl;
    class DvPage;
    class DvPageTransition;

    class DvPageConditionBase : public hh::fnd::BaseObject{
    public:
        int8_t unk0;
        DvPageTransition* transition;
        int unk2;
        int unk3;

        virtual hh::game::GameService* GetEventPlayer(void* a2);
        virtual int64_t UnkFunc();
        
        DvPageConditionBase(csl::fnd::IAllocator* allocator);
    };

    class DvPageTransition : public hh::fnd::BaseObject{
    public:
        struct DvPageTransitionData{
            int destinationPageID;
            int conditionCount;
            int64_t conditionSize;
        };

        void* unk;
        DvPage* page;
        DvPageTransitionData binaryData;
        DvPageConditionBase* condition;

        DvPageTransition(csl::fnd::IAllocator* allocator);
    };

    class DvPage : public hh::fnd::BaseObject{
    public:
        struct DvPageData{
            int64_t unk0;
            int start;
            int end;
            int transitionCount;
            int transitionSize;
            int skipFrame;
            int pageIndex;
            int skipLinkIndexNum;
            int unks[3];
            char pageName[32];
        };

        int8_t unk0;
        DvSceneControl* dvSceneControl;
        DvPageData binaryData;
        csl::ut::MoveArray<DvPageTransition*> transitions;
        int unk1;
        float unk2;

        virtual int GetStart();

        DvPage(csl::fnd::IAllocator* allocator);
    };
}