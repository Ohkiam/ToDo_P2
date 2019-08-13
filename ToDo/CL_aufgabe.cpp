/** Klasse CL_aufgabe  */

#include <stdio.h>
#include "CL_aufgabe.hpp"
#include "CL_schlagwort.hpp"
#include "header.hpp"


CL_aufgabe::CL_aufgabe()     /// konstruktor
{

}
CL_aufgabe::~CL_aufgabe()
{

}
std::string CL_aufgabe::create_string_todo(){
    std::cout << "Aufgabe erstellen" << std::endl;
	getline(std::cin, my_todo_tmp);
	return my_todo_tmp;
}



/**
* @description : ToDos erstellen und in einer datei schreiben lasen
*
* @param :
*
* @todo :
*
* @todo : Fortgeschritten -> das DoDo als zweiter Parameter
*         eingeben und verarbeiten lassen
*
* @throws :
* @error :
* @return:
*/
void CL_aufgabe::command_todo(){
    CL_todo todo;
    CL_schlagwort schlagwort;

	todo.set_todo(create_string_todo());

	todo.set_tag(schlagwort.create_string_tag());



	#if 1
	if(schlagwort.check_tag(todo.get_tag(), todo.get_tag_file()) == false){
        /** tag existiert nicht also tag anlegen oder anderen tag eingeben */
        std::cout << todo.get_tag() << " existiert nicht" << std::endl;
        std::cout << "Wollen Sie dieses Schlagwort erstellen? "
                  << "\nJa (j) /Nein (n): " << std::endl;
        //std::string j_n = "";
        std::cin >> j_n;
        if(j_n == "n"){
            //command_tag();
            todo.set_tag(schlagwort.create_string_tag());
            if(schlagwort.check_tag(todo.get_tag(), todo.get_tag_file()) == false){
                std::cout << "letzte Moeglichkeit das Schlagwort zu bestimmen!" << std::endl;
                todo.set_tag(schlagwort.create_string_tag());
                if(schlagwort.check_tag(todo.get_tag(), todo.get_tag_file()) == false){
                    std::cout << todo.get_tag() << " existiert nicht" << std::endl;                 /// Fehlerbehandlung Abbruch wegen falscher eingabe einbauen
                    /// Hier kommt ein Trow hin
                    std::cout << "Programm endet wegen wiederholter Falscheingabe des Schlagwortes" << std::endl;
                }else{
                    todo.write_file_todo();
                }
            }else{
                todo.write_file_todo();
            }
        }else{
            //write_file(my_todo);
            todo.write_file_tag();
            todo.write_file_todo();
        }
	}else{
	    todo.write_file_todo();
	}
	#endif // 0
    return;
}
/**
* @description : Auflisten der ToDos
*
* @param :
*
* @todo : in der Schleife funzt es noch nicht
*
*
* @throws :
* @error :
* @return: strings
*/
void CL_aufgabe::command_list_todo(){

    std::ifstream f;

    int counter = 1;

    std::cout << "Aufgaben: " << std::endl;
    std::cout << "Wollen Sie sich die Schlagwoerter anzeigen lassen? "
              << "\nJa (j) /Nein (n): " << std::endl;
    std::cin >> j_n;
    CL_todo todo;                                                           /// Kontrollstrucktur schaffen ob Die Dateien leer sind
    if(j_n == "j"){
        CL_schlagwort schlagwort;
        schlagwort.command_list_tag();


        std::cout << "mit welchem Schlagwort soll gesucht werden: " << std::endl;
        std::cin >> suche;
        std::cout << "\n" << std::endl;
        f.open(todo.get_todo_file(), std::fstream::in); // Öffne Datei aus Parameter
        while (!f.eof())          // Solange noch Daten vorliegen
        {
            getline(f, s);        // Lese eine Zeile
            if(s.find(suche) != std::string::npos){
                std::cout << "\n \t" << counter++ << ". "
                          << s.replace(s.find(s[0]),
                             std::string(suche).length()+2 , "")
                          << "\n" << std::endl;
            }

        }
        f.close();                // Datei wieder schließen
    }else{
        //std::cout << "Sie haben nein gewaehlt" << std::endl;
        f.open(todo.get_todo_file(), std::fstream::in); // Öffne Datei aus Parameter
        while (!f.eof())          // Solange noch Daten vorliegen
        {
            getline(f, s);        // Lese eine Zeile
            std::cout << "\n \t" << counter++ << ". " << s << "\n" << std::endl;
        }
        f.close();                // Datei wieder schließen
    }
}
