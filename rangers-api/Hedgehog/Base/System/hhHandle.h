#pragma once

namespace hh::fnd
{
	class HandleManager;
	class HandleBase
	{
	protected:
		uint32_t handle;

		void Set(const RefByHandleObject* pObj)
		{
			if (pObj)
			{
				handle = pObj->handle;
			}
		}
		
	public:
		HandleBase()
		{
			
		}
		
		HandleBase(const RefByHandleObject* pObj)
		{
			Set(pObj);
		}

        // TODO: fix
		RefByHandleObject* Get(HandleManager* handleManager) const;

		bool operator==(const RefByHandleObject* pObj)
		{
			return handle == pObj->handle;
		}

		bool operator!=(const RefByHandleObject* pObj)
		{
			return !operator==(pObj);
		}

		HandleBase& operator=(const RefByHandleObject* pObj)
		{
			Set(pObj);
			return *this;
		}

		HandleBase& operator=(const HandleBase& hObj)
		{
			handle = hObj.handle;
			return *this;
		}
	};

    //hh::fnd::Handle<hh::fnd::Messenger,hh::fnd::HandleManager<hh::fnd::Messenger>>
	template<class T>
	class Handle : public HandleBase
	{
	public:
		Handle()
		{
			
		}

		Handle(const T* pObj) : HandleBase(pObj)
		{
			
		}

		T* Get(HandleManager* handleManager) const
		{
			return reinterpret_cast<T*>(HandleBase::Get(handleManager));
		}

		Handle<T>& operator=(T* pObj)
		{
			Set(pObj);
			return *this;
		}

		Handle<T>& operator=(const Handle<T>& hObj)
		{
			handle = hObj.handle;
			return *this;
		}

		operator T*() const
		{
			return Get();
		}

		T* operator->() const
		{
			return Get();
		}
	};
}
