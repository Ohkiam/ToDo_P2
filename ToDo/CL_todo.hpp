/** Klasse CL_todo  */
#include <iostream>

#ifndef _CL_TODO_H_
#define _CL_TODO_H_
class CL_todo{
private:
    /** Was habe ich an Variablen und Methoden hier */
    int a;

public:
    /** was muss ich sichtbar deklarieren */
    CL_todo();     /// konstruktor
    ~CL_todo();
    void echo(int a);
};
#endif // _CL_TODO_H_c
