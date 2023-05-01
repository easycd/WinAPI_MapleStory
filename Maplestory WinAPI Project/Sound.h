#pragma once
#include "RResource.h"

class Sound : public RResource
{
public:
	virtual HRESULT Load(const std::wstring& path) override;
	bool LoadWavFile(const std::wstring& path);
	void Play(bool loop);
	void Stop(bool reset);
	void SetPosition(float position, bool loop);
	void SetVolume(float volume);
	int GetDecibel(float volume);

private:
	LPDIRECTSOUNDBUFFER		mSoundBuffer; //사운드 파일이 들어있는 버퍼
	DSBUFFERDESC			mBufferDesc; // 옵션
	int mVolume;
};

