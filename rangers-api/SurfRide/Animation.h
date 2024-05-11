#pragma once

namespace SurfRide
{
	enum class SRE_CURVE_TYPE : uint16_t
	{
		TranslationX,
		TranslationY,
		TranslationZ,
		RotationX,
		RotationY,
		RotationZ,
		ScaleX,
		ScaleY,
		ScaleZ,
		MaterialColor,
		Display,
		Width,
		Height,
		VertexColorTopLeft,
		VertexColorTopRight,
		VertexColorBottomLeft,
		VertexColorBottomRight,
		CropIndex0,
		CropIndex1,
		Unknown,
		IlluminationColor,
		MaterialColorR,
		MaterialColorG,
		MaterialColorB,
		MaterialColorA,
		VertexColorTopLeftR,
		VertexColorTopLeftG,
		VertexColorTopLeftB,
		VertexColorTopLeftA,
		VertexColorTopRightR,
		VertexColorTopRightG,
		VertexColorTopRightB,
		VertexColorTopRightA,
		VertexColorBottomLeftR,
		VertexColorBottomLeftG,
		VertexColorBottomLeftB,
		VertexColorBottomLeftA,
		VertexColorBottomRightR,
		VertexColorBottomRightG,
		VertexColorBottomRightB,
		VertexColorBottomRightA,
		IlluminationColorR,
		IlluminationColorG,
		IlluminationColorB,
		IlluminationColorA,
	};

	enum class SRE_TRACK_FLAG : uint16_t {
		CONSTANT = 0x0,
		LINEAR = 0x1,
		HERMITE = 0x2,
		INDIVIDUAL = 0x3,

		FLOAT = 0x10,
		INDEX = 0x20,
		BOOL = 0x30,
		INT = 0x40,
		COLOR = 0x50,

		// These are uncertain
		UNK_FLOAT = 0x60,
		UNK_DOUBLE = 0x70, // Types say double, but used for what? Won't interpolate linearly.
		UNK_CHAR = 0x80, // Char? doubt
	};

	enum class SRE_INTERPOLATION_TYPE : uint32_t {
		CONSTANT,
		LINEAR,
		HERMITE,
	};

	struct SRS_KEYFRAME
	{
		uint32_t frame{};
	};

	template<typename T>
	struct Key : public SRS_KEYFRAME {
		T value;
	};

    template<typename T>
    struct KeyLinear : public Key<T> {
    };

    template<typename T>
    struct KeyHermite : public Key<T> {
		T derivativeIn;
		T derivativeOut;
    };

    template<typename T>
    struct KeyIndividual : public Key<T> {
		T derivativeIn;
		T derivativeOut;
		SRE_INTERPOLATION_TYPE interpolationType;
    };

	struct SRS_TRACK
	{
		SRE_CURVE_TYPE trackType{};
		uint16_t keyCount{};
		SRE_TRACK_FLAG flags{};
		uint32_t firstFrame{};
		uint32_t lastFrame{};
		SRS_KEYFRAME* keyFrame{};
	};

	struct SRS_MOTION
	{
		uint16_t castId{};
		uint16_t trackCount{};
		SRS_TRACK* tracks{};
	};

	struct SRS_ANIMATION
	{
		const char* name{};
		uint32_t id{};
		uint32_t linkCount{};
		uint32_t frameCount{};
		SRS_MOTION* links{};
		void* userData{};
		bool isLooping{};
	};
}