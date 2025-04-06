#ifndef ADMIN_H
#define ADMIN_H
#include "karbar.h"
#include"json.hpp"
using json = nlohmann::json;
class admin : public karbar
{
private:
    int nomrehostad;
    static void addnewdaneshjoo();
    static void showkarbaranlist();
    static void virayeshinfokarbar();
    static void hazfkarbar();
    static void restorekarbar();
    // static void showdoroosinfo();
public:
    static void admincore();
    admin();
};
void creatingfile(string filename);
#endif