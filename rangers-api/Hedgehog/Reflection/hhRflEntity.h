#pragma once

namespace hh::fnd
{
	class RflEntity
	{
	protected:
    public:
		const char* m_pName{};

        const char* GetName() const
		{
			return m_pName;
		}
    };
}
