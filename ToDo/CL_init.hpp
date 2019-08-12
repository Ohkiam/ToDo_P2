/** Klasse CL_init  */

//#include "CL_todo.hpp"
#include "CL_aufgabe.hpp"
#include "CL_schlagwort.hpp"

#ifndef _CL_INIT_H_
#define _CL_INIT_H_

class CL_init: public CL_aufgabe, public CL_schlagwort{
private:
    /** Was habe ich an Variablen und Methoden hier */

public:
    /** was muss ich sichtbar deklarieren */
    CL_init();     /// konstruktor
    ~CL_init();
    void init(int argc, char **argv);
};
#endif // _CL_INIT_H_
