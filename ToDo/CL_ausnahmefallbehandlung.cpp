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




/// http://www.tutorialspoint.com/cplusplus/cpp_exceptions_handling.htm



CL_ausnahmefallbehandlung::CL_ausnahmefallbehandlung(int _grund)
{
	grund = _grund;
};

int CL_ausnahmefallbehandlung::get_grund()
{ return grund; }




