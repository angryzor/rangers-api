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
		
		// AppMessage<T>* Clone() override
		// {
		// 	return new AppMessage<T>(ID);
		// }
	};
}