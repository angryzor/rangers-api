#pragma once

namespace app::fnd
{
	template <typename T>
	class AppMessage : public hh::fnd::Message
	{
	public:
		AppMessage(hh::fnd::MessageID in_id) : Message(in_id)
		{
			
		}
		
		virtual uint32_t UnkFunc1() { return 0; }
	};
}