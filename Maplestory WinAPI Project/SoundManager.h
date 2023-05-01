#pragma once
#include "CommonInclude.h"

class SoundManager
{
public:
	static bool Initialize();
	static LPDIRECTSOUND8 GetDevice() { return mSoundDevice; }

private:
	static LPDIRECTSOUND8 mSoundDevice;
};

