#include "stdafx.h"
#include "RenderingWindow.h"


LRESULT RenderingWindow::MessageHandler( UINT const message,
                                         WPARAM const wparam,
                                         LPARAM const lparam )
{
    switch( message )
    {
        case WM_CREATE:
        {
            CreateHandler();
        } break;

        case WM_PAINT:
            {
                PaintHandler();
            }
            break;

        case WM_CLOSE:
            {
                DestroyWindow( m_window );
            }
            break;

        default:
            {
                return __super::MessageHandler
                (
                    message,
                    wparam,
                    lparam
                );
            }
    }

    return 0;
}

#pragma region Message Handlers

void RenderingWindow::CreateHandler()
{
    auto const monitor =
            MonitorFromWindow( m_window, MONITOR_DEFAULTTONEAREST );

    unsigned dpiX = 0;
    unsigned dpiY = 0;

    HR( GetDpiForMonitor( monitor,
                          MDT_EFFECTIVE_DPI,
                          &dpiX,
                          &dpiY
    ) );

    m_dpiX = static_cast<float>( dpiX );
    m_dpiY = static_cast<float>( dpiY );

    TRACE( L"DPI %.2f, %.2f\n", m_dpiX, m_dpiY );

    RECT size =
    {
        0,
        0,
        static_cast<unsigned>( LogicalToPhysical( m_WindowWidth, dpiX ) ),
        static_cast<unsigned>( LogicalToPhysical( m_WindowHeight, dpiY ) )
    };

    VERIFY( AdjustWindowRect(
            &size,
            GetWindowLong( m_window, GWL_STYLE ),
        false
        ) );

    VERIFY( SetWindowPos(
        m_window,
        nullptr,
        0, 0,
        size.right - size.left,
        size.bottom - size.top,
        SWP_NOACTIVATE | SWP_NOMOVE | SWP_NOZORDER
    ) );

    TRACE( L"Adjusted: %d %d %d %d\n", size.left, size.top, size.left - size.right, size.bottom - size.top );
}

void RenderingWindow::PaintHandler() const
{
    PAINTSTRUCT ps;
    auto hdc = BeginPaint( m_window, &ps );

    FillRect( hdc, &ps.rcPaint, reinterpret_cast<HBRUSH>( COLOR_WINDOW + 1 ) );

    EndPaint( m_window, &ps );
}

#pragma endregion

/*
int RenderingWindow::MessagePump()
{
    MSG message = {};

    while( true )
    {
        if( PeekMessage( &message, m_window, 0, 0, PM_REMOVE ) )
        {
            if( WM_QUIT == message.message )
            {
                break;
            }

            TranslateMessage( &message );
            DispatchMessage( &message );
        }
        else
        {
            Render();
        }
    }

    return message.wParam;
}
*/

void RenderingWindow::Render()
{
}
