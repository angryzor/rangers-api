#pragma once

namespace SurfRide {
    class CastListener {
    public:
        virtual ~CastListener();
        virtual void* GetRuntimeTypeInfo();
        virtual int64_t Unk1();
        virtual int64_t Unk2();
        virtual int64_t Unk3();
        virtual int64_t Unk4();
        virtual int64_t Unk5();
        virtual int64_t Unk6();
        virtual int64_t Unk7();
        virtual int64_t Unk8();
    };

	struct SRS_CASTNODE
	{
        enum class Type {
            NORMAL,
            IMAGE,
            SLICE,
            REFERENCE,
        };

		const char* name{};
		int id{};
		int flags{}; // 0xF mask -> Type
		void* data{};
		short childIndex{};
		short siblingIndex{};
		SRS_USERDATA* userData{};
	};

    class Scene;
    class Cast : public ReferencedObject {
    public:
		struct Unk1 {
			// This is actually an unknown structure containing this movearray, it's used in multiple resources.
			csl::ut::MoveArray<void*> unk1;
			Cast* cast;
			Unk1(csl::fnd::IAllocator* allocator);
		};

        Transform* transform;
        RefPtr<Blur> blurEffect;
        RefPtr<Reflect> reflectEffect;
        uint32_t unk4;
        uint64_t unk5;
        const SRS_CASTNODE* castData;
        Layer* layer;
        Cast* parentCast;
        csl::ut::MoveArray<SurfRide::Cast*> children;
        SRS_MOTION* motion;
        uint32_t flags;
        bool unk8;
        bool is3D;
        uint16_t unk9;
        uint16_t unk9a;
        uint64_t unk10;
        Vector3 position;
        Unk1 unk12;
        bool unk14;

        Cast(SRS_CASTNODE* castData, Cast* parentCast, Layer* layer);
        UserData GetUserData();
        void SetFlag1000(bool enabled);
        void InitializeTransform2D(Transform* transform, SRS_TRS2D* cell);
        void InitializeTransform3D(Transform* transform, SRS_TRS3D* cell);
        Scene* GetScene();
        void CreateEffectCast(void* effectData);
        void* GetTextureListData(int id) const;

        virtual void* GetRuntimeTypeInfo() const;
        virtual bool UnkFunc2();
        virtual uint64_t UnkFunc3() {}
        virtual void CalcTrackTypeWidth(float time, const SRS_TRACK* track) {}
        virtual void CalcTrackTypeHeight(float time, const SRS_TRACK* track) {}
        virtual void CalcTrackTypeCropIndex0(float time, const SRS_TRACK* track) {}
        virtual void CalcTrackTypeCropIndex1(float time, const SRS_TRACK* track) {}
        virtual void* GetCellProbably() const { return nullptr; }
        virtual void SetCellProbably(void* cell) {}
        virtual unsigned int GetCellCount() const { return 0; }
        virtual void UpdateThis(float time, const Cast* parentCast);
        virtual uint64_t UnkFunc12();
    };
}
