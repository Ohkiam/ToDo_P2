/** Klasse CL_schlagwort  */

#include "CL_todo.hpp"


#ifndef _CL_SCHLAGWORT_H_
#define _CL_SCHLAGWORT_H_

class CL_schlagwort: /*virtual*/ public CL_todo{    /** virtual aus dem Grund, damit die CL_init keine Probleme mit der Mehrfachvererbung bekommt wenn auf CL_todo zugegriffen werden soll */
private:
    /** Was habe ich an Variablen und Methoden hier */
    std::string my_tag;

public:
    /** was muss ich sichtbar deklarieren */
    CL_schlagwort();     /// konstruktor
    ~CL_schlagwort();
    void command_tag();
};
#endif // _CL_SCHLAGWORT_H_
