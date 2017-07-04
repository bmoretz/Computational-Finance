// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#define NOMINMAX

#include "targetver.h"

// Windows Header Files:
#include <windows.h>
#include <windowsx.h>
#include <shellscalingapi.h>

// Standard Libraries

#include <string>
#include <sstream>
#include <vector>
#include <cassert>

// Direct Composition

#include <wrl.h>
#include <dxgi.h>
#include <D2d1_2.h>
#include <d3d11.h>
#include <dcomp.h>
#include <dwrite.h>

#pragma comment(lib, "shcore")
#pragma comment(lib, "dxgi")
#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "D2d1.lib")
#pragma comment(lib, "dwrite.lib")
#pragma comment(lib, "dcomp.lib")