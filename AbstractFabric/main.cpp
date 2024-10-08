#include <QCoreApplication>
//#include "myclass.h"
#include "method_unit.h"
#include "class_unit.h"
#include "printOperator_unit.h"
#include <memory>

std::string generateProgram()
{
    ClassUnit myClass( "MyClass" );
    myClass.add(
        std::make_shared< MethodUnit >( "testFunc1", "void", 0 ), ClassUnit::PUBLIC);
    myClass.add(
        std::make_shared< MethodUnit >( "testFunc2", "void", MethodUnit::STATIC ),ClassUnit::PRIVATE);
    myClass.add(
        std::make_shared< MethodUnit >( "testFunc3", "void", MethodUnit::VIRTUAL | MethodUnit::CONST ), ClassUnit::PUBLIC );

    auto method = std::make_shared< MethodUnit >( "testFunc4", "void",  MethodUnit::STATIC );
    method->add( std::make_shared< PrintOperatorUnit >( R"(Hello, world!\n)" ) );
    myClass.add( method, ClassUnit::PROTECTED );
    return myClass.compile();
}

int main() {
    std::cout << generateProgram() << std::endl;
    std::cout<<generateProgram()<<std::endl;
    return 0;
}
