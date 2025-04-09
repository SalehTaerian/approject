#include "dars.h"
#include <iostream>
#include "json.hpp"
#include "karbar.h"
using json = nlohmann::json;
dars::dars()
{
}
string taklif::start_getter()
{
    return tarikh_shoroo;
}
string taklif::payan_getter()
{
    return tarikh_payan;
}
string taklif::sharh_getter()
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
dars::dars(string darsname1, string darsinfo1, int zarfiat1) : darsname(darsname1), darsinfo(darsinfo1), zarfiat(zarfiat1), taklifnum(0), numettel(0)
{
    for (int i = 0; i < 10; i++)
    {
        takliflist[i] = taklif();
    }
}
void dars::addtaklif()
{
    if (taklifnum >= 10)
    {
        cout << "basseh digeh ah!! zarfiat por shodeh!" << endl;
    }
    cout << "Enter soal mored nazar:" << endl;
    cin.ignore();
    getline(cin, takliflist[taklifnum].sharh);
    cout << "Enter tarikh shoroo:" << endl;
    cin >> takliflist[taklifnum].tarikh_shoroo;
    cout << "Enter tarikh payan:" << endl;
    cin >> takliflist[taklifnum].tarikh_payan;
    FILE *fp;
    json jsonarray;
    karbar usertmp;
    jsonarray = usertmp.parsejson("doroos.json");
    int jsonsize = jsonarray.size();
    cout << "Enter namedars" << endl;
    cin >> darsname;
    for (int i = 0; i < jsonsize; i++)
    {
        if (jsonarray[i]["darsname"] == darsname)
        {
            jsonarray[i]["taklif"].push_back({
                {"tarikh_shoroo", takliflist[taklifnum].tarikh_shoroo},
                {"tarikh_payan", takliflist[taklifnum].tarikh_payan},
                {"sharh_taklif", takliflist[taklifnum].sharh},
            });
            taklifnum++;
            break;
        }
    }
    string matnfile = jsonarray.dump(4);
    fp = fopen("doroos.json", "w");
    int size = matnfile.size();
    fwrite(matnfile.c_str(), 1, size, fp);
    fclose(fp);
}
void dars::setnomreh_taklif()
{
    int shomareh_taklif;
    string name;
    cout << "Enter name dars:" << endl;
    cin >> darsname;
    cout << "Enter shomareh taklif" << endl;
    cin >> shomareh_taklif;
    cout << "Enter nomreh taklif" << endl;
    cin >> takliflist[shomareh_taklif].nomreh_taklif;
    cout << "Enter username daneshjoo:";
    cin >> name;
    karbar userttemp;
    json jsonarray;
    jsonarray = userttemp.parsejson("daneshjoo.json");
    int jsonsize = jsonarray.size();
    for (int i = 0; i < jsonsize; i++)
    {
        if (jsonarray[i]["darsname"] == darsname)
        {
            if (jsonarray[i]["username"] == name)
            {
                jsonarray[i]["nomreh_taklif"][shomareh_taklif] = takliflist[shomareh_taklif].nomreh_taklif;
            }
        }
    }
    string matnfile = jsonarray.dump(4);
    FILE *fp;
    fp = fopen("daneshjoo.json", "w");
    int size = matnfile.size();
    fwrite(matnfile.c_str(), 1, size, fp);
    fclose(fp);
}
void dars::set_ettelaeieh()
{
    cout << "Enter etteleieh:" << endl;
    cin.ignore();
    getline(cin, ettelaeieh[numettel]);
    numettel++;
    json jsonarray;
    karbar usertmp;
    jsonarray = usertmp.parsejson("doroos.json");
    int jsonsize = jsonarray.size();
    cout << "Enter name dars:" << endl;
    cin >> darsname;
    for (int i = 0; i < jsonsize; i++)
    {
        if (jsonarray[i]["darsname"] == darsname)
        {
            jsonarray[i]["ettelaeieh"].push_back(ettelaeieh[numettel - 1]);
            break;
        }
    }
    FILE *fp;
    fp = fopen("doroos.json", "w");
    string matnfile = jsonarray.dump(4);
    fwrite(matnfile.c_str(), 1, matnfile.size(), fp);
    fclose(fp);
}
void dars::show_ettel()
{
    for (int i = 0; i < numettel; i++)
    {
        cout << ettelaeieh[i] << endl
             << endl;
    }
}
void dars::setnomrehdars()
{
    string esmdars, name;
    cout << "username daneshjoo:" << endl;
    cin >> name;
    cout << "Enter darsname:" << endl;
    cin >> esmdars;
    cout << "Enter nomreh:" << endl;
    cin >> nomrehdars;
    json jsonarray;
    karbar karbtmp;
    jsonarray = karbtmp.parsejson("daneshjoo.json");
    int jsonsize = jsonarray.size();
    for (int i = 0; i < jsonsize; i++)
    {
        if (jsonarray[i]["dars"] == esmdars)
        {
            if (jsonarray[i]["username"] == name)
            {
                jsonarray[i]["nomrehdars"] = nomrehdars;
                break;
            }
        }
    }
    FILE *fp;
    fp = fopen("daneshjoo.json", "w");
    string matnfile = jsonarray.dump(4);
    int size = matnfile.size();
    fwrite(matnfile.c_str(), 1, size, fp);
    fclose(fp);
}
string *dars::get_ettelaeieh()
{
    return ettelaeieh;
}