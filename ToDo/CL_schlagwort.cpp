/** Klasse CL_schlagwort  */

#include <stdio.h>
#include "CL_schlagwort.hpp"
#include "header.hpp"

CL_schlagwort::CL_schlagwort()     /// konstruktor
{

}
CL_schlagwort::~CL_schlagwort()
{

}

/**
* @description : Schlagwort (tag) erstellen und in eine txt schreiben lassen
*
* @param :
*
* @todo :
*
*
* @todo : Fortgeschritten -> das Schlagwort als zweiter Parameter eingeben
*         und verarbeiten lassen
* @throws :
* @error :
* @return: string
*/
void CL_schlagwort::command_tag(){
    std::cout << "Schlagwort erstellen" << std::endl;
    getline(std::cin, my_tag);
    //CL_todo t;
	//write_file();
	return;
}
