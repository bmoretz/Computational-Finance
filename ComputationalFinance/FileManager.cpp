#include "stdafx.h"
#include "FileManager.h"

namespace Common
{
    #pragma Constructor / Deconstructor

    FileManager::FileManager( const string &basePath )
        : m_basePath( basePath )
    {
    }

    FileManager::FileManager( const FileManager &m )
    {
        m_basePath = m.m_basePath;
    }

    FileManager& FileManager::operator=( FileManager &m )
    {
        if( this != &m )
        {
            m_basePath = m.m_basePath;
        }

        return *this;
    }

    FileManager::~FileManager()
    {
    }

    #pragma endregion

    void FileManager::removeFiles() const
    {
        auto files = getDirectoryContents();

        for( auto file : files )
        {
            path aPath( file );

            if( is_regular_file( aPath ) )
            {
            }
            else
            {
                remove( aPath );
            }
        }
    }

    vector<string> FileManager::getDirectoryContents() const
    {
        vector<string> results;

        path aPath( m_basePath );

        if( is_directory( aPath ) )
        {
            auto iterator = directory_iterator( aPath );

            vector<path> contents;

            copy( directory_iterator( aPath ), directory_iterator(), back_inserter( contents ) );

            for( auto item : contents )
            {
                results.push_back( item.string() );
            }
        }

        return results;
    }

    vector<string> FileManager::listContents() const
    {
        auto files = getDirectoryContents();

        vector<string> contents;

        for( auto file : files )
        {
            path aPath( file );

            if( is_regular_file( aPath ) )
            {
                contents.push_back( aPath.string() );
            }
        }

        return contents;
    }

    void FileManager::copyToTempDirectory( const string &tmpDir ) const
    {
        const path tmpPath( tmpDir );

        path aPath( m_basePath );

        if( !is_directory( aPath ) )
        {
            // Incorrect Path
        }

        auto contents = getDirectoryContents();

        for( auto it = directory_iterator( aPath ); it != directory_iterator(); ++it )
        {
            if( is_regular_file( it->path() ) )
            {
                copy_file( it->path(), tmpPath );
            }
        }
    }
}