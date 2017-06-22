#pragma once

using namespace std;
using namespace boost::filesystem;

namespace Utility
{
    class FileManager
    {
    public:
        explicit FileManager( const string &basePath );
        FileManager( const FileManager &m );
        FileManager& operator=( FileManager &m );
        ~FileManager();

        void removeFiles() const;
        vector<string> getDirectoryContents() const;
        vector<string> listContents() const;
        void copyToTempDirectory( const string &tmpDir ) const;

    protected:
        string m_basePath;
    };
}