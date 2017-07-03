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

    void Render();

    void CreateHandler();

    void PaintHandler();
    void DpiHandler( const LPARAM wparam, const WPARAM lparam );
    void SizeHandler( const LPARAM wparam, const WPARAM lparam );

    bool IsDeviceCreated() const;

    void CreateDeviceResources();
    void ReleaseDeviceResources();

    void CreateDevice3D();
    void CreateDevice2D();
    void CreateCompositionDevice();

private:

    #pragma region Device Independent

    float m_rectSize = 0;

    D2D_SIZE_F m_size;
    D2D_POINT_2F m_dpi;

    RECT m_clientRect = {};

    ComPtr<ID2D1Factory2> m_factory;
    ComPtr<ID2D1EllipseGeometry> m_geometry;
    ComPtr<ID2D1SolidColorBrush> m_brush;

    #pragma endregion

    #pragma region Device Dependent

    ComPtr<ID3D11Device> m_device3d;
    ComPtr<ID2D1Device> m_device2d;
    ComPtr<IDXGIDevice> m_dxgiDevice;
    ComPtr<IDXGIFactory2> m_dxFactory;
    ComPtr<IDXGISwapChain1> m_swapChain;

    ComPtr<IDCompositionDesktopDevice> m_device;
    ComPtr<IDCompositionTarget> m_target;
    ComPtr<IDCompositionVisual2> m_visual;
    ComPtr<IDCompositionSurface> m_surface;

    #pragma endregion
};
