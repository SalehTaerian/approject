#ifndef DARS_H
#define DARS_H
#include <iostream>
#include <string>
using namespace std;
class taklif
{
friend class dars;
private:
    string tarikh_shoroo;
    string tarikh_payan;
    string sharh;

public:
    float nomreh_taklif[10];
    taklif();
    taklif(string tarikh_shoroo, string tarikh_payan, string sharh);
    string start_getter();
    string payan_getter();
    string sharh_getter();
};
class dars
{
private:
    string darsname;
    string darsinfo;
    float nomrehdars;
    int taklifnum;
    string ettelaeieh[10];
    int numettel = 0;

public:
    int zarfiat;
    taklif takliflist[10];
    string namedars_getter();
    string infodars_getter();
    string *get_ettelaeieh();
    float nomrehdarsgetter();
    int taklifnumgetter();
    dars(string darsname, string darsinfo, int zarfiat);
    void addtaklif();
    void setnomreh_taklif();
    void setnomrehdars();
    void set_ettelaeieh();
    void show_ettel();
};

#endif