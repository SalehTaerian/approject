#ifndef ADMIN_H
#define ADMIN_H
#include "karbar.h"
class admin : public karbar
{
    private:
        int nomrehostad;
    public:
        void admincore();
        void addnewdaneshjoo();
        void showkarbaranlist();
        void virayeshinfokarbar();
        void hazfkarbar();
        void restorekarbar();
        void showdoroosinfo();
};
void admin();

#endif