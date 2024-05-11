#pragma once

namespace SurfRide
{
	struct SRS_CAMERA
	{
		const char* name{};
		int id{};
		csl::math::Vector3 position{};
		csl::math::Vector3 target{};
		int flags{};
		int fov;
		float nearPlane{};
		float farPlane{};
		uint64_t unk;
	};

	class Camera
	{
	public:
		SRS_CAMERA camera;
		csl::math::Matrix44 viewMatrix;
		csl::math::Matrix44 projectionMatrix;

		Camera(const SRS_CAMERA& camera, float resolutionX, float resolutionY);
	};
}
