/** Klasse CL_todo  */
#include <iostream>

#ifndef _CL_TODO_H_
#define _CL_TODO_H_
class CL_todo{
private:
    /** Was habe ich an Variablen und Methoden hier */
    std::string my_tag_file = "tag.txt";
    std::string my_todo_file = "todo.txt";



public:
    /** was muss ich sichtbar deklarieren */
    CL_todo();     /// konstruktor
    ~CL_todo();
    bool exist_file();
    void write_file();


};
#endif // _CL_TODO_H_c
