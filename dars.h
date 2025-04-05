#ifndef DARS_H
#define DARS_H
#include <iostream>
#include <string>
using namespace std;
class dars
{
private:
    string darsname;
    string darsinfo;
    float nomrehdars;
    int taklifnum;

public:
    int zarfiat;
    taklif takliflist[10];
    string namedars_getter();
    string infodars_getter();
    float nomrehdarsgetter();
    int taklifnumgetter();
    dars(string darsname, string darsinfo, float nomrehdars, int zarfiat, int taklifnum1);
    void addtaklif();
    void setnomreh();
};
class taklif
{
private:
    string tarikh_shoroo;
    string tarikh_payan;
    string sharh;

public:
    float nomreh_taklif;
    taklif();
    taklif(string tarikh_shoroo, string tarikh_payan, string sharh);
    string start_getter();
    string payan_getter();
    string sharh_getter();
};
#endif