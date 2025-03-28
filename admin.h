#ifndef ADMIN_H
#define ADMIN_H
#include "karbar.h"
class admin : public karbar
{
private:
    int nomrehostad;
    void addnewdaneshjoo();
    void showkarbaranlist();
    void virayeshinfokarbar();
    void hazfkarbar();
    void restorekarbar();
    // void showdoroosinfo();
public:
    void admincore();
};
#endif