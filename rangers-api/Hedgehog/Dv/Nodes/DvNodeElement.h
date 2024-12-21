#pragma once

namespace hh::dv{
    class DvNodeElement;

    class DvElementBase : public hh::fnd::ReferencedObject {
    public:
        char isLoaded;
        DvNodeElement* baseNode;

        DvElementBase(csl::fnd::IAllocator* allocator);

        virtual ~DvElementBase() { };

        virtual bool AlwaysUpdate(unsigned int currFrame, csl::math::Transform& transform);
        virtual bool Unk1(void* a1, void* a2);
        virtual void NormalUpdate(unsigned int currFrame, csl::math::Transform& transform);
        virtual void null0();
        virtual void DestroyElement();
        virtual bool IsLoaded();
    };

    class DvNodeElement : public DvNodeBase {
    public:
        enum class PlayType : uint32_t{
            NORMAL,
            ONESHOT,
            ALWAYS
        };

        enum class UpdateTiming : uint32_t{
            ON_EXEC_PATH,
            ON_PRE_UPDATE,
            CHARACTER_FIX_POSTURE,
            ON_POST_UPDATE_CHARACTER,
            ON_UPDATE_POS,
            ON_FIX_BONE_POSTURE,
            ON_EVALUATE_DETAIL_MOTION,
            CHARACTER_JOB_UPDATE,
            MODIFY_POSE_AFTER,
            JOB_REGISTER,
            MOTION_UPDATE
        };

        struct DvNodeElementData {
            int ElementID;
            float Start;
            float End;
            int unk1;
            int unk2;
            PlayType playType;
            UpdateTiming updateTiming;
            int padding;
        };

        int isActive;
        DvNodeElementData binaryData;
        int unk0;
        DvElementBase* element;
        int start;
        int end;

        virtual void Setup();
        virtual void DeleteElement();
        virtual bool SomethingWithIsActiveAndPlayType();
        virtual void HidesBasedOnFrame(uint32_t frame);
        virtual bool IsUnkFlag1();
        virtual UpdateTiming GetUpdateTiming();
        virtual int UnkFunc0();

        DV_NODE_DECLARATION_BASE(DvNodeElement)
    };
}