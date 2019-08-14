/** Klasse CL_ausnahmefallbehandlung  */


#define AUSNAHME_1 1
#define AUSNAHME_2 2
#define AUSNAHME_3 3
#define AUSNAHME_4 4
#define AUSNAHME_5 5
#define AUSNAHME_6 6


#ifndef _CL_AUSNAHMEFALLBEHANDLUNG_H_
#define _CL_AUSNAHMEFALLBEHANDLUNG_H_

class CL_ausnahmefallbehandlung : public std::exception
{
private:
    int grund;
public:
    CL_ausnahmefallbehandlung(int _grund);
    int get_grund();
};
#endif // _CL_AUSNAHMEFALLBEHANDLUNG_H_


