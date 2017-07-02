#pragma once

#include "stdafx.h"

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

inline void HR( HRESULT const result, wstring msg )
{
    if( S_OK != result )
    {
        #ifdef _DEBUG
        ShowMessageBoxIfFailed( result, msg.c_str() );
        #endif

        throw ComException( result );
    }
}