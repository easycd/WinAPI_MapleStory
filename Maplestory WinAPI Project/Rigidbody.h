#pragma once
#include "Component.h"

	class Rigidbody : public Component
	{
	public:
		Rigidbody();
		~Rigidbody();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

		void SetMass(float mass) { mMass = mass; } // ���� ���� �Լ�
		void AddForce(Vector2 force); // ���� �������ټ� �ִ� �Լ�
		void SetGround(bool ground) { mbGround = ground; }
		void SetVelocity(Vector2 velocity) { mVelocity = velocity; }
		Vector2 GetVelocity() { return mVelocity; }

	private:
		float mMass; //����
		Vector2 mForce; //��ü�� �̵���Ű�� ��
		Vector2 mAccelation; //���ӵ�
		Vector2 mVelocity; //�ӵ�
		Vector2 mVelocity2;
		Vector2 mGravity; //�߷�
		Vector2 mLimitedVelocity;

		bool mbGround; //���� �پ����� �Ⱥپ����� üũ
		float mFriction; //������

		//float mStaticFriction; //����������
		//float mKineticFriction; //�������
		//float mCoefficientFriction; //������ ���
		//float mNormalForce; 
	};

