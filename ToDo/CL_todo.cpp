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
    fr.open(my_todo_file, std::fstream::out | std::fstream::app);
    if(!fr.good()){
        return false;
    }
    fr.close();
    std::fstream f;
    f.open(my_tag_file, std::fstream::out | std::fstream::app);
    if(!f.good()){
        return false;
    }
    f.close();
}

/**
* @description : schreiben von todos und tags in den richtigen Dateien
*
* @param : todo (kleine Hilfe damit das Tool weis was es wohin schreiben soll)
*
* @todo :   soll so laufen, das nicht mehr so ein Kuddelmuddel ist mit übergabe ob tag so oder so, sondern nur noch aufrufen wen was geschrieben werden soll entscheidung wird vor dem Aufruf gestroffen
*
* @throws :
* @error :
* @return:
*/
void CL_todo::write_file(){
/*    if(my_todo == "0"){
        save_file = my_tag_file;
	}else{
	    save_file = my_file;
	}*/
    std::string save_file;
    std::string my_todo;
    std::string my_tag;
    std::string todo;
    std::fstream fr;
	fr.open (save_file, std::fstream::out | std::fstream::app);
	if(my_todo == "0"){
        fr << my_tag << " # " <<"\n";
        std::cout << "\n \n Das Schlagwort: \n " << my_tag
                  << "\n \n wurde gespeichert!" << std::endl;
	}else{
	    fr << my_tag << " # " << my_todo <<"\n";
	    std::cout << "\n \n Das Todo: \n " << my_todo
                  << "\n \n wurde gespeichert" << std::endl;
	}
	fr.close();
	if(todo != "0"){
        fr.open (my_tag_file, std::fstream::out | std::fstream::app);
        fr << my_tag << " # " <<"\n";
        std::cout << "\n \n Das Schlagwort: \n " << my_tag
                  << "\n \n wurde gespeichert!" << std::endl;
        fr.close();
	}
	return;
}
