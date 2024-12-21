#pragma once

namespace hh::dv{
    class DvNodeModel : public DvNodeBaseAnimationModel {
    public:
        virtual void Setup() override;
        virtual void DeleteCharacterObject() override;
        virtual void* UnkFunc1();
        virtual void UnkFunc3();
        virtual bool UnkFunc2();
        virtual int64_t UnkInt();
        virtual void* UnkCharacterObject2();
        virtual void* GetRuntimeTypeInfo() override;
        virtual char UnkFunc0() override;

        DV_NODE_DECLARATION_BASE(DvNodeModel)
    };
}