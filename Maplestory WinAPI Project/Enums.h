#pragma once


enum class eSceneType
{
	Start,
	Login,
	CharSelect,
	Henesys,
	Somyeol,
	Arcana,
	Boss_Enter,
	Boss_Stage1,
	Boss_Stage2,
	Ending,
	End,
};

enum class eLayerType
{
	Wizet,
	BG,
	SoulEclipse,
	Object,
	SoulEclipseEffect,
	Portal,
	Monster,
	Skill,
	Player,
	PlayerGround,
	Ground,
	WallCollider,
	Effect,
	UI,
	End,
};

enum class eComponentType
{
	Transform,
	Collider,
	SpriteRenderer,
	Animator,
	Rigidbody,
	Audio,
	End,
};