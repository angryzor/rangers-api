#pragma once

namespace SurfRide {
	struct SRS_TRS_BASE
	{
		Color materialColor{};
		Color illuminationColor{};
		bool visible{};
	};

	struct SRS_TRS2D : public SRS_TRS_BASE
	{
		Vector2 position{};
		uint32_t rotation{};
		Vector2 scale{};
		uint32_t unkX;
		uint32_t unkY;
	};

	struct SRS_TRS3D : public SRS_TRS_BASE
	{
		Vector3 position{};
		Rotation3 rotation{};
		Vector3 scale{};
	};

	class Layer;
	class Cast;
	class Transform {
	public:
		Vector3 position;
		Rotation3 rotation;
		Vector3 scale;
		Color materialColor;
		int32_t unk7;
		Color illuminationColor;
		int32_t unk8;
		bool visible;
		uint8_t unk9;
		uint32_t prefabFlags[12];
		uint32_t flags;
		Layer* layer;
		Cast* cast;
		uint64_t unk17;
		Matrix44 transformationMatrix;
		
		Transform(Layer* layer);
		void Initialize2D(SRS_TRS2D* cell, Cast* cast);
		void Initialize3D(SRS_TRS3D* cell, Cast* cast);
	};
}
