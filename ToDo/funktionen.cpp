// For Paste and Copy for this script
/**
* @description : Beschreibung
*
* @param : Angabe sämtlicher Parameter
*
* @todo : Was ist noch zu tun?
*
*
* @throws : wirft eine exception (Ausnahme)?
* @error : erzeugt ein Fehler
* @return: Was wird zurück gegeben
*/

#include "CL_schlagwort.hpp"
#include "CL_aufgabe.hpp"
#include "CL_todo.hpp"

#include <stdio.h>
#include "header.hpp"


/// extern in der header.hpp funktioniert nicht
std::string my_tag = "";
std::string my_todo = "0";
std::string my_file = "todos.txt";
std::string my_tag_file = "tags.txt";
std::string save_file = "";
std::string s = "";
bool is_found = false;
std::string j_n = "";
std::string suche = "";

std::fstream fr;
std::ifstream f;


int init(int argc, char **argv)
{
    /**
    * @description : Schalter für den Aufruf der Gui
    *
    * @param : Anzahl der übergebenen Parameter
    *
    * @todo : Diese Funktion muss noch augelagert werden, Problem ist die
    *         Übernahme der main Parameter (nochmal schlau machen ob es mit
    *         casten geht)
    *
    * @throws :
    * @error :
    * @return:
    */
    if(argc < 2){
        #ifdef WINDOWS  /// Hier kommt nachher der Aufruf für die Gui rein
            std::cout << "nur prog.exe in Windows aufgerufen" << std::endl;
        #else           /// Hier kommt nachher der Aufruf für die Gui rein
            std::cout << "nur prog in Linux aufgerufen" << std::endl;
        #endif // WINDOWS
        return 0;
    }
    /**
    * @description : Schleife zum Auslesen der übergebenen Parameter beim
    *                Programmaufruf und aufruf der entsprechenden Funktionen
    *
    * @param : argc, argv
    *
    * @todo : Diese Funktion muss noch augelagert werden, Problem ist die
    *         Übernahme der main Parameter (nochmal schlau machen ob es mit
    *         casten geht)
    *
    * @throws :
    * @error :
    * @return:
    */
    int i;
    for(i=0; i<argc; i++)
	{
        #if 0
		/// https://www.geeksforgeeks.org/friend-class-function-cpp/
		/// geht also mit vererbung, mach ich aber erst später wenn es
		/// ans oop geht
		std::string a = argv[i];
		switch(a){
		    /**
		    error: switch quantity not an integer
		    Fehler : Schaltmenge ist keine ganze Zahl
		    */
		    case 'help': std::cout << a << std::endl; break;
		    case 'tag': std::cout << a << std::endl; break;
		    case 'todo': std::cout << a << std::endl; break;
		    default: std::cout << a << std::endl; break;
		}
		#endif // switch case

		#if 1
		// hier werden die Strings verglichen mit !strcmp
		// wichtig ist das sring.h eingebunden wird
        if(!strcmp( argv[i], "todo_consolen_tool.exe" )){
                CL_aufgabe test;
                test.echo(5);
        }else if(!strcmp( argv[i], "help" )){
            command_help();
            return 0;
        }else if(!strcmp( argv[i], "tag" )){
            command_tag();
            return 0;
        }else if(!strcmp( argv[i], "todo" )){
            command_todo();
            return 0;
        }else if(!strcmp( argv[i], "list_tag" )){
            command_list_tag();
            return 0;
        }else if(!strcmp( argv[i], "list_todo" )){
            command_list_todo();
            return 0;
        }else{
            s = argv[i];
            comand_err();
            return 0;
        }
        #endif // if Spungliste
    }
    return 0;
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
void command_help(){
    std::cout <<    "\n Hilfe \n"
                    "      tag | Schlagwort erstellen \n"
                    "     todo | Aufgabe erstellen \n"
                    " list_tag | Sclagwoerter anzeigen \n"
                    "list_todo | Aufgaben anzeigen" << std::endl;
    return;
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
void comand_err(){
    std::cout << "Sorry!, ich weiss nicht was du willst. Den Befehl "<< s
              <<" kenne ich nicht" << std::endl;
    return;
}
/**
* @description : hier wird geschaut ob die Datei existiert, wenn nicht
*                wird sie erstellt
*
* @param :
*
* @todo :
*
* @throws :
* @error :
* @return:
*/
void exist_file(){
    fr.open(my_tag_file, std::fstream::out | std::fstream::app);
    if(!fr.good()){
        std::cerr << "Fehler beim erstellen der tags.txt" << std::endl;
    }
    fr.close();
    // ??
    f.open(my_file, std::fstream::out | std::fstream::app);
    if(!f.good()){
        std::cerr << "Fehler beim erstellen der todos.txt !" << std::endl;
    }
    f.close();
}
/**
* @description : schreiben von todos und tags in den richtigen Dateien
*
* @param : todo (kleine Hilfe damit das Tool weis was es wohin schreiben soll)
*
* @todo :
*
* @throws :
* @error :
* @return:
*/
void write_file(std::string todo = "0"){
    if(my_todo == "0"){
        save_file = my_tag_file;
	}else{
	    save_file = my_file;
	}

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
void command_tag(){
    exist_file();
    std::cout << "Schlagwort erstellen" << std::endl;
    getline(std::cin, my_tag);
	write_file();
	return;
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
void command_todo(){
    exist_file();
    std::cout << "Aufgabe erstellen" << std::endl;
	getline(std::cin, my_todo);
	std::cout << "Schlagwort ?" << std::endl;
	getline(std::cin, my_tag);
	check_tag();
    //write_file();
    return;
}
/**
* @description : Auflisten aller Schlagwörter (tags)
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
void command_list_tag(){
    exist_file();
    std::cout << "Schlagwoerter: anzeigen lassen " << std::endl;
    f.open(my_tag_file, std::fstream::in); // Öffne Datei aus Parameter
    while (!f.eof())          // Solange noch Daten vorliegen
    {
        getline(f, s);        // Lese eine Zeile
        // Zeige sie auf dem Bildschirm und nehme das # weg:
        std::cout << "\t" << s.substr(0, s.size()-2) << std::endl;
    }
    f.close();                // Datei wieder schließen
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
void command_list_todo(){
    exist_file();
    int counter = 1;

    std::cout << "Aufgaben: " << std::endl;
    std::cout << "Wollen Sie sich die Schlagwoerter anzeigen lassen? "
              << "\nJa (j) /Nein (n): " << std::endl;
    std::cin >> j_n;
    if(j_n == "j"){
        command_list_tag();
        std::cout << "mit welchem Schlagwort soll gesucht werden: " << std::endl;
        std::cin >> suche;
        std::cout << "\n" << std::endl;

        f.open(my_file, std::fstream::in); // Öffne Datei aus Parameter
        while (!f.eof())          // Solange noch Daten vorliegen
        {
            getline(f, s);        // Lese eine Zeile
            std::cout << s << std::endl;
            /// Hier gibt es zwei möglichkeiten um zum gesuchten zu kommen
            #if 0 /// Variante eins
            if(s.find(suche) == false){
                //std::cout << s.find("kind") << "    Suchwort: " << suche
                //          << " im String " << s << std::endl;
            }
            #endif // 0
            #if 1 /// Variante zwei (mein Favorit)
            if(s.find(suche) != std::string::npos){
                //std::cout << s.find(suche) << "     Suchwort: " << suche
                //          << " im String " << s << std::endl;
                std::cout << "\n \t" << counter++
                          << s.replace(s.find(s[0]),
                             std::string(suche).length()+2 , "")
                          << "\n" << std::endl;
                //s.replace(s.find(s[0]), std::string(suche).length(), "");
            }
            #endif // 1
        }
        f.close();                // Datei wieder schließen
    }else{
        //std::cout << "Sie haben nein gewaehlt" << std::endl;
        f.open(my_file, std::fstream::in); // Öffne Datei aus Parameter
        while (!f.eof())          // Solange noch Daten vorliegen
        {
            getline(f, s);        // Lese eine Zeile
            std::cout << "\n \t" << counter++
                      << s.substr(0, s.size()-2) << std::endl;
        }
        f.close();                // Datei wieder schließen
    }
}
/**
* @description : Prüfen ob das tag schon existiert, wenn nicht abfrage ob es
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
void check_tag(){
    /// Prüfung ob das Schlagwort existiert,
    /// wenn nicht Schlagwort erstellen (mit Rückfrage)

    f.open(my_tag_file, std::fstream::in); // Öffne Datei aus Parameter
    while (!f.eof())          // Solange noch Daten vorliegen
    {
        getline(f, s);        // Lese eine Zeile
        //if(s.find(my_tag) != std::string::npos){
        if(s.find(my_tag)){
            is_found = true;
            //std::cout << s.find(my_tag) << "   existiert" << std::endl;
        }
    }
    f.close();                // Datei wieder schließen
    if(is_found == true){
        std::cout << my_tag << " Ok, das Schlagwort existiert!" << std::endl;
    }else{
        std::cout << my_tag << " existiert nicht" << std::endl;
        std::cout << "Wollen Sie dieses Schlagwort erstellen? "
                  << "\nJa (j) /Nein (n): " << std::endl;
        std::cin >> j_n;
        if(j_n == "n"){
            command_tag();
        }else{
            write_file(my_todo);
        }
    }
    write_file();
}
