#pragma once

namespace hh::eff {
    struct EffectCreateInfo {
        uint8_t unk1;
        uint8_t unk1a;
        uint8_t unk2;
        const char* resourceName;
        float unk4;
        uint32_t unk4a;
        uint64_t unk5;
        uint64_t unk6;
        uint32_t unk7;
        fnd::WorldPosition position;
        char unk8[16];
        gfx::GOCVisualModel* unkModel1;
        uint8_t unk9;
    };

    class EffectHandle {
        int unk1;
        void* unk2;
        EffectHandle();
    };

    class GOCEffect : public game::GOComponent {
    public:
        struct Description {
            uint32_t unk1;
            uint32_t unk2;
            float unk3;
            uint32_t unk4;
            int unk5;
            uint32_t unk6;
            uint8_t unk7;
            bool unk8;
        };

        struct EffectTransInfo {
            uint8_t unk1;
            uint8_t flags;
            unsigned short modelNodeIndex;
            gfx::GOCVisualModel* model;
            fnd::Reference<gfx::GOCVisualModel> model1;
            fnd::Reference<gfx::GOCVisualModel> model2;
            csl::math::Matrix34 transformationMatrix1;
            csl::math::Matrix34 transformationMatrix2;
        };

        uint64_t qword80;
        gfx::GOCVisualModel* unkModel1;
        float dword90;
        uint8_t byte94;
        int dword98;
        float dword9C;
        uint32_t dwordA0;
        gfx::GOCVisualModel* model;
        csl::ut::MoveArray<void*> unkB0;
        csl::ut::MoveArray<void*> unkD0;
        csl::ut::InplaceMoveArray<void*, 1> unkF0;
        uint32_t dword118;

		virtual void* GetRuntimeTypeInfo() override;
		virtual void GetDebugInfoMaybe() override;
		virtual void OnGOCEvent(GOCEvent event, game::GameObject& ownerGameObject, void* data) override;

        void SetModel(unsigned int* nameHash);
        void Setup(const Description& description);
        void SetupGlobalScale();
        csl::math::Matrix34 CalcEffectMatrix(const EffectTransInfo& transInfo);
        void SetupTransInfo(const EffectCreateInfo& createInfo, EffectTransInfo* transInfo);
        EffectHandle CreateEffectHandle(const char* resourceName, const csl::math::Matrix34& location, float unkParam2, const float* unkParam3, const EffectCreateInfo* createInfo);
        void CreateEffect(const char* resourceName, EffectHandle* handle);
        void CreateEffectEx(const EffectCreateInfo& createInfo, EffectHandle* handle);
        void CreateEffectLoop(const char* resourceName, EffectHandle* handle);
        void CreateEffectLoopEx(const EffectCreateInfo& createInfo, EffectHandle* handle);
        void CreateEffectPlain(const char* resourceName, const csl::math::Matrix34& location);
        void CreateEffectWorld(const char* resourceName, const csl::math::Matrix34& location, EffectHandle* handle);
        void StopEffect(EffectHandle handle, bool unkParam);
        void StopEffectAll(bool unkParam);

        GOCOMPONENT_CLASS_DECLARATION(GOCEffect)
    };
}
