#pragma once

namespace hh::needle {
    class PostEffectRenderJob : public RenderJob {
    public:
        struct Unk1 {
            uint64_t unk1;
            uint64_t unk2;

            Unk1();
        };

        void* qword50[10];
        void* qword98[8];
        void* qwordD8;
        Unk1 qwordE0;

        PostEffectRenderJob(void* unk1Param);
        virtual void UnkFunc7(void* unkParam) override;
        virtual void UnkFunc8() override;
        virtual void UnkFunc20(unsigned int index, void* obj);
        virtual void UnkFunc21(unsigned int index, void* obj);
        virtual void UnkFunc22();
        virtual void UnkFunc23();
        virtual void UnkFunc24();
    };
}
