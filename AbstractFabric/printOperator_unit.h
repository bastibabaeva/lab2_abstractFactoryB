#ifndef PRINTOPERATOR_UNIT_H
#define PRINTOPERATOR_UNIT_H
#include <QString>
#include "unit.h"

class PrintOperatorUnit : public Unit {
public:
    explicit PrintOperatorUnit( const std::string& text ) : m_text( text ) { }
    std::string compile( unsigned int level = 0 ) const {
        return generateShift( level ) + "printf( \"" + m_text + "\" );\n";
    }
private:
    std::string m_text;
};

#endif // PRINTOPERATOR_UNIT_H
