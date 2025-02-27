#pragma once

namespace hh::fmv{
    class MoviePlayer : public fnd::ReferencedObject {
    public:
        class MyRenderable : public gfnd::Renderable {
        public:
            virtual void* MyUnkFunc0();
            virtual void MyUnkFunc1() {}
            virtual bool MyUnkFunc2() { return true; }
        };

        struct UnkStr{
        public:
            int qword0; //flags
            void* unkFunc;
            MoviePlayer* moviePlayer;
            int qword18;
            csl::fnd::IAllocator* allocator;

            UnkStr(csl::fnd::IAllocator* allocator);
        };

        struct UnkStr1{
        public:
            float unk0;
            int unk1;
            int unk2;
        };

        MovieRenderObject* movieRenderObj;
        MyRenderable* renderable;
        const char* usmFilePath;
        int64_t qword30;
        UnkStr unkStr38;
        UnkStr1 unkStr1[3];
        float secondsRunning;
        int framesRunning;
        int dword8C;
        short word90;
        short word92;
        int64_t qword98;
        int dwordA0;

        virtual void* UnkFunc0() {}
        virtual void* UnkFunc1() {}
        virtual void* UnkFunc2() {}
        virtual void UnkFunc3(char a2) {}
        virtual void* UnkFunc4(char a2) {}
        virtual void* UnkFunc5(int a2, double a3); //denuvo infested
        virtual void* UnkFunc6(int a2, int a3);
        virtual void* UnkFunc7(char a2);
        virtual void UnkFunc8() {}
        virtual void* UnkFunc9(void* a2);
        virtual void* UnkFunc10() {}

        MoviePlayer(csl::fnd::IAllocator* allocator);
    };

    class MoviePlayerCri : public MoviePlayer {
    public:
        struct FrameStr{
        public:
            int framesRunning;
            int currentFrame;
        };

        void* unk3;
        int unk4[2];
        void* unk5;
        csl::ut::MoveArray<void*> unk6;
        FrameStr* frameStr0;
        int* unk7;
        FrameStr* frameStr1;
        FrameStr* frameStr2;
        bool unk8;

        virtual void* UnkFunc0() override;
        virtual void* UnkFunc1() override;
        virtual void* UnkFunc2() override;
        virtual void UnkFunc3(char a2) override;
        virtual void* UnkFunc4(char a2) override;
        virtual void* UnkFunc5(int a2, double a3) override;
        virtual void* UnkFunc6(int a2, int a3) override;
        virtual void* UnkFunc7(char a2) override;
        virtual void UnkFunc8() override;
        virtual void* UnkFunc9(void* a2) override;
        virtual void* UnkFunc10() override;
        
        MoviePlayerCri(csl::fnd::IAllocator* allocator);
    };
}