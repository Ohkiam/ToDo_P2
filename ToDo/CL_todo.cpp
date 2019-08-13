/** Klasse CL_todo  */

#include <stdio.h>
#include <string>
#include <fstream>
#include "CL_todo.hpp"


CL_todo::CL_todo()     /// konstruktor
{

}
CL_todo::~CL_todo()
{

}
void CL_todo::set_tag(std::string _my_tag){
    my_tag = _my_tag;
}
void CL_todo::set_todo(std::string _my_todo){
    my_todo = _my_todo;
}
std::string CL_todo::get_tag_file(){
    return my_tag_file;
}
std::string CL_todo::get_todo_file(){
    return my_todo_file;
}
std::string CL_todo::get_tag(){
    return my_tag;
}
std::string CL_todo::get_todo(){
    return my_todo;
}
/**
* @description : hier wird geschaut ob die Datei existiert, wenn nicht
*                wird sie erstellt
*
* @param :
*
* @todo :   ready_file bekommt ein true oder false dann soll in einer anderen Methode entschieden werden wie es weiter geht
*
* @throws :
* @error :
* @return:
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
* @description : schreiben von todos und tags in den richtigen Dateien
*
* @param :
*
* @todo :   return string noch und kontrolle ob my_tag befüllt ist
*
* @throws :
* @error :
* @return:
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
* @description : schreiben von todos und tags in den richtigen Dateien
*
* @param :
*
* @todo :    return string noch und kontrolle ob my_ Variablen befüllt sind
*
* @throws :
* @error :
* @return:
*/
void CL_todo::write_file_todo(){
    std::fstream fr;
	fr.open (my_todo_file, std::fstream::out | std::fstream::app);
	fr << my_tag << " # " << my_todo <<"\n";
    std::cout << "\n \n Das Todo: \n " << my_todo << "\n \n wurde gespeichert" << std::endl;
	fr.close();
	return;
}
