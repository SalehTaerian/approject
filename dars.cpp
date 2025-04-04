#include "dars.h"
#include <iostream>
void taklif::getter()
{
    int option;
    cout << "choose your option" << endl;
    cout << "1-tarikh_shoroo 2- tarikh_payan  3 -sharh taklif" << endl;
    cin >> option;
    if (option == 1)
    {
        cout << "tarikh shoroo:" << "\t" << tarikh_shoroo << endl;
    }
    else if (option == 2)
    {
        cout << "tarikh payan:" << "\t" << tarikh_payan << endl;
    }
    else if (option == 3)
    {
        cout << "sharh taklif:" << "\t" << sharh << endl;
    }
    else
    {
        cout << "dalghak dobareh eshtebah zadi!!" << endl;
        exit(0);
    }
}
void dars::darsgetter()
{
    int option;
    cout << "Enter your option:" << endl
         << "1-darsinfo" << endl
         << "2-nomrehdars" << endl;
    cin >> option;
    if (option == 1)
    {
        cout << darsinfo << endl;
    }
    else if (option == 2)
    {
        cout << "youre nomreh: " << nomrehdars << endl;
    }
}
taklif::taklif() : tarikh_shoroo(""), tarikh_payan(""), sharh("")
{
}
taklif::taklif(string tarikh_shoroo1, string tarikh_payan1, string sharh1) : tarikh_shoroo(tarikh_shoroo1), tarikh_payan(tarikh_payan1), sharh(sharh1)
{
}
dars::dars(string darsname1, string darsinfo1, float nomrehdars1, int zarfiat1, int taklifnum1) : darsname(darsname1), darsinfo(darsinfo1), nomrehdars(nomrehdars1), zarfiat(zarfiat1), taklifnum(0)
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
void dars::setnomreh()
{
    float nomreh;
    cout << "Enter nomreh:" << endl;
    cin >> nomreh;
    takliflist[taklifnum].nomreh_taklif = nomreh;
}