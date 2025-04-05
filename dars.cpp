#include "dars.h"
#include <iostream>
string taklif::start_getter()
{
    return tarikh_shoroo;
}
string taklif::payan_getter()
{
    return tarikh_payan;
}string taklif::sharh_getter()
{
    return sharh;
}
string dars::namedars_getter()
{
    return darsname;
}
string dars::infodars_getter()
{
    return darsinfo;
}
float dars::nomrehdarsgetter()
{
    return nomrehdars;
}
int dars::taklifnumgetter()
{
    return taklifnum;
}
taklif::taklif() : tarikh_shoroo(""), tarikh_payan(""), sharh("")
{
}
taklif::taklif(string tarikh_shoroo1, string tarikh_payan1, string sharh1) : tarikh_shoroo(tarikh_shoroo1), tarikh_payan(tarikh_payan1), sharh(sharh1)
{
}
dars::dars(string darsname1, string darsinfo1, int zarfiat1) : darsname(darsname1), darsinfo(darsinfo1), zarfiat(zarfiat1), taklifnum(0) ,numettel(0)
{
    for (int i = 0; i < 10; i++)
    {
        takliflist[i] = taklif();
    }
}
void dars::addtaklif()
{
    string shoroo, payan, sharh;
    cout << "Enter tarikh shroo taklif:" << endl;
    cin >> shoroo;
    cout << "Enter tarikh payan taklif:" << endl;
    cin >> payan;
    cout << "Enter sharh taklif:" << endl;
    cin >> sharh;
    if (taklifnum >= 10)
    {
        cout << "basseh digeh ah!! zarfiat por shodeh!" << endl;
    }
    else
    {
        takliflist[taklifnum] = taklif(shoroo, payan, sharh);
        taklifnum++;
    }
}
void dars::setnomreh_taklif()
{
    float nomreh;
    cout << "Enter nomreh:" << endl;
    cin >> nomreh;
    takliflist[taklifnum].nomreh_taklif = nomreh;
}
void dars::set_ettelaeieh()
{
    string ettel;
        cout << "Enter etteleieh:" << endl;
        cin >> ettel;
        etteleieh[numettel] = ettel;
        numettel++;
}
void dars::show_ettel()
{
    for (int i = 0; i < numettel;i++)
    {
        cout << etteleieh[i]<<endl<<endl;
    }
}