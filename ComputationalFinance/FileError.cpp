#include "stdafx.h"
#include "FileError.h"

namespace Common
{
    FileError::FileError( const string &description )
        : runtime_error( description )
    {
    }

    FileError::~FileError()
    {
    }
}