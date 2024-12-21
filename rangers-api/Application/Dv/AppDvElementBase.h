#pragma once

#define APP_DV_ELEMENT_DECLARATION_BASE(ClassName)public:\
		static app::dv::AppDvElementBase* Create(csl::fnd::IAllocator* allocator);

namespace app::dv{
    class AppDvElementBase : public hh::dv::DvElementBase{
    public:
        long elementBinaryDataSize;
        const char* elementBinaryData;
        char flags;

        virtual int64_t LoadBinaryData(const char* binaryData);
        virtual int64_t UnloadBinaryData();

        AppDvElementBase(csl::fnd::IAllocator* allocator, long elementSize);
    };
}