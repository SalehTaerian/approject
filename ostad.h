#ifndef OSTAD_H
#define OSTAD_H
#include "karbar.h"
#include "dars.h"
#include "admin.h"
#include "ostad.h"
class ostad : public karbar
{
private:
    void listdaneshjooha();
    void ostadcore();
    void newdars();
    dars darsobj;
    void writeindarsfile(string filename);
    void show_javabtaklif();
public:
    ostad();
    friend void karbar::signin(int option);
};
#endif