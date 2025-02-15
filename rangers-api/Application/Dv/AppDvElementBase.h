#pragma once

#define APP_DV_ELEMENT_DECLARATION_BASE(ClassName)public:\
		static app::dv::AppDvElementBase* Create(csl::fnd::IAllocator* allocator);\
        ClassName::Data* GetData() {\
            return reinterpret_cast<ClassName::Data*>(elementBinaryData);\
        }

namespace app::dv{
    class AppDvElementBase : public hh::dv::DvElementBase{
    public:
        long elementBinaryDataSize;
        void* elementBinaryData;
        char flags;

        virtual void SetData(void* data) override;
        virtual void UnkFunc4() override;
        virtual void AppUnkFunc0() {};
        virtual void AppUnkFunc1() {};
        virtual void AppUnkFunc2() {};
        virtual void* AppUnkFunc3(void* unk0, unsigned int unk1) {};

        const char* GetBinaryData();

        AppDvElementBase(csl::fnd::IAllocator* allocator, hh::dv::DvNodeElement* base);
    };
}