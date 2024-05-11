#pragma once

namespace SurfRide {
	struct SRS_CELLTEXTURE {
		uint32_t textureId;
		SrTexCoord texCoords[4];

		SRS_CELLTEXTURE();
	};


	struct SRS_CELL3D
	{
		uint32_t dword0;
		uint32_t qword4;
		uint32_t qword8;
		uint32_t qwordC;
		uint32_t qword10;
		SRS_CELLTEXTURE textures[2];
		uint32_t qword3C;
		Matrix44 transform;
		uint32_t qword78a;

		SRS_CELL3D();
	};
}
