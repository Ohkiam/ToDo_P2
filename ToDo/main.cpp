/**
* @autor : Maik Hoffmann
*
* @name : ConsolenToDo
*
* @description : Speichern und Ausgeben von ToDos (Aufgaben) in der Shell
*
* @todos : siehe todo.md im Projektordner
*
*
* @date : 01.08.2019
*/

#pragma once            /** Sorgt dafür das Headerdateien nur einmal
                            eingebunden werden */

/** Bibliotheken */
#include <stdio.h>
#include "header.hpp"


/** Klassen */
#include <stdio.h>
//#include "header.hpp"
#include "CL_init.hpp"

/** Schalter für Windows/Linux */
/// Von hier aus funktioniert es nicht, muss anscheinend in die header.hpp
//#undef WINDOWS
#define WINDOWS



int main(int argc, char **argv)
{
    CL_init init_now;
    init_now.init(argc, argv);
    //init(argc, argv);

return 0;
}
