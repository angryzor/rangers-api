#pragma once

namespace SurfRide
{
	struct SRS_PROJECT;
	struct SRS_SCENE;
	struct SRS_LAYER;
	struct SRS_CASTNODE;
	struct SRS_ADDRESS_RESOLUTION_HEADER {
		uint32_t unk1;
		uint32_t unk2;
		uint32_t addressToResolveCount;
		uint32_t isResolved; // 0 if not, 1 if yes
		// uint32_t addressOffsets[];
	};

	struct SRS_CHUNK_HEADER {
		uint32_t magic;
		uint32_t chunkSize;
	};

	struct SRS_PROJECT_CHUNK {
		SRS_CHUNK_HEADER header;
		uint32_t startOffset;
		uint32_t unk1;
	};

	struct SRS_TEXTURE_LIST_CHUNK {
		SRS_CHUNK_HEADER header;
		uint32_t startOffset;
		uint32_t textureListCount;
	};

	struct SRS_BINARY_FILE_HEADER_CHUNK {
		SRS_CHUNK_HEADER chunkHeader;
		uint32_t unk2;
		uint32_t unk3;
		uint32_t unk4;
		uint32_t addressResolutionHeaderOffset;

		struct ChunkInfo {
			SRS_PROJECT_CHUNK* projectChunk;
			SRS_TEXTURE_LIST_CHUNK* textureListChunk;

			unsigned int GetTextureListCount() const;
			TextureListIterator GetTextureListIteratorBegin() const;
			TextureListIterator GetTextureList(unsigned int) const;
			ProjectIterator GetProject() const;
		};

		static ChunkInfo GetChunkInfo(void* data);
	};

	class BinaryData : public ReferencedObject {
		void* data{};
	public:
		BinaryData(void* data);
		void ResolveAddress();
		static void ResolveAddress(void* data);
		Project* ApplyMemoryImageToProject(bool unkParam);
		SRS_BINARY_FILE_HEADER_CHUNK* GetBinaryFileHeader();
		void ResetAddress(void* start, void* end, unsigned int size);
	};

	Project* ApplyMemoryImageToProject(void* image, bool unkParam);
}
