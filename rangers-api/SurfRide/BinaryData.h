#pragma once

namespace SurfRide
{
	class BinaryData : public ReferencedObject {
		void* data{};
	public:
		BinaryData(void* data);
	};
}
