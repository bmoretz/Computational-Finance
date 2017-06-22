#include "stdafx.h"
#include "FileError.h"

namespace Utility
{
    FileError::FileError( const string &description )
        : runtime_error( description )
    {
    }

    FileError::~FileError()
    {
    }
}