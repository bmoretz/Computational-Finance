#pragma once

#include "stdafx.h"

using namespace D2D1;
using namespace Microsoft::WRL;
using namespace std;

class Application
{
public:
    explicit Application( HINSTANCE hInstance );
    ~Application();

    int Run();

private:

    static LRESULT CALLBACK WindowProc( HWND hWnd, UINT msg, WPARAM wparam, LPARAM lparam );

    HRESULT BeforeEnteringMessageLoop();
    static int EnterMessageLoop();
    void AfterLeavingMessageLoop();

    HRESULT CreateMainWindow();
    HRESULT ShowMainWindow() const;
    void DestroyMainWindow();

    static HRESULT EnableMouseAsPointerDevice();

    HRESULT CreateD3DDevice();
    void DestroyD3DDevice();

    HRESULT CreateD2DDevice();
    void DestroyD2DDevice();

    void CreateDXGIDevice();
    void DestroyDXGIDevice();

    void CreateDXFactory();
    void DestroyDXFactory();

    void CreateSwapChain();
    void DestroySwapChain();

    void RenderSurface() const;

    void CreateCompositionDevice();
    void DestroyCompositionDevice();

    LRESULT OnPointerUp( LPARAM lparam ) const;
    LRESULT OnClose();
    static LRESULT OnDestroy();

    #pragma region Window

    static Application *m_application;

    HINSTANCE m_hInstance;

    HWND m_hWnd;
    LONG m_hWndClientWidth;
    LONG m_hWndClientHeight;

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