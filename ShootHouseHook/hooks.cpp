#include "hooks.h"
#include "utils.h"
#include "engine.h"

namespace Hooks
{
	bool bDx11Init = false;
	bool bDx11ReInit = false;
	Utils::VTableHook Dx11Hook;
	WNDPROC oWndProc = NULL;
	ID3D11Device* pDevice = nullptr;
	ID3D11DeviceContext* pDeviceContext = nullptr;
	IDXGISwapChain* pSwapChain = nullptr;
	ID3D11RenderTargetView* pRenderTargetView = nullptr;



	void Initialize()
	{
		oWndProc = (WNDPROC)SetWindowLongPtrA(Engine::GethWnd(), GWLP_WNDPROC, (LONG_PTR)hkWndProc);
		Dx11Hook.Initialize(Engine::GetSwapChain());
		Dx11Hook.Bind(8, hkPresent);
		Dx11Hook.Bind(13, hkResizeBuffers);
	}

	HRESULT WINAPI hkPresent(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags)
	{

		if (!bDx11Init)
		{
			pSwapChain->GetDevice(__uuidof(ID3D11Device), (void**)&pDevice);
			pDevice->GetImmediateContext(&pDeviceContext);

			ID3D11Texture2D* pBackBuffer;
			pSwapChain->GetBuffer(0, IID_PPV_ARGS(&pBackBuffer));
			pDevice->CreateRenderTargetView(pBackBuffer, nullptr, &pRenderTargetView);
			pBackBuffer->Release();

			if (!bDx11ReInit)
			{
				ImGui::CreateContext();
				ImGui::StyleColorsDark();
				ImGui_ImplWin32_Init(Engine::GethWnd());

				ImGuiIO& Io = ImGui::GetIO();
				Io.IniFilename = NULL;
				Io.LogFilename = NULL;
				// Io.Fonts->AddFontFromFileTTF("c:\\Windows\\Fonts\\ArialUni.ttf", 18.0f, nullptr, Io.Fonts->GetGlyphRangesJapanese());

			}

			ImGui_ImplDX11_Init(pDevice, pDeviceContext);
			bDx11Init = true;
			bDx11ReInit = true;

		}

		// ----------------------------------------------------------------


			// Start the Dear ImGui frame
		ImGui_ImplDX11_NewFrame();
		ImGui_ImplWin32_NewFrame();
		ImGui::NewFrame();

		static float f = 0.0f;
		static int counter = 0;

		ImGui::Begin("Hello, world!");                          // Create a window called "Hello, world!" and append into it.

		ImGui::Text("This is some useful text.");               // Display some text (you can use a format strings too)

		ImGui::SliderFloat("float", &f, 0.0f, 1.0f);            // Edit 1 float using a slider from 0.0f to 1.0f

		if (ImGui::Button("Button"))                            // Buttons return true when clicked (most widgets return true when edited/activated)
			counter++;
		ImGui::SameLine();
		ImGui::Text("counter = %d", counter);

		ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
		ImGui::End();


		// Rendering
		ImGui::Render();
		pDeviceContext->OMSetRenderTargets(1, &pRenderTargetView, nullptr);
		ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
		// ----------------------------------------------------------------

		return Dx11Hook.GetOriginal<decltype(&hkPresent)>(8)(pSwapChain, SyncInterval, Flags);
	}




	HRESULT WINAPI hkResizeBuffers(IDXGISwapChain* pSwapChain, UINT BufferCount, UINT Width, UINT Height, DXGI_FORMAT NewFormat, UINT SwapChainFlags)
	{

		if (bDx11Init)
		{
			pDevice->Release();
			pRenderTargetView->Release();
			ImGui_ImplDX11_Shutdown();
			bDx11Init = false;
		}

		return Dx11Hook.GetOriginal<decltype(&hkResizeBuffers)>(13)(pSwapChain, BufferCount, Width, Height, NewFormat, SwapChainFlags);
	}


	LRESULT WINAPI hkWndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		if (ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam))
			return true;


		return CallWindowProcA(oWndProc, hWnd, msg, wParam, lParam);

	}

}