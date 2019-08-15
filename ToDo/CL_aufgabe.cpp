/** Klasse CL_aufgabe  */

#include <stdio.h>
#include <iostream>
#include <fstream>
#include "CL_aufgabe.hpp"
#include "CL_schlagwort.hpp"
#include "CL_ausnahmefallbehandlung.hpp"



CL_aufgabe::CL_aufgabe()     /// konstruktor
{

}
CL_aufgabe::~CL_aufgabe()
{

}
/**
* @description : erstellen geines strings mit der Aufgabe
*
* @param :
*
* @todo : Fortgeschritten -> das DoDo als zweiter Parameter
*         eingeben und verarbeiten lassen
*
* @throws : AUSNAHME_1
*
* @return: std::string
*/
std::string CL_aufgabe::create_string_todo(){
    std::cout << "Aufgabe erstellen" << std::endl;
	getline(std::cin, my_todo_tmp);
	if(std::cin.fail())		{
        throw CL_ausnahmefallbehandlung(AUSNAHME_1);	// * Selbstdefinierter Rueckgabewert
    }
	return my_todo_tmp;
}



/**
* @description : Verarbeitung des Befehles todo
*
* @param :
*
* @todo : Fortgeschritten -> das DoDo als zweiter Parameter
*         eingeben und verarbeiten lassen
*
* @throws : AUSNAHME_1 und AUSNAHME_2
*
* @return: nix
*/
void CL_aufgabe::command_todo(){
    /** Objekte erstellen */
    CL_todo todo;
    CL_schlagwort schlagwort;
    /** string erstellen mit der Aufgabe */
	todo.set_todo(create_string_todo());            /// CL_todo -> set_todo(    CL_aufgabe -> create_string_todo()  )
    /** string erstellen mit dem Schlagwort */
	todo.set_tag(schlagwort.create_string_tag());   /// CL_todo -> set_tag(    CL_schlagwort -> create_string_tag()  )



	#if 1 /// Wegen Zeitmangel nicht geschafft alles in eine Schleife zu Packen, Vielleicht habe ich morgen noch zeit dazu

	/** Überprüfen ob Schlagwort existiert */
	if(schlagwort.check_tag(todo.get_tag(), todo.get_tag_file()) == false){     /// CL_schlagwort -> check_tag(    CL_todo -> get_tag() und  get_tag_file()
        /** tag existiert nicht also tag anlegen oder anderen tag eingeben */
        std::cout << todo.get_tag() << " existiert nicht" << std::endl;
        std::cout << "Wollen Sie dieses Schlagwort erstellen? "
                  << "\nJa (j) /Nein (n): " << std::endl;
        //std::string j_n = "";
        std::cin >> j_n;
        if(std::cin.fail())		{
			throw CL_ausnahmefallbehandlung(AUSNAHME_1);	///* Selbstdefinierter Rückgabewert
		}
        if(j_n == "n"){
            /** neuen string erstellen mit dem Schlagwort */
            todo.set_tag(schlagwort.create_string_tag());
            /** Überprüfen ob Schlagwort existiert */
            if(schlagwort.check_tag(todo.get_tag(), todo.get_tag_file()) == false){     /// CL_schlagwort -> check_tag(    CL_todo -> get_tag() und  get_tag_file()
                std::cout << "letzte Moeglichkeit das Schlagwort zu bestimmen!" << std::endl;
                /** Letzte Überprüfung */
                todo.set_tag(schlagwort.create_string_tag());
                if(schlagwort.check_tag(todo.get_tag(), todo.get_tag_file()) == false){
                    std::cout << todo.get_tag() << " existiert nicht" << std::endl;                 /// Fehlerbehandlung ^^ , Programm geht nicht weiter hier
                    /// Hier könnte ein Trow hin, muss aber nicht
                    std::cout << "Programm endet wegen wiederholter Falscheingabe des Schlagwortes" << std::endl;
                }else{
                    todo.write_file_todo(); /** todo in datei schreiben */
                }
            }else{
                todo.write_file_todo(); /** todo in datei schreiben */
            }
        }else if(j_n == "j"){
            //write_file(my_todo);
            todo.write_file_tag();  /** tag in datei schreiben */
            todo.write_file_todo(); /** todo in datei schreiben */
        }else if(j_n == ""){
             throw CL_ausnahmefallbehandlung(AUSNAHME_2);	///* Selbstdefinierter Rückgabewert
        }
	}else{
	    todo.write_file_todo(); /** todo in datei schreiben */
	}
	#endif // 0
    return;
}
/**
* @description : Auflisten der ToDos
*
* @param :
*
* @todo : Kontrollstrucktur schaffen ob Die Dateien leer sind , j_n Abfrage noch in eigene Methode verpacken
*
*
* @throws : AUSNAHME_1 , AUSNAHME_2
* @error :
* @return: nix
*/
void CL_aufgabe::command_list_todo(){

    std::ifstream f;

    int counter = 1;

    std::cout << "Aufgaben: " << std::endl;
    std::cout << "Wollen Sie sich die Schlagwoerter anzeigen lassen? "
              << "\nJa (j) /Nein (n): " << std::endl;
    std::cin >> j_n;
    CL_todo todo;
    if(std::cin.fail()){
        throw CL_ausnahmefallbehandlung(AUSNAHME_1);	// * Selbstdefinierter Rueckgabewert
    }                                                         /// Kontrollstrucktur schaffen ob Die Dateien leer sind
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
    }else if(j_n == "n"){
        //std::cout << "Sie haben nein gewaehlt" << std::endl;
        f.open(todo.get_todo_file(), std::fstream::in); // Öffne Datei aus Parameter
        while (!f.eof())          // Solange noch Daten vorliegen
        {
            getline(f, s);        // Lese eine Zeile
            std::cout << "\n \t" << counter++ << ". " << s << "\n" << std::endl;
        }
        f.close();                // Datei wieder schließen
    }else{
        throw CL_ausnahmefallbehandlung(AUSNAHME_2);	// * Selbstdefinierter Rueckgabewert
    }
}
