#include "class_unit.h"

ClassUnit::ClassUnit( const std::string& name ): m_name( name )
{
    m_fields.resize( ACCESS_MODIFIERS.size() );
}

void CFactory::add(const shared_ptr<Unit>&unit, Flags flags)
{
    assert (unit!=NULL);
    int accessModifier = PRIVATE;
    if( flags < ACCESS_MODIFIERS.size() )
    {
        accessModifier = flags;
    }
    m_fields[ accessModifier ].push_back( unit );
}

std::string CFactory::compile(unsigned int level)const
{
    std::string result = generateShift( level ) + "class " + m_name + " {\n";
    for( size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i ) {
        if( m_fields[ i ].empty() ) {
            continue;
        }
        result += ACCESS_MODIFIERS[ i ] + ":\n";
        for( const auto& f : m_fields[ i ] ) {
            result += f->compile( level + 1 );
        }
        result += "\n";
    }
    result += generateShift( level ) + "};\n";
    return result;
}
void CSharpFactory::add(const shared_ptr<Unit>&unit, Flags flags)
{

    int accessModifier = PRIVATE;
    if( flags < 3 ) {
        accessModifier = flags;
    }
    m_fields[ accessModifier ].push_back( unit );
}
void CSharpFactory::compile(unsigned int level) const
{
    std::string result = generateShift( level ) + "class " + m_name + " {\n";
    for( size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i )
    {
        if( m_fields[ i ].empty() )
        {
            continue;
        }
        result += ACCESS_MODIFIERS[ i ] + ":\n";
        for( const auto& f : m_fields[ i ] )
        {
            result += f->compile( level + 1 );
        }
        result += "\n";
    }
    result += generateShift( level ) + "};\n";
    return result;
}
void JavaFactory::add(const shared_ptr<Unit>&unit, Flags flags)
{

    int accessModifier = PRIVATE;
    if( flags < 3 ) {
        accessModifier = flags;
    }
    m_fields[ accessModifier ].push_back( unit );
}
void JavaFactory::compile(unsigned int level) const
{
    std::string result = generateShift( level ) + "class " + m_name + " {\n";
    for( size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i )
    {
        if( m_fields[ i ].empty() )
        {
            continue;
        }
        result += ACCESS_MODIFIERS[ i ] + ":\n";
        for( const auto& f : m_fields[ i ] )
        {
            result += f->compile( level + 1 );
        }
        result += "\n";
    }
    result += generateShift( level ) + "};\n";
    return result;
}
