/** Klasse CL_todo  */

#include <stdio.h>
#include <string>
#include <fstream>
#include "CL_todo.hpp"


CL_todo::CL_todo()      /// konstruktor
{

}
CL_todo::~CL_todo()     /// dekonstruktor
{

}
/**
* @description : setzen der Variable my_tag
*
* @param : std::string _my_tag
*
* @return: nix
*/
void CL_todo::set_tag(std::string _my_tag){
    my_tag = _my_tag;
}
/**
* @description : setzen der Variable my_todo
*
* @param : std::string _my_todo
*
* @return: nix
*/
void CL_todo::set_todo(std::string _my_todo){
    my_todo = _my_todo;
}
/**
* @description : ausgeben der Variable my_tag_file
*
* @param :
*
* @return: std::string
*/
std::string CL_todo::get_tag_file(){
    return my_tag_file;
}
/**
* @description : ausgeben der Variable my_todo_file
*
* @param :
*
* @return: std::string
*/
std::string CL_todo::get_todo_file(){
    return my_todo_file;
}
/**
* @description : ausgeben der Variable my_tag
*
* @param :
*
* @return: std::string
*/
std::string CL_todo::get_tag(){
    return my_tag;
}
/**
* @description : ausgeben der Variable my_todo
*
* @param :
*
* @return: std::string
*/
std::string CL_todo::get_todo(){
    return my_todo;
}
/**
* @description : hier wird geschaut ob die Dateien my_todo_file und my_tag_file existieren,
*                wenn nicht werden sie erstellt
*
* @param :
*
* @todo :   diese Methode muss noch verkleinert werden, Eine Methode in einer Klasse (Dateihandling) wird benötigt
*
* @return: bool
*/
bool CL_todo::exist_file(){
    std::fstream fr;
    bool my_return = true;
    fr.open(my_todo_file, std::fstream::out | std::fstream::app);
    if(!fr.good()){
        my_return = false;
    }
    fr.close();
    std::fstream f;
    f.open(my_tag_file, std::fstream::out | std::fstream::app);
    if(!f.good()){
        my_return = false;
    }
    f.close();
    return my_return;
}

/**
* @description : schreiben von Schlagwörter in die my_tag_file
*
* @param :
*
* @todo :   diese Methode muss noch verkleinert werden, Eine Methode in einer Klasse (Dateihandling) wird benötigt
*
* @return: nix
*/
void CL_todo::write_file_tag(){
    std::fstream fr;
	fr.open (my_tag_file, std::fstream::out | std::fstream::app);
    fr << my_tag << " # " <<"\n";
    std::cout << "\n \n Das Schlagwort: " << my_tag << "\n \n wurde gespeichert!" << std::endl;
	fr.close();
	return;
}
/**
* @description : schreiben von Aufgaben in die my_todo_file
*
* @param :
*
* @todo :   diese Methode muss noch verkleinert werden, Eine Methode in einer Klasse (Dateihandling) wird benötigt
*
* @return: nix
*/
void CL_todo::write_file_todo(){
    std::fstream fr;
	fr.open (my_todo_file, std::fstream::out | std::fstream::app);
	fr << my_tag << " # " << my_todo <<"\n";
    std::cout << "\n \n Das Todo: \n " << my_todo << "\n \n wurde gespeichert" << std::endl;
	fr.close();
	return;
}
