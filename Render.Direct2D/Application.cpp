#include "stdafx.h"
#include "Application.h"
#include "Common.h"

Application *Application::m_application = nullptr;

#pragma region Window Callback

LRESULT CALLBACK Application::WindowProc( HWND hWnd, UINT msg, WPARAM wparam, LPARAM lparam )
{
    LRESULT result = 0;

    switch( msg )
    {
        case WM_POINTERUP:
            {
                result = m_application->OnPointerUp( lparam );
                break;
            }

        case WM_PAINT:
            {
            }
            break;

        case WM_CLOSE:
            {
                result = m_application->OnClose();
                break;
            }

        case WM_DESTROY:
            {
                result = m_application->OnDestroy();
                break;
            }

        default:
            {
                result = DefWindowProc( hWnd, msg, wparam, lparam );
                break;
            }
    }

    return result;
}

#pragma endregion

// Provides the entry point to the application and defines client size
Application::Application( HINSTANCE hInstance ) :
    m_hInstance( hInstance ),
    m_hWnd( nullptr ),
    m_hWndClientWidth( 512 ),
    m_hWndClientHeight( 512 )
{
    m_application = this;
}

Application::~Application()
{
    m_application = nullptr;
}

// Runs the application
int Application::Run()
{
    auto result = 0;

    if( SUCCEEDED( BeforeEnteringMessageLoop() ) )
    {
        result = EnterMessageLoop();
    }

    AfterLeavingMessageLoop();

    return result;
}

// Initialization for the application window, devices and
// DComp resources before entering the message loop
HRESULT Application::BeforeEnteringMessageLoop()
{
    auto hr = S_OK;

    if( SUCCEEDED( hr ) )
    {
        hr = CreateMainWindow();
    }

    if( SUCCEEDED( hr ) )
    {
        hr = CreateD3DDevice();
    }

    if( SUCCEEDED( hr ) )
    {
        hr = CreateD2DDevice();
    }

    CreateDXGIDevice();
    CreateDXFactory();
    CreateSwapChain();

    if( SUCCEEDED( hr ) )
    {
        hr = ShowMainWindow();
    }

    if( SUCCEEDED( hr ) )
    {
        hr = EnableMouseAsPointerDevice();
    }

    RenderSurface();

    CreateCompositionDevice();

    return hr;
}

// Message loop
int Application::EnterMessageLoop()
{
    MSG message = { nullptr };

    while( GetMessage( &message, nullptr, 0, 0 ) )
    {
        TranslateMessage( &message );
        DispatchMessage( &message );
    }

    return static_cast<int>( message.wParam );
}

// Destroys the application window, devices and DComp resources
void Application::AfterLeavingMessageLoop()
{
    DestroyCompositionDevice();

    DestroyDXFactory();

    DestroyDXFactory();

    DestroySwapChain();

    DestroyD2DDevice();

    DestroyD3DDevice();

    DestroyMainWindow();
}

// Creates the application window
HRESULT Application::CreateMainWindow()
{
    auto hr = S_OK;

    if( SUCCEEDED( hr ) )
    {
        WNDCLASSEX wcex = { 0 };

        wcex.cbSize = sizeof ( wcex );
        wcex.style = CS_HREDRAW | CS_VREDRAW;
        wcex.lpfnWndProc = WindowProc;
        wcex.cbClsExtra = 0;
        wcex.cbWndExtra = 0;
        wcex.hInstance = m_hInstance;
        wcex.hIcon = nullptr;
        wcex.hCursor = LoadCursorW( nullptr, IDC_ARROW );
        wcex.hbrBackground = static_cast<HBRUSH>( GetStockObject( WHITE_BRUSH ) );
        wcex.lpszMenuName = nullptr;
        wcex.lpszClassName = L"MainWindowClass";
        wcex.hIconSm = nullptr;

        hr = ( RegisterClassEx( &wcex ) == 0 ) ? E_FAIL : S_OK;

        //ShowMessageBoxIfFailed( hr, L"RegisterClassEx" );
    }

    if( SUCCEEDED(hr) )
    {
        RECT windowRect = { 0, 0, m_hWndClientWidth, m_hWndClientHeight };

        hr = ( AdjustWindowRect( &windowRect, WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX, FALSE ) == FALSE ) ? E_FAIL : S_OK;

        //ShowMessageBoxIfFailed( hr, L"AdjustWindowRect" );

        if( SUCCEEDED(hr) )
        {
            m_hWnd = CreateWindowExW
            (
                0,
                L"MainWindowClass",
                L"DirectComposition",
                WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX,
                0,
                0,
                windowRect.right - windowRect.left,
                windowRect.bottom - windowRect.top,
                nullptr,
                nullptr,
                m_hInstance,
                nullptr
            );

            hr = ( m_hWnd == nullptr ) ? E_FAIL : S_OK;

            //ShowMessageBoxIfFailed( hr, L"CreateWindowExW" );
        }
    }

    return hr;
}

// Shows the application window 
HRESULT Application::ShowMainWindow() const
{
    auto hr = ( m_hWnd == nullptr ) ? E_UNEXPECTED : S_OK;

    if( SUCCEEDED(hr) )
    {
        ShowWindow( m_hWnd, SW_SHOW );
        UpdateWindow( m_hWnd );
    }

    return hr;
}

// Destroys the application window 
void Application::DestroyMainWindow()
{
    if( m_hWnd != nullptr )
    {
        DestroyWindow( m_hWnd );
        m_hWnd = nullptr;
    }
}

// Enables mouse pointer device for hit-testing
HRESULT Application::EnableMouseAsPointerDevice()
{
    auto hr = S_OK;

    if( !IsMouseInPointerEnabled() )
    {
        hr = ( EnableMouseInPointer( TRUE ) == FALSE ) ? E_FAIL : S_OK;
    }

    return hr;
}

#pragma region Create Composition Devices

HRESULT Application::CreateD3DDevice()
{
    auto hr = m_d3dDevice != nullptr ? E_UNEXPECTED : S_OK;

    //ShowMessageBoxIfFailed( hr, L"(m_d3dDevice != nullptr)" );

    if( SUCCEEDED( hr ) )
    {
        ComPtr<ID3D11Device> d3dDevice;

        hr = D3D11CreateDevice
        (
            nullptr,
            D3D_DRIVER_TYPE_HARDWARE,
            nullptr,
            D3D11_CREATE_DEVICE_BGRA_SUPPORT,
            nullptr,
            0,
            D3D11_SDK_VERSION,
            &d3dDevice,
            nullptr,
            nullptr
        );

        //ShowMessageBoxIfFailed( hr, L"::D3D11CreateDevice" );

        if( SUCCEEDED( hr ) )
        {
            m_d3dDevice = d3dDevice.Detach();
        }
    }

    return hr;
}

void Application::DestroyD3DDevice()
{
    m_d3dDevice = nullptr;
}

HRESULT Application::CreateD2DDevice()
{
    auto hr = m_d3dDevice == nullptr || m_d2dDevice != nullptr ? E_UNEXPECTED : S_OK;

    //ShowMessageBoxIfFailed( hr, L"((m_d3dDevice == nullptr) || (m_d2dDevice != nullptr))" );

    if( SUCCEEDED( hr ) )
    {
        ComPtr<IDXGIDevice> dxgiDevice;

        HR( m_d3dDevice.As( &dxgiDevice ), L"" );

        //ShowMessageBoxIfFailed( hr, L"m_d3dDevice->QueryInterface" );

        HR( D2D1CreateDevice( dxgiDevice.Get(), nullptr, &m_d2dDevice ), L"D2D1CreateDevice" );

        //ShowMessageBoxIfFailed( hr, L"::D2D1CreateDevice" );
    }

    return hr;
}

void Application::DestroyD2DDevice()
{
    m_d2dDevice = nullptr;
}

void Application::CreateDXGIDevice()
{
    HR( m_d3dDevice.As( &m_dxgiDevice ), L"" );
}

void Application::DestroyDXGIDevice()
{
    m_dxgiDevice = nullptr;
}

void Application::CreateCompositionDevice()
{
    HR( DCompositionCreateDevice( m_dxgiDevice.Get(), __uuidof(IDCompositionDevice), reinterpret_cast<void **>( m_dcompDevice.GetAddressOf() ) ), L"" );
    HR( m_dcompDevice->CreateTargetForHwnd( m_hWnd, true, m_target.GetAddressOf() ), L"" );
    HR( m_dcompDevice->CreateVisual( m_visual.GetAddressOf() ), L"" );
    HR( m_visual->SetContent( m_swapChain.Get() ), L"" );
    HR( m_target->SetRoot( m_visual.Get() ), L"" );
    HR( m_dcompDevice->Commit(), L"" );
}

void Application::DestroyCompositionDevice()
{
    m_dcompDevice = nullptr;
    m_target = nullptr;
    m_visual = nullptr;
}

#pragma endregion

void Application::RenderSurface() const
{
    // Create a single-threaded Direct2D factory with debugging information

    ComPtr<ID2D1Factory2> d2Factory;
    D2D1_FACTORY_OPTIONS const options = { D2D1_DEBUG_LEVEL_INFORMATION };

    HR( D2D1CreateFactory( D2D1_FACTORY_TYPE_SINGLE_THREADED,
                           options,
                           d2Factory.GetAddressOf() ),
        L"D2D1CreateFactory" );

    // Create the Direct2D device that links back to the Direct3D device
    ComPtr<ID2D1Device1> d2Device;
    HR( d2Factory->CreateDevice( m_dxgiDevice.Get(), d2Device.GetAddressOf() ), L"d2Factory->CreateDevice" );

    // Create the Direct2D device context that is the actual render target
    // and exposes drawing commands
    ComPtr<ID2D1DeviceContext> dc;
    HR( d2Device->CreateDeviceContext( D2D1_DEVICE_CONTEXT_OPTIONS_NONE,
                                       dc.GetAddressOf() ),
        L"d2Device->CreateDeviceContext" );

    // Retrieve the swap chain's back buffer
    ComPtr<IDXGISurface2> surface;
    HR( m_swapChain->GetBuffer( 0, __uuidof(IDXGISurface2), reinterpret_cast<void **>( surface.GetAddressOf() ) ), L"m_swapChain->GetBuffer" );

    // Create a Direct2D bitmap that points to the swap chain surface

    D2D1_BITMAP_PROPERTIES1 properties = {};
    properties.pixelFormat.alphaMode = D2D1_ALPHA_MODE_PREMULTIPLIED;
    properties.pixelFormat.format = DXGI_FORMAT_B8G8R8A8_UNORM;
    properties.bitmapOptions = D2D1_BITMAP_OPTIONS_TARGET | D2D1_BITMAP_OPTIONS_CANNOT_DRAW;

    ComPtr<ID2D1Bitmap1> bitmap;
    HR( dc->CreateBitmapFromDxgiSurface( surface.Get(), properties, bitmap.GetAddressOf() ), L"" );

    // Point the device context to the bitmap for rendering
    dc->SetTarget( bitmap.Get() );
    // Draw something
    dc->BeginDraw();

    dc->Clear();
    ComPtr<ID2D1SolidColorBrush> brush;

    auto const brushColor =
            static_cast<_D3DCOLORVALUE>( ColorF( 0.18f, // red
                                                 0.55f, // green
                                                 0.34f, // blue
                                                 0.75f ) ); // alpha

    HR( dc->CreateSolidColorBrush( brushColor, brush.GetAddressOf() ), L"" );

    auto const ellipseCenter = Point2F( 150.0f, // x
                                        150.0f ); // y

    auto const ellipse = D2D1::Ellipse( ellipseCenter,
                                        100.0f, // x radius
                                        100.0f ); // y radius
    dc->FillEllipse( ellipse, brush.Get() );

    HR( dc->EndDraw(), L"dc->EndDraw" );

    // Make the swap chain available to the composition engine
    HR( m_swapChain->Present( 1, // sync
                              0 ), // flags    
        L"SwapChain->Present" );
}

void Application::CreateDXFactory()
{
    HR( CreateDXGIFactory2( DXGI_CREATE_FACTORY_DEBUG,
                            __uuidof( IDXGIFactory2),
                            reinterpret_cast<void **>( m_dxFactory.GetAddressOf() ) ),
        L"CreateDXGIFactory2" );
}

void Application::DestroyDXFactory()
{
    m_dxFactory = nullptr;
}

void Application::CreateSwapChain()
{
    DXGI_SWAP_CHAIN_DESC1 description = {};

    description.Format = DXGI_FORMAT_B8G8R8A8_UNORM;
    description.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    description.SwapEffect = DXGI_SWAP_EFFECT_FLIP_SEQUENTIAL;
    description.BufferCount = 2;
    description.SampleDesc.Count = 1;
    description.AlphaMode = DXGI_ALPHA_MODE_PREMULTIPLIED;
    description.Width = m_hWndClientWidth;
    description.Height = m_hWndClientHeight;

    assert( m_dxFactory != nullptr );
    assert( m_dxgiDevice != nullptr );

    HR( m_dxFactory->CreateSwapChainForComposition( m_dxgiDevice.Get(),
                                                    &description,
                                                    nullptr,
                                                    m_swapChain.GetAddressOf() ),
        L"CreateSwapChainForComposition" );
}

void Application::DestroySwapChain()
{
    m_swapChain = nullptr;
}

// Hit-testing visual
LRESULT Application::OnPointerUp( LPARAM lparam ) const
{
    POINT p = { GET_X_LPARAM(lparam), GET_Y_LPARAM(lparam) };

    ScreenToClient( m_hWnd, &p );

    return 0;
}

LRESULT Application::OnClose()
{
    if( m_hWnd != nullptr )
    {
        DestroyWindow( m_hWnd );
        m_hWnd = nullptr;
    }

    return 0;
}

LRESULT Application::OnDestroy()
{
    PostQuitMessage( 0 );

    return 0;
}
