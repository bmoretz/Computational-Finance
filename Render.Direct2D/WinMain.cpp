#include "stdafx.h"
#include "RenderingWindow.h"

//Provides the entry point to the application
int __stdcall wWinMain( _In_ HINSTANCE hInstance, 
    _In_opt_ HINSTANCE hPrevInstance, 
    _In_ LPWSTR cmdLine, 
    _In_ int cmdShow )
{
    UNREFERENCED_PARAMETER( hPrevInstance );
    UNREFERENCED_PARAMETER( cmdLine );
    UNREFERENCED_PARAMETER( cmdShow );

	RenderingWindow window;

    window.CreateDesktopWindow( L"TemplateWnd", L"Template Window" );

	return static_cast<int>( window.MessagePump() );
}