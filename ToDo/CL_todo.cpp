/** Klasse CL_todo  */

#include <stdio.h>
#include "CL_todo.hpp"


CL_todo::CL_todo()     /// konstruktor
{

}
CL_todo::~CL_todo()
{

}

void CL_todo::echo(int a)
{
    a = 10;
    std::cout << a << std::endl;
}
