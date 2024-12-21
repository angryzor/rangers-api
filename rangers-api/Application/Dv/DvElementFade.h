#pragma once

namespace app::dv{
    class DvElementFade : public AppDvElementBase{
    public:
        struct DvElementFadeData{
            char a;
            char r;
            char g;
            char b;
            int padding[3];
            float curveData[32];
        };

        int unk0;

        virtual void Setup(int a2);
        virtual void UnkFunc();
        virtual int64_t LoadBinaryData(const char* binaryData) override;
        virtual int64_t UnloadBinaryData() override;
        virtual void CreateDvFadeObject();
        virtual void KillDvFadeObject();

        APP_DV_ELEMENT_DECLARATION_BASE(DvElementFade)
    };
}