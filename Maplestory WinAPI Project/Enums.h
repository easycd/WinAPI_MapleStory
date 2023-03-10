#pragma once


enum class eSceneType
{
	Login,
	CharSelect,
	Henesys,
	Somyeol,
	Arcana,
	Boss_Stage1,
	Boss_Stage2,
	Ending,
	End,
};

enum class eLayerType
{
	BG,
	Monster,
	Player,
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
	Audio,
	End,
};