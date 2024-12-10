#include "engine.h"

#define DO_API(RetType, Name, Args) \
	Name##_t Name = NULL;

#include "il2cpp_api.h"

#undef DO_API

namespace Engine 
{

	HWND hWnd = NULL;
	HMODULE hUnityPlayer = NULL;
	HMODULE hGameAssembly = NULL;

	void Engine::Initialize()
	{
		hWnd = FindWindowA("UnityWndClass", NULL);
		hUnityPlayer = GetModuleHandleA("UnityPlayer.dll");
		hGameAssembly = GetModuleHandleA("GameAssembly.dll");


#define DO_API(RetType, Name, Args) \
	Name = (Name##_t)GetProcAddress(hGameAssembly,#Name);

#include "il2cpp_api.h"

#undef DO_API

		// printf("%p\n", il2cpp_field_get_name);

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

	string GetTypeName(const Il2CppType* pType)
	{
		return il2cpp_type_get_name(pType);
	}

	void* GetMethod(string AssemblyName, string Namespaze, string ClazzName)
	{
		Il2CppDomain* pDomain = il2cpp_domain_get();
		const Il2CppAssembly* pAssembly = il2cpp_domain_assembly_open(pDomain, AssemblyName.c_str());
		const Il2CppImage*  pImage = il2cpp_assembly_get_image(pAssembly);
		Il2CppClass* pClazz = il2cpp_class_from_name(pImage, Namespaze.c_str(), ClazzName.c_str());

		void* Iter = NULL;
		while (true)
		{
			const MethodInfo* pMethod = il2cpp_class_get_methods(pClazz, &Iter);
			if (pMethod == NULL)
				break;

			string temp = GetTypeName(il2cpp_method_get_return_type(pMethod));

		}
	}
}