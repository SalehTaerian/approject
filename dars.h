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
    dars(string darsname, string darsinfo , int zarfiat);
    void addtaklif(string namedars , string sharh_taklif,string tarikh_shoroo , string tarikh_payan);
    void setnomreh_taklif();
    void setnomrehdars();
    void set_ettelaeieh(string darsname  ,string news);
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
    string start_getter();
    string payan_getter();
    string sharh_getter();
};
#endif