/** Klasse CL_userinfo  */
#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <fstream>
#include <stdio.h>
#include "CL_userinfo.hpp"



//std::string s = "";



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
    //std::cout << help << std::endl;
    return(help) ;
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

    //std::string test;
    //test = s;
    //test += " ist als Befehl nicht vorhanden";

    //std::cout << "Sorry!, ich weiss nicht was du willst. Den Befehl "<< s <<" kenne ich nicht" << std::endl;
    return (s += " ist als Befehl nicht vorhanden");
}


