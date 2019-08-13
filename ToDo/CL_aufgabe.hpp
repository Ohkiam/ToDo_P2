/** Klasse CL_aufgabe  */

#include "CL_todo.hpp"



#ifndef _CL_AUFGABE_H_
#define _CL_AUFGABE_H_

class CL_aufgabe: /*virtual*/ public CL_todo{   /** virtual aus dem Grund, damit die CL_init keine Probleme mit der Mehrfachvererbung bekommt wenn auf CL_todo zugegriffen werden soll */
private:
    /** Was habe ich an Variablen und Methoden hier */
    std::string j_n = "";
    std::string suche = "";
    std::string s = "";
    std::string my_todo_tmp = "";


public:
    /** was muss ich sichtbar deklarieren */
    CL_aufgabe();     /// konstruktor
    ~CL_aufgabe();
    std::string create_string_todo();
    void command_todo();
    void command_list_todo();
};
#endif // _CL_AUFGABE_H_
