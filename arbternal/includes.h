#pragma once
#include <Windows.h>
#include <d3d9.h>
#include <d3dx9.h>
#include <string>

#include <iostream>
#include "proton/hash.hpp"
#include "proton/rtparam.hpp"
#include "proton/variant.hpp"
#include "proton/vector.hpp"
#include "utils.hpp"

#include "minhook/include/MinHook.h"
#include "imgui/imgui.h"
#include "imgui/imgui_impl_win32.h"
#include "imgui/imgui_impl_dx9.h"

typedef uintptr_t PTR;
typedef long(__stdcall* EndScene)(LPDIRECT3DDEVICE9);
typedef LRESULT(CALLBACK* WNDPROC)(HWND, UINT, WPARAM, LPARAM);
