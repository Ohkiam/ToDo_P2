/** Klasse CL_init  */
#include <iostream>
#include <cstring>
#include <stdio.h>
#include "CL_init.hpp"
#include "CL_userinfo.hpp"
#include "CL_ausnahmefallbehandlung.hpp"


/** Schalter für Windows/Linux */
//#undef WINDOWS
#define WINDOWS

CL_init::CL_init()     /// konstruktor
{

}
CL_init::~CL_init()
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
void CL_init::init(int argc, char **argv)
{
    try
	{


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
    CL_todo todo;
    if(todo.exist_file() == false){
        std::cout << "false beim Testen ob die Dateien existieren" << std::endl;
        if(todo.exist_file()){
            std::cout << "Dateien wurden erstellt" << std::endl;
        }else{
            std::cout << "Dateien konnten nicht erstellt werden" << std::endl;
        }
    }
    todo.~CL_todo();




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
    if(argc < 2){
        #ifdef WINDOWS  /// Hier kommt nachher der Aufruf für die Gui rein
            std::cout << "nur prog.exe in Windows aufgerufen" << std::endl;
        #else           /// Hier kommt nachher der Aufruf für die Gui rein
            std::cout << "nur prog in Linux aufgerufen" << std::endl;
        #endif // WINDOWS
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
        // hier werden die Strings verglichen mit !strcmp
		// wichtig ist das sring.h eingebunden wird
        if(!strcmp( argv[i], "ToDo.exe" ) || !strcmp( argv[i], "todo.exe" )){
                //CL_aufgabe test;
                //test.echo(5);
        }else if(!strcmp( argv[i], "help" )){
            CL_userinfo user;
            std::cout << user.command_help() << std::endl;

        }else if(!strcmp( argv[i], "tag" )){
            CL_schlagwort schlagwort;
            schlagwort.command_tag();
            //command_tag();
        }else if(!strcmp( argv[i], "todo" )){
            CL_aufgabe aufgabe;
            aufgabe.command_todo();
            //command_todo();

        }else if(!strcmp( argv[i], "list_tag" )){
            CL_schlagwort schlagwort;
            schlagwort.command_list_tag();
            //command_list_tag();

        }else if(!strcmp( argv[i], "list_todo" )){
            CL_aufgabe aufgabe;
            aufgabe.command_list_todo();
            //command_list_todo();

        }else{
            if(argc > 1){
                CL_userinfo user;
                std::cout << user.comand_err(argv[i]) << std::endl;
            }

        }

    }



	}
	catch(CL_ausnahmefallbehandlung a)
	{
		switch(a.get_grund())
		{
			case AUSNAHME_1:
				std::cout << "Eingabe Fehlgeschlagen." << std::endl;
				break;
			case AUSNAHME_2:
				std::cout << "Kein gueltiger Eingabewert." << std::endl;
				break;
		}
	}




}



