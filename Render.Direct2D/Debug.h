#pragma once

#ifndef ASSERT
#include <crtdbg.h>
#define ASSERT _ASSERTE
#endif

#ifndef VERIFY
#ifdef _DEBUG
#define VERIFY( expression ) ASSERT( expression )
#else
#define VERIFY(expression) (expression)
#endif
#endif

#ifndef TRACE
#ifdef _DEBUG

#include <stdio.h>

template <typename... Args>
void DebugTrace( wchar_t const * format, Args... args )
{
	wchar_t buffer[ 512 ];

	int const count = swprintf_s( buffer,
		format,
		args... );

	ASSERT( -1 != count );

	//OutputDebugString( buffer );
}

#define TRACE DebugTrace
#else
#define TRACE __noop
#endif
#endif