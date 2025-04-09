#ifndef DANESHJOO_H
#define DANESHJOO_H
#include <iostream>
#include "json.hpp"
#include "karbar.h"
#include"admin.h"
using namespace std;
using json = nlohmann::json;
class daneshjoo : public karbar
{
    string taklif;
public:
    void daneshjoocore();
    void showlistdoroos();
    void zarfiatkhali();
    void entekhabvahed();
    void moshakhasatdars();
    void showkhabar();
    void nomarattakalif();
    daneshjoo(string username, string password, string name, string lastname);
    void nomrehostad();
    void tahviltaklif();
    void show_nomrehdars();
};
#endif