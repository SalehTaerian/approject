#ifndef OSTAD_H
#define OSTAD_H
#include "karbar.h"
#include "dars.h"
#include "admin.h"
class ostad : public karbar
{
private:
    int darscounter = 0;
    void listdaneshjooha(admin access);
    void ostadcore();
    void newdars();
    dars doroos[10];
    void writeindarsfile(string filename);
};
#endif