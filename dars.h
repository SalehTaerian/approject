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
    string etteleieh[10];
    int numettel = 0;
public:
    int zarfiat;
    taklif takliflist[10];
    void darsgetter();
    dars(string darsname, string darsinfo, float nomrehdars, int zarfiat);
    void addtaklif();
    void setnomreh();
    void setnomrehdars();
    void set_ettelaeieh();
    void show_ettel();
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
    void getter();
};
#endif