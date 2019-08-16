/** Klasse CL_userinfo  */




#ifndef _CL_USERINFO_H_
#define _CL_USERINFO_H_

class CL_userinfo{
private:
    /** Was habe ich an Variablen und Methoden hier */
    std::string help = "\n  Hilfe: \n"
                    "\n \t       tag | Schlagwort erstellen \n"
                    "\n \t      todo | Aufgabe erstellen \n"
                    "\n \t  list_tag | Sclagwoerter anzeigen \n"
                    "\n \t list_todo | Aufgaben anzeigen";


public:
    /** was muss ich sichtbar deklarieren */
    CL_userinfo();
    ~CL_userinfo();
    std::string command_help();
    std::string comand_err(std::string s);

};
#endif // _CL_INIT_H_


