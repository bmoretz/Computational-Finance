#pragma once

using namespace std;

extern "C" IMAGE_DOS_HEADER __ImageBase;

template <typename T>
struct Window
{
    virtual ~Window() = default;

    HWND m_window = nullptr;
	RECT m_clientRect = { };

    ULONG m_WindowWidth, m_WindowHeight = 0.0;

    static T* GetThisFromHandle( HWND const window )
    {
        return reinterpret_cast<T *>( GetWindowLongPtr( window, GWLP_USERDATA ) );
    }

    static LRESULT __stdcall WndProc( HWND const window,
                                      UINT const message,
                                      WPARAM const wparam,
                                      LPARAM const lparam )
    {
        ASSERT( window );

        if( WM_NCCREATE == message )
        {
            auto cs = reinterpret_cast<CREATESTRUCT *>( lparam );

            T *that = static_cast<T *>( cs->lpCreateParams );

            ASSERT( that );
            ASSERT( !that->m_window );

            that->m_window = window;

            SetWindowLongPtr( window, GWLP_USERDATA, reinterpret_cast<LONG_PTR>( that ) );
        }
        else if( message == WM_NCHITTEST )
        {
            auto result = DefWindowProc( window, message, wparam, lparam );

            if( result == HTCLIENT )
                result = HTCAPTION;

            return result;
        }
        else if( T *that = GetThisFromHandle( window ) )
        {
            return that->MessageHandler( message, wparam, lparam );
        }

        return DefWindowProc( window, message, wparam, lparam );
    }

    virtual LRESULT MessageHandler( UINT const message,
                                    WPARAM const wparam,
                                    LPARAM const lparam )
    {
        if( WM_DESTROY == message )
        {
            GetThisFromHandle( m_window )->DistroyWindow();

            PostQuitMessage( 0 );
        }
        else
        {
            return DefWindowProc( m_window, message, wparam, lparam );
        }

        return 0;
    }

    virtual int MessagePump()
    {
        MSG message = { nullptr };

        while( GetMessage( &message, nullptr, 0, 0 ) )
        {
            TranslateMessage( &message );
            DispatchMessage( &message );
        }

        return message.wParam;
    }

    virtual void DistroyWindow()
    {
        if( m_window != nullptr )
        {
            DestroyWindow( m_window );

            m_window = nullptr;
        }
    }
    
    HRESULT ShowMainWindow() const
    {
        auto hr = ( m_window == nullptr ) ? E_UNEXPECTED : S_OK;

        if( SUCCEEDED(hr) )
        {
            ShowWindow( m_window, SW_SHOW );
            UpdateWindow( m_window );
        }

        return hr;
    }

    virtual void CreateDesktopWindow( wstring windowClass, wstring windowTitle,
        float windowWidth = 640.0f, float windowHeight = 480.0f )
    {
        m_WindowWidth = windowWidth; m_WindowHeight = windowHeight;

        WNDCLASSEXW wcex = {};

        wcex.cbSize = sizeof( WNDCLASSEX);

        wcex.style = CS_HREDRAW | CS_VREDRAW;
        wcex.lpfnWndProc = WndProc;
        wcex.cbClsExtra = 0;
        wcex.cbWndExtra = 0;
        wcex.hInstance = reinterpret_cast<HINSTANCE>( &__ImageBase );
        wcex.hIcon = LoadIcon( nullptr, IDI_APPLICATION );
        wcex.hCursor = LoadCursor( nullptr, IDC_ARROW );
        wcex.hbrBackground = reinterpret_cast<HBRUSH>( COLOR_WINDOW + 1 );

        wcex.lpszClassName = windowClass.c_str();

        RegisterClassExW( &wcex );

        ASSERT( !m_window );

        VERIFY( CreateWindowEx(
                WS_EX_CLIENTEDGE,
                windowClass.c_str(),
                windowTitle.c_str(),
                WS_OVERLAPPEDWINDOW | WS_VISIBLE,
                CW_USEDEFAULT,
                CW_USEDEFAULT,
                m_WindowWidth,
                m_WindowHeight,
                nullptr,
                nullptr,
                wcex.hInstance,
                this
            ) 
        );

        ASSERT( m_window );
    }
};
