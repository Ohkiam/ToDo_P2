#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <fstream>

//#include "CL_schlagwort.hpp"
//#include "CL_aufgabe.hpp"

/// wenn in funktionen.cpp weg sind die Globalen Variablen hier nicht
/// auskommentiert sind, gibt es folgende Fehlermeldungen
/// multiple definition of 'my_tag[abi:cxx11]'
/// first defined here
/// in function 'main'

extern std::string my_tag;
extern std::string my_todo;
extern std::string my_file;
extern std::string my_tag_file;
extern std::string save_file;
extern std::string s;
extern std::string j_n;
extern std::string suche;
extern bool is_found;

extern std::fstream fr;
extern std::ifstream f;


int init(int, char**);

void command_help();

void comand_err();

void exist_file();

void write_file(std::string todo);

void command_tag();

void command_todo();

void command_list_tag();

void command_list_todo();

void check_tag();
