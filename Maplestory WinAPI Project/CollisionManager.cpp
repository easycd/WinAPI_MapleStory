#include "CollisionManager.h"
#include "Scene.h"
#include "SceneManager.h"

WORD CollisionManager::mMatrix[(UINT)eLayerType::End] = {};
std::map<UINT64, bool> CollisionManager::mCollisionMap;
void CollisionManager::Update()
{
	Scene* scene = SceneManager::GetActiveScene();

	for (UINT row = 0; row < (UINT)eLayerType::End; row++)
	{
		for (UINT col = 0; col < (UINT)eLayerType::End; col++)
		{
			if (mMatrix[row] & (1 << col))
			{
				LayerCollision(scene, (eLayerType)row, (eLayerType)col);
			}

		}
	}
}

void CollisionManager::LayerCollision(Scene* scene, eLayerType left, eLayerType right)
{
	 std::vector<GameObject*>& lefts = scene->GetGameObjects(left); //몬스터
	 std::vector<GameObject*>& rights = scene->GetGameObjects(right); // 플레이어

	for (auto leftObject : lefts)
	{
		//충돌체가 없으면 건너뜀
		Collider* leftCollider = leftObject->GetComponent<Collider>();
		if (leftCollider == nullptr)
			continue;

		for (auto rightObject : rights)
		{
			//충돌체가 없으면 건너뜀
			Collider* rightCollider = rightObject->GetComponent<Collider>();
			if (rightCollider == nullptr)
				continue;

			if (leftObject == rightObject)
				continue;

			ColliderCollision(leftCollider, rightCollider, left, right); //충돌체 끼리 충돌했는지 확인

		}
	}

}

//충돌하고 있는지 아닌지 상태 확인하는 함수
void CollisionManager::ColliderCollision(Collider* leftCol, Collider* rightCol, eLayerType left, eLayerType right)
{
	ColliderID collidrID = {};
	collidrID.left = (UINT)leftCol->GetID();
	collidrID.right = (UINT)rightCol->GetID();

	std::map<UINT64, bool>::iterator iter = mCollisionMap.find(collidrID.id); //이미 충돌 중인 경우

	if (iter == mCollisionMap.end()) //충돌한적이 없을 때
	{
		mCollisionMap.insert(std::make_pair(collidrID.id, false));
		iter = mCollisionMap.find(collidrID.id);
	}

	//충돌했을때 이벤트
	if (Intersect(leftCol, rightCol))
	{
		//최초 충돌을 시작했을 떄 Enter
		if (iter->second == false)
		{
			leftCol->OnCollisionEnter(rightCol);
			rightCol->OnCollisionEnter(leftCol);

			iter->second = true;
		}
		//충돌 중인 상태
		else
		{
			leftCol->OnCollisionStay(rightCol);
			rightCol->OnCollisionStay(leftCol);
		}
	}
	else // 충돌 X
	{

		//이전프레임 충돌 했지만 현재는 충돌 안했을 때 Exit
		if (iter->second == true)
		{
			leftCol->OnCollisionExit(rightCol);
			rightCol->OnCollisionExit(leftCol);

			iter->second = false;
		}
	}
}

bool CollisionManager::Intersect(Collider* left, Collider* right)
{
	Vector2 leftPos = left->GetPos();
	Vector2 rightPos = right->GetPos();

	// 두 충돌체 간의 거리와, 각면적의 절반끼리의 합을 비교해서
	// 거리가 더 길다면 충돌 X, 거리가 더 짧다면 충돌 O
	Vector2 leftSize = left->GetSize();
	Vector2 rightSize = right->GetSize();

	leftPos.x = leftPos.x + leftSize.x / 2.0f;
	leftPos.y = leftPos.y + leftSize.y / 2.0f;

	rightPos.x = rightPos.x + rightSize.x / 2.0f;
	rightPos.y = rightPos.y + rightSize.y / 2.0f;

	//fabs = 절댓값 구해주는 함수.
	if (fabs(leftPos.x - rightPos.x) < (leftSize.x / 2.0f) + (rightSize.x / 2.0f)
		&& fabs(leftPos.y - rightPos.y) < (leftSize.y / 2.0f) + (rightSize.y / 2.0f))
	{
		return true; //충돌
	}

	return false; //충돌 안함
}

void CollisionManager::SetLayer(eLayerType left, eLayerType right, bool value)
{
	UINT row = 0;
	UINT col = 0;

	UINT ileft = (UINT)left;
	UINT iright = (UINT)right;

	if (left <= right)
	{
		row = ileft;
		col = iright;
	}
	else
	{
		row = iright;
		col = ileft;
	}

	if (value == true)
		mMatrix[row] |= (1 << col);
	else
		mMatrix[row] &= ~(1 << col);
}

void CollisionManager::Clear()
{
	memset(mMatrix, 0, sizeof(WORD) * (UINT)eLayerType::End);
	mCollisionMap.clear();
}