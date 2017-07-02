#include "stdafx.h"
#include "Application.h"

//Provides the entry point to the application
int WINAPI wWinMain( _In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR cmdLine, _In_ int cmdShow )
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(cmdLine);
    UNREFERENCED_PARAMETER(cmdShow);

    Application application( hInstance );

    return application.Run();
}