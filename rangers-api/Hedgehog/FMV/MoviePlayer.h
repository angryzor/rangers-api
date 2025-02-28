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
            int width0;
            int height0;
            int width1;
            int height1;
            int rawFps;
            int framerateN; //see usm keys
            int framerateD; //see usm keys
            int totalFrames;
            int unk1; //related to current frame
        };

        struct UnkStr2{
        public:
            void* unk0;
            char unk1;
            void* unk2;
            char unk3;
        };

        struct TextureInfo{
        public:
            int width;
            int height;
            char unk0;
            int unk1;
            char unk2;
            int unk3;
            size_t unk4;
            size_t unk5;
        };

        void* unk3;
        int unk4[2];
        void* unk5;
        csl::ut::MoveArray<TextureInfo> textureInfos;
        FrameStr* frameStr0;
        int* unk7;
        FrameStr* frameStr1;
        FrameStr* frameStr2;
        char unk8;
        csl::fnd::IAllocator* unkAllocator1;
        UnkStr2 unkStr2[2];
        char unk9;
        float unk95;
        char unk10;
        char unk11;
        char unk12;
        char unk13;
        char unk14;
        char unk15;
        char unk16;
        int unk17[8];
        char unk18;
        char unk19;
        char unk20;
        char unk21;
        int unk22;
        char unk23;
        char unk24;
        char unk25;
        char unk26;
        int unk27;
        int unk28;

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