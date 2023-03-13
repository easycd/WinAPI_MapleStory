#include "Animator.h"
#include "RResources.h"

Animator::Animator()
	: Component(eComponentType::Animator)
	, mActiveAnimation(nullptr)
	, mSpriteSheet(nullptr)
	, mbLoop(false)
{

}
Animator::~Animator()
{
	for (auto animation : mAnimations)
	{
		delete animation.second;
		animation.second = nullptr;
	}
	for (auto events : mEvents)
	{
		delete events.second;
		events.second = nullptr;
	}
}
void Animator::Initialize()
{
}
void Animator::Update()
{
	if (mActiveAnimation) //NULL이 아니면
	{
		mActiveAnimation->Update();

		if (mbLoop && mActiveAnimation->IsComplete()) //애니메이션이 완료됐을때
		{
			Animator::Events* events
				= FindEvents(mActiveAnimation->GetName()); // 해당 애니메이션은 이름을 찾아옴.
			if (events != nullptr)
				events->mCompleteEvent();

			mActiveAnimation->Reset();
		}
	}
}
void Animator::Render(HDC hdc)
{
	if (mActiveAnimation)
	{
		mActiveAnimation->Render(hdc);
	}
}
void Animator::Release()
{
}

void Animator::CreateAnimation(const std::wstring& name
	, Image* sheet, Vector2 leftTop
	, UINT coulmn, UINT row, UINT spriteLength
	, Vector2 offset, float duration)
{
	Animation* animation = FindAnimation(name);

	if (animation != nullptr)
		return;

	animation = new Animation();
	animation->Create(sheet, leftTop, coulmn, row, spriteLength, offset, duration);
	animation->SetName(name);
	animation->SetAnimator(this); //애니메이션 연결

	mAnimations.insert(std::make_pair(name, animation));
	Events* event = new Events();
	mEvents.insert(std::make_pair(name, event));
}

void Animator::CreateAnimations(const std::wstring& path, Vector2 offset, float duration)
{
	UINT width = 0;
	UINT height = 0;
	UINT fileCount = 0;


	std::filesystem::path fs(path);
	std::vector<Image*> images = {};
	for (const auto& p : std::filesystem::recursive_directory_iterator(path))
	{
		std::wstring fileName = p.path().filename();
		std::wstring fullName = path + L"\\" + fileName;

		const std::wstring ext = p.path().extension();
		if (ext == L".png")
			continue;

		Image* image = RResources::Load<Image>(fileName, fullName);
		images.push_back(image);

		if (width < image->GetWidth())
		{
			width = image->GetWidth();
		}
		if (height < image->GetHeight())
		{
			height = image->GetHeight();
		}
		fileCount++;
	}

	std::wstring key = fs.parent_path().filename();
	key += fs.filename();
	mSpriteSheet = Image::Create(key, width * fileCount, height);

	int index = 0;
	for (Image* image : images)
		{
			int centerX = (width - image->GetWidth()) / 2;
			int centerY = (height - image->GetHeight());

			BitBlt(mSpriteSheet->GetHdc()
				, width * index + centerX
				, 0 + centerY
				, image->GetWidth(), image->GetHeight()
				, image->GetHdc(), 0, 0, SRCCOPY);
			index++;
		}
	CreateAnimation(key, mSpriteSheet, Vector2::Zero, index, 1, index, offset, duration);
}

Animation* Animator::FindAnimation(const std::wstring& name)
{
	std::map<std::wstring, Animation*>::iterator iter
		= mAnimations.find(name);

	if (iter == mAnimations.end())
		return nullptr;

	return iter->second;
}

void Animator::Play(const std::wstring& name, bool loop)
{
	//애니메이션 종료
	if (mActiveAnimation != nullptr)
	{
		Animator::Events* prevEvents
			= FindEvents(mActiveAnimation->GetName());

		if (prevEvents != nullptr)
			prevEvents->mEndEvent();  //end이벤트 호출
	}

	//애니메이션을 바꿔주고
	mActiveAnimation = FindAnimation(name);
	mActiveAnimation->Reset();
	mbLoop = loop;

	//바꿔준 애니메이션 호출
	Animator::Events* events
		= FindEvents(mActiveAnimation->GetName());

	if (events != nullptr)
		events->mStartEvent();

}

//void Animator::Play(const std::wstring& name, bool loop)
//{
//	mActiveAnimation = FindAnimation(name);
//	mbLoop = loop;
//}

//애니메이션 끝났을때 총알 나가고 이런것들 쓸때 쓰는 함수
Animator::Events* Animator::FindEvents(const std::wstring& name)
{
	std::map<std::wstring, Events*>::iterator iter
		= mEvents.find(name); //애니메이션의 이름을 찾아옴.

	if (iter == mEvents.end())
		return nullptr;

	return iter->second;
}

//애니메이션 시작 함수
std::function<void()>& Animator::GetStartEvent(const std::wstring& name)
{
	Animation* animation = FindAnimation(name); //애니메이션의 이름을 불러옴.

	Animator::Events* events
		= FindEvents(animation->GetName());

	return events->mStartEvent.mEvent;
}

//애니메이션 1번 돌았을때 함수
std::function<void()>& Animator::GetCompleteEvent(const std::wstring& name)
{
	Animation* animation = FindAnimation(name);

	Animator::Events* events
		= FindEvents(animation->GetName());

	return events->mCompleteEvent.mEvent;
}

//애니메이션 끝내는 함수
std::function<void()>& Animator::GetEndEvent(const std::wstring& name)
{
	Animation* animation = FindAnimation(name);

	Animator::Events* events
		= FindEvents(animation->GetName());

	return events->mEndEvent.mEvent;
}