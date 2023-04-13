#pragma once
#include "CommonInclude.h"
#include "Enums.h"
#include "Math.h"

#define SAFE_DELETE(p)	if(p)	{delete p; p = nullptr;}