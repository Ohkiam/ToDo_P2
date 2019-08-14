/** Klasse CL_schlagwort  */

#include <stdio.h>
#include "CL_schlagwort.hpp"
#include "CL_ausnahmefallbehandlung.hpp"
#include "header.hpp"

CL_schlagwort::CL_schlagwort()     /// konstruktor
{

}
CL_schlagwort::~CL_schlagwort()
{

}
std::string CL_schlagwort::create_string_tag(){
    std::cout << "\n \tSchlagwort ?" << std::endl;
	getline(std::cin, my_tag_tmp);
	if(std::cin.fail()){
        throw CL_ausnahmefallbehandlung(AUSNAHME_1);	// * Selbstdefinierter Rueckgabewert
	}
    return my_tag_tmp;
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
    CL_todo todo;
    std::cout << "\n \tSchlagwort erstellen: " << std::endl;
    getline(std::cin, my_tag_tmp);
    if(std::cin.fail()){
        throw CL_ausnahmefallbehandlung(AUSNAHME_1);	// * Selbstdefinierter Rueckgabewert
    }
    if(my_tag_tmp.length() == 0){
        std::cout << "\n \tWurde was eingegeben?" << std::endl;
    }else if(my_tag_tmp.length() < 3){
        std::cout << "\n \tBitte mehr als 3 Zeichen benutzen?" << std::endl;
    }else if(check_tag(my_tag_tmp, todo.get_tag_file()) == true ){
        std::cout << "\n \tDieses Schlagwort gibt es schon!" << std::endl;
    }else{
        todo.set_tag(my_tag_tmp);
        todo.write_file_tag();
    }
	return;
}
/**
* @description : Auflisten aller Schlagw�rter (tags)
*
* @param :
*
* @todo :
*
*
* @throws :
* @error :
* @return: strings
*/
void CL_schlagwort::command_list_tag(){
    std::cout << "\n \tgespeicherte Schlagwoerter: " << std::endl;
    CL_todo todo;
    std::ifstream f;
    f.open(todo.get_tag_file(), std::fstream::in); // �ffne Datei aus Parameter
    while (!f.eof())          // Solange noch Daten vorliegen
    {
        getline(f, s);        // Lese eine Zeile
        std::cout << "\n \t" << s.substr(0, s.size()-2) << std::endl;    // Zeige sie auf dem Bildschirm und nehme das # weg
    }
    f.close();                // Datei wieder schlie�en
    return;
}
/**
* @description : Pr�fen ob das tag schon existiert, wenn nicht abfrage ob es
*                erstellt werden soll
*
* @param :
*
* @todo :
*
*
* @throws :
* @error :
* @return: strings
*/
bool CL_schlagwort::check_tag(std::string _my_tag, std::string tagfile){
    /// Pr�fung ob das Schlagwort existiert,
    /// wenn nicht Schlagwort erstellen (mit R�ckfrage)
    bool is_found = false;
    std::ifstream f;
    f.open(tagfile, std::fstream::in); // �ffne Datei aus Parameter
    while (!f.eof())          // Solange noch Daten vorliegen
    {
        getline(f, s);        // Lese eine Zeile
        if(s.find(_my_tag)!= std::string::npos){
            is_found = true;
            //std::cout << s.find(_my_tag) << "   existiert" << std::endl;
        }
    }
    f.close();                // Datei wieder schlie�en
    return is_found;
}
