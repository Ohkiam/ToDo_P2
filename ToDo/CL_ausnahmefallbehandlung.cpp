/** Klasse CL_ausnahmefallbehandlung  */
#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <fstream>
#include <stdio.h>
#include <exception>
#include "CL_ausnahmefallbehandlung.hpp"


/// http://peterforgacs.github.io/2017/06/25/Custom-C-Exceptions-For-Beginners/
/// https://www.c-plusplus.net/forum/topic/139074/exception-handling/2
/// http://www.tutorialspoint.com/cplusplus/cpp_exceptions_handling.htm
/// https://roscas.github.io/cpp/Cpp-exceptions-Handling.html
/// https://riptutorial.com/de/cplusplus/example/23640/benutzerdefinierte-ausnahme


/**

@Gisela

Diese Klasse ist noch nicht fertig,
Der Grund : Blicke da noch nicht so richtig durch was alles möglich ist!



*/

CL_ausnahmefallbehandlung::CL_ausnahmefallbehandlung(int _grund)
{
	grund = _grund;
};

int CL_ausnahmefallbehandlung::get_grund()
{ return grund; }




