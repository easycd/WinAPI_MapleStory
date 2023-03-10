//여러가지 헤더파일을 한번에 쓸수 있게 모아놓은 헤더파일


// Windows 헤더 파일
#include <windows.h>
// C 런타임 헤더 파일입니다.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <assert.h>

#include <string>
#include <vector>
#include <list>
#include <map>
#include <functional>
#include <filesystem> //파일 불러오는 헤더

#pragma comment(lib, "Msimg32.lib") // TransparentBlt 함수를 쓸 수있게 해주는 코드