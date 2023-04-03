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
	Monster,
	Player,
	Skill,
	Ground,
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