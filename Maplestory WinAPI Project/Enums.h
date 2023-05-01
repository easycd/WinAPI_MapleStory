#pragma once


enum class eSceneType
{
	Loding,
	Start,
	ChannelSelect,
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
	BossSkill,
	Object,
	SoulEclipseEffect,
	Portal,
	Monster,
	Boss,
	BossObj,
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