#pragma once

namespace hh::eff {
    class EffectManager : public game::GameService, public game::GameStepListener, public game::GameUpdateListener {
    public:
        class Impl;// {
        // public:
        //     rsdx::hhMTSimpleJobJoint* jobJoint1;
        //     rsdx::hhMTSimpleJobJoint* jobJoint2;
        //     rsdx::hhMTSimpleJobJoint* jobJoint3;
        //     rsdx::hhMTSimpleJobJoint* jobJoint4;
        //     rsdx::hhMTSimpleJobJoint* jobJoint5;
        //     csl::fnd::IAllocator* allocator;
        //     void* unk1;
        //     csl::ut::MoveArray<void*> unk2;
        //     uint64_t unk3;
        //     uint32_t unk4;
        //     float unk5;
        //     _BYTE gap68[16];
        //     _DWORD dword78;
        //     _QWORD qword80;
        //     _QWORD qword88;
        //     _QWORD qword90;
        //     _QWORD qword98;
        //     _QWORD qwordA0;
        //     _QWORD qwordA8;
        //     _QWORD qwordB0;
        //     _QWORD qwordB8;
        //     _WORD wordC0;
        //     _QWORD qwordC8;
        //     _DWORD dwordD0;
        //     _QWORD qwordD8;
        //     _DWORD dwordE0;
        //     _QWORD qwordE8;
        //     _QWORD qwordF0;
        //     _QWORD qwordF8;
        //     _QWORD qword100;
        //     _QWORD qword108;
        //     _DWORD dword110;
        //     _QWORD qword118;
        //     _QWORD qword120;
        //     _BYTE byte128;
        //     __unaligned __declspec(align(4)) _QWORD qword12C;
        //     __unaligned __declspec(align(1)) _QWORD qword134;
        //     __unaligned __declspec(align(1)) _QWORD qword13C;
        //     __unaligned __declspec(align(1)) _QWORD qword144;
        //     __unaligned __declspec(align(1)) _QWORD qword14C;
        //     _QWORD qword158;
        //     _QWORD qword160;
        //     _QWORD qword168;
        //     _WORD word170;
        //     _RTL_CRITICAL_SECTION rtl_critical_section178;
        // };

        struct RenderableInfo {
            unsigned int renderPass;
            unsigned int unk1;
        };

        struct SetupInfo {
            unsigned int cyanSystemSize;
            unsigned int cyanRenderSize;
            unsigned int cyanTagSize;
            unsigned int cyanEffectSize;
            unsigned int cyanEmitterSize;
            unsigned int cyanElementSize;
            unsigned int cyanAnimationSize;
            unsigned int cyanMeshRenderSize;
            unsigned int cyanDebugSize;
            unsigned int renderWidth;
            unsigned int renderHeight;
            unsigned int numRenderables;
            RenderableInfo* renderables;
            unsigned int (*unk1)(uint8_t unkParam);
            unsigned int (*unk2)(unsigned int unkParam);
        };

        class Listener {
        public:
            virtual void UnkFunc1() {}
            virtual void UnkFunc2() {}
            virtual void UnkFunc3() {}
        };

        class Resolver : public fnd::ResourceResolver {
        public:
            EffectManager* effMgr;
            csl::ut::VariableString unk1;
            virtual fnd::ManagedResource* Resolve(csl::fnd::IAllocator* allocator, const char* name, const fnd::ResourceTypeInfo* typeInfo);
        };

        Impl* implementation;
        Listener listener;
        Resolver resolver;
        csl::ut::MoveArray<void*> unk2;

		virtual void* GetRuntimeTypeInfo() override;
		virtual void OnAddedToGame() override;
		virtual void OnRemovedFromGame() override;
		virtual void PreStepCallback(game::GameManager* gameManager, const game::GameStepInfo& gameStepInfo) override;
		virtual void PostGameUpdateCallback(game::GameManager* gameManager, const fnd::SUpdateInfo& updateInfo) override;

        void Setup(const SetupInfo& setupInfo);

        GAMESERVICE_CLASS_DECLARATION(EffectManager)
    };
}
