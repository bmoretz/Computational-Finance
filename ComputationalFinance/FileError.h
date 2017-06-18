#pragma once

using namespace std;

namespace Common
{
    class FileError :
            public runtime_error
    {
    public:
        explicit FileError( const string &description );
        ~FileError();

    };
}
