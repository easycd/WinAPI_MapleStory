#pragma once
#include "GameObject.h"
#include "Image.h"


class Animator;
class CircleObj : public GameObject
{
	enum class eCircleState
	{
		Raspawn,
		Fall,
		End,
		Destroy
	};

public:
	CircleObj();
	~CircleObj();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

	virtual void OnCollisionEnter(class Collider* other) override;

	void respawn();
	void fall();
	void end();
	void destroy();


	void SetFallTiming(int num)
	{
		FallTiming = num;
	}

private:
	Animator* m_Animator;
	Transform* mTransform;
	eCircleState mState;

	int FallCnt;
	int FallTiming;

	float m_Time;
	float FallTime;
	float Speed;

	bool Check;

};

