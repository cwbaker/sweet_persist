//
// XmlReader.hpp
// Copyright (c) 2006 - 2011 Charles Baker.  All rights reserved.
//

#ifndef SWEET_PERSIST_XMLREADER_HPP_INCLUDED
#define SWEET_PERSIST_XMLREADER_HPP_INCLUDED

#include "declspec.hpp"
#include "TextReader.hpp"

namespace sweet
{

namespace persist
{

/**
// Reads XML archives.
*/
class SWEET_PERSIST_DECLSPEC XmlReader : public TextReader
{
    public:
        XmlReader();
        XmlReader( const TextReader& reader );

        template <class Char, class Type> void read( const Char* filename, const char* name, Type& object );
        template <class Char, class Type> void read( const Char* filename, const char* name, const char* child_name, Type& container );
        template <class Char, class Type, size_t LENGTH> void read( const Char* filename, const char* name, const char* child_name, Type (& values)[LENGTH] );
        template <class Type> void read( std::istream& stream, const char* name, Type& object );
        template <class Type> void read( std::istream& stream, const char* name, const char* child_name, Type& container );
        template <class Type, size_t LENGTH> void read( std::istream& stream, const char* name, const char* child_name, Type (& values)[LENGTH] );

    private:
        void parse( const char* filename, Element* element );
        void parse( const wchar_t* filename, Element* element );
        void parse( std::istream& stream, Element* element );
};

}

}

#endif
