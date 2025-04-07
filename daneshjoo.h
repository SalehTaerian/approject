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
public:
    void daneshjoocore();
    void showlistdoroos();
    void zarfiatkhali();
    void entekhabvahed();
    void moshakhasatdars();
    void showkhabar();
    void nomarattakalif();
    void nomrehostad();
};
#endif