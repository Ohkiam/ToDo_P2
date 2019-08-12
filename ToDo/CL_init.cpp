/** Klasse CL_init  */
#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <fstream>
#include <stdio.h>
#include "CL_init.hpp"
#include "CL_userinfo.hpp"

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
    CL_todo todo;
    if(todo.exist_file() == false){
        std::cout << "false beim Testen ob die Dateien existieren" << std::endl;
        if(todo.exist_file()){
            std::cout << "Dateien wurden erstellt" << std::endl;
        }else{
            std::cout << "Dateien konnten nicht erstellt werden" << std::endl;
        }
    }

    if(argc < 2){
        #ifdef WINDOWS  /// Hier kommt nachher der Aufruf für die Gui rein
            std::cout << "nur prog.exe in Windows aufgerufen" << std::endl;
        #else           /// Hier kommt nachher der Aufruf für die Gui rein
            std::cout << "nur prog in Linux aufgerufen" << std::endl;
        #endif // WINDOWS
    }
    CL_userinfo user;
    int i;
    for(i=0; i<argc; i++)
	{
        // hier werden die Strings verglichen mit !strcmp
		// wichtig ist das sring.h eingebunden wird
        if(!strcmp( argv[i], "ToDo.exe" )){
                //CL_aufgabe test;
                //test.echo(5);
        }else if(!strcmp( argv[i], "help" )){
            //command_help();
            std::cout << user.command_help() << std::endl;

        }else if(!strcmp( argv[i], "tag" )){
            //command_tag();

        }else if(!strcmp( argv[i], "todo" )){
            //command_todo();

        }else if(!strcmp( argv[i], "list_tag" )){
            //command_list_tag();

        }else if(!strcmp( argv[i], "list_todo" )){
            //command_list_todo();

        }else{

            std::cout << user.comand_err(argv[i]) << std::endl;


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
