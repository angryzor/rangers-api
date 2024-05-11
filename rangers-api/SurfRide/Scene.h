#pragma once

namespace SurfRide
{
	struct SRS_SCENE
	{
		const char* pName{};
		int ID{};
		int Flags{};
		int LayerCount{};
		SRS_LAYER* pLayers{};
		short CameraCount;
		short CurrentCameraIndex{};
		SRS_CAMERA* pCameras{};
		int BackgroundColor{};
		csl::math::Vector2 Resolution{};
		void* pUserData{};
	};

	class Project;
	class Scene : public ReferencedObject
	{
	public:
		SRS_SCENE* sceneData;
		Project* project;
		Camera camera;
		csl::ut::MoveArray<Layer*> layers;
		uint32_t unk1;
		uint32_t flags;

		Scene(const SRS_SCENE& sceneData, Project* project);

		Layer* GetLayer(const char* layers);
	};
}
