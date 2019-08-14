/** Klasse CL_userinfo  */
#include <iostream>
#include <stdio.h>
#include "CL_userinfo.hpp"







CL_userinfo::CL_userinfo()     /// konstruktor
{

}
CL_userinfo::~CL_userinfo()
{

}
/**
* @description : Anzeigen welche Befehle es gibt
*
* @param : keine
*
* @todo :
*
* @throws :
* @error :
* @return: string
*/
std::string CL_userinfo::command_help(){
    return help ;
}
/**
* @description : Meldung das der eingegebene Befehl nicht existiert
*
* @param : string a (Name des falschen Befehl)
*
* @todo :
*
* @throws :
* @error :
* @return:
*/
std::string CL_userinfo::comand_err(std::string s){
    return (s += " ist als Befehl nicht vorhanden");
}


