#pragma once
#include "CommonInclude.h"
#include "Enums.h"
#include "Collider.h"

union ColliderID
{
	struct
	{
			//64비트를 반으로 쪼개서 씀
		UINT32 left;
		UINT32 right;
	};
	UINT64 id; //id를 가져올땐 64비트
};

class Scene;
class CollisionManager
{
  public:
	static void Update();
	static void LayerCollision(Scene* scene, eLayerType left, eLayerType right);
	static void ColliderCollision(Collider* leftCol, Collider* rightCol, eLayerType left, eLayerType right); //충돌체끼리 충돌된 상태인지 확인
	static bool Intersect(Collider* left, Collider* right);

	static void SetLayer(eLayerType left, eLayerType right, bool value);
	static void Clear();

  private:
	static WORD mMatrix[(UINT)eLayerType::End];
	static std::map<UINT64, bool> mCollisionMap; //어떤 레이어랑 충돌중인지 기록
};



