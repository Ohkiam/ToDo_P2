/** Klasse CL_todo  */
#include <iostream>

#ifndef _CL_TODO_H_
#define _CL_TODO_H_
class CL_todo{
private:
    /** Was habe ich an Variablen und Methoden hier */
    std::string my_tag_file = "tag.txt";
    std::string my_todo_file = "todo.txt";
    std::string my_tag = "";
    std::string my_todo = "";




public:
    /** was muss ich sichtbar deklarieren */
    CL_todo();     /// konstruktor
    ~CL_todo();
    bool exist_file();
    void set_tag(std::string _my_tag);
    void set_todo(std::string _my_todo);
    std::string get_tag_file();
    std::string get_todo_file();
    std::string get_tag();
    std::string get_todo();
    void write_file_tag();
    void write_file_todo();


};
#endif // _CL_TODO_H_c
