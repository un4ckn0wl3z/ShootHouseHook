#include "engine.h"


namespace Engine 
{

	HMODULE hUnityPlayer = NULL;
	HWND hWnd = NULL;

	void Engine::Initialize()
	{
		hWnd = FindWindowA("UnityWndClass", NULL);
		hUnityPlayer = GetModuleHandleA("UnityPlayer.dll");
	}

	IDXGISwapChain* Engine::GetSwapChain()
	{
		uint8_t* temp = *(uint8_t**)((uint8_t*)hUnityPlayer + 0x17A84D8);
		return *(IDXGISwapChain**)(temp + 0x3A0);
	}

	HWND GethWnd()
	{
		return hWnd;
	}
}