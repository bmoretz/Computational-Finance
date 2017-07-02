#pragma once

#include "stdafx.h"

using namespace std;

struct ComException
{
    HRESULT result;

    explicit ComException( HRESULT const value );
};

inline void ShowMessageBoxIfFailed( HRESULT hr, const wchar_t *pMessage )
{
    if( FAILED( hr ) )
    {
        ::MessageBox( nullptr, pMessage, L"Failed", MB_OK );
    }
}

inline ComException::ComException( HRESULT const value ):
    result( value )
{
}

inline void HR( HRESULT const result, wstring msg = L"")
{
    if( S_OK != result )
    {
        #ifdef _DEBUG
        ShowMessageBoxIfFailed( result, msg.c_str() );
        #endif

        throw ComException( result );
    }
}

template <typename T>
float LogicalToPhysical( T pixel, float const dpi )
{
	return pixel * 96.0f / dpi;
}

template <typename T>
float PhysicalToLogical( T pixel, float const dpi )
{
	return pixel / 96.0f * dpi;
}