#ifndef CSHARP_H
#define CSHARP_H
#include "class_unit.h"

class CSharp: public ClassUnit
{

    public:
        const std::vector< std::string > ACCESS_MODIFIERS =
            { "public", "protected", "private", "internal", "protected_internal", "private_protected", "file"};
        CSharpClass(const std::string& name):ClassUnit(name)
        {
            m_fields.resize(ACCESS_MODIFIERS.size());
        }
        void add(const std::shared_ptr< Unit >& unit, Flags flags) override;
        std::string compile( unsigned int level = 0, std::string access_modifiers = "") const override;

}



#endif // CSHARP_H
