#pragma once
#include "Entity.h"
#include "Component.h"

	class GameObject : public Entity // 이름 쓸려고 상속 받음 ex) 몬스터1 몬스터2
	{
	public:
		enum class eState
		{
			Active,
			Pause,
			Death,
		};

		GameObject();
		virtual ~GameObject();

		virtual void Initialize();
		virtual void Update();
		virtual void Render(HDC hdc);
		virtual void Release();

		virtual void OnCollisionEnter(class Collider* other);
		virtual void OnCollisionStay(class Collider* other);
		virtual void OnCollisionExit(class Collider* other);

		template <typename T>
		T* AddComponent()
		{
			T* comp = new T();
			UINT compType = (UINT)comp->GetType();
			mComponents[compType] = comp;
			comp->SetOwner(this);

			return comp;
		}

		template <typename T>
		T* GetComponent()
		{
			for (Component* comp : mComponents)
			{
				if (dynamic_cast<T*>(comp))
					return dynamic_cast<T*>(comp);
			}

			return nullptr;
		}


		template <typename T>
		std::vector<T*> GetComponents()
		{
			std::vector<T*> components;

			for (Component* comp : mComponents)
			{
				if (dynamic_cast<T*>(comp))
					components.push_back(comp);
			}

			return components;
		}
		

		eState GetState() { return mState; }
		void SetState(eState state) { mState = state; }
	private:
		std::vector<Component*> mComponents;
		eState mState;
	};


