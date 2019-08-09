/** Klasse CL_init  */
#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <fstream>
#include <stdio.h>
#include "CL_init.hpp"


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
void CL_init::command_help(){
    std::cout <<    "\n Hilfe new \n"
                    "      tag | Schlagwort erstellen \n"
                    "     todo | Aufgabe erstellen \n"
                    " list_tag | Sclagwoerter anzeigen \n"
                    "list_todo | Aufgaben anzeigen" << std::endl;
    return;
}

void CL_init::init(int argc, char **argv)
{
    if(argc < 2){
        #ifdef WINDOWS  /// Hier kommt nachher der Aufruf für die Gui rein
            std::cout << "nur prog.exe in Windows aufgerufen" << std::endl;
        #else           /// Hier kommt nachher der Aufruf für die Gui rein
            std::cout << "nur prog in Linux aufgerufen" << std::endl;
        #endif // WINDOWS
    }
    int i;
    for(i=0; i<argc; i++)
	{
        // hier werden die Strings verglichen mit !strcmp
		// wichtig ist das sring.h eingebunden wird
        if(!strcmp( argv[i], "todo.exe" )){
                //CL_aufgabe test;
                //test.echo(5);
        }else if(!strcmp( argv[i], "help" )){
            //command_help();
            command_help();
        }else if(!strcmp( argv[i], "tag" )){
            //command_tag();

        }else if(!strcmp( argv[i], "todo" )){
            //command_todo();

        }else if(!strcmp( argv[i], "list_tag" )){
            //command_list_tag();

        }else if(!strcmp( argv[i], "list_todo" )){
            //command_list_todo();

        }else{
            //s = argv[i];
            //comand_err();

        }

    }
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
