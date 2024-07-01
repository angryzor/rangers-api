#pragma once

namespace SurfRide
{
    struct SRS_PROJECT
    {
        const char* name{};
        short sceneCount{};
        short unk1{};
        short textureListCount{};
        short fontCount{};
        SRS_SCENE* scenes{};
        void* textureLists{}; // SRS_TEXTURELIST
        void* fonts{}; // SRS_FONT
        SRS_CAMERA camera{};
        int startFrame{};
        int endFrame{};
        float frameRate{};
        void* userData{};
    };

    class Project : public ReferencedObject
    {
        void LoadTextureListChunk(void* data, BinaryData& binaryData);
        void LoadProjectChunk(void* data, BinaryData& binaryData, bool cloneBinaryData);
    public:
        const SRS_PROJECT* projectData;
        void* textureLists;
        uint32_t textureListCount;
        csl::ut::MoveArray<SurfRide::Scene*> scenes;
        BinaryData* binaryData;
        void* binaryDataData;

        Project();
        static Project* Create(const BinaryData& binaryData, bool cloneBinaryData);
        SRS_CAMERA* GetCameraData();
        Scene* GetScene(const char* name);
    };
}
