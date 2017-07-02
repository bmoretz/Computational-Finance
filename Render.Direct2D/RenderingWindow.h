#pragma once

#include "stdafx.h"
#include "Window.h"

using namespace D2D1;
using namespace Microsoft::WRL;
using namespace std;

#define MAX_LOADSTRING 100

struct RenderingWindow : 
	Window<RenderingWindow>
{
    LRESULT MessageHandler( UINT const message,
		WPARAM const wparam,
		LPARAM const lparam ) override;

    //int MessagePump() override;

protected:

    void PaintHandler() const;

    void CreateHandler();

    static void Render();

    /*
    void CreateD3DDevice();
    void DestroyD3DDevice();

    void CreateD2DDevice();
    void DestroyD2DDevice();

    void CreateDXGIDevice();
    void DestroyDXGIDevice();

    void CreateDXFactory();
    void DestroyDXFactory();

    void CreateSwapChain();
    void DestroySwapChain();

    void CreateCompositionDevice();
    void DestroyCompositionDevice();
    */

private:

    #pragma region Device Independent

	float m_dpiX = 0.0f, m_dpiY = 0.0f;

	RECT m_clientRect = { };

	ComPtr<ID2D1Factory2> m_factory;
	ComPtr<ID2D1EllipseGeometry> m_geometry;

	#pragma endregion

    #pragma region Device Dependent

    ComPtr<ID3D11Device> m_d3dDevice;
    ComPtr<ID2D1Device> m_d2dDevice;
    ComPtr<IDXGIDevice> m_dxgiDevice;
    ComPtr<IDXGIFactory2> m_dxFactory;
    ComPtr<IDXGISwapChain1> m_swapChain;

    ComPtr<IDCompositionDevice> m_dcompDevice;
    ComPtr<IDCompositionTarget> m_target;
    ComPtr<IDCompositionVisual> m_visual;

	#pragma endregion
};