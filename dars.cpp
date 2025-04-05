#include "dars.h"
#include <iostream>
#include"json.hpp"
using json = nlohmann::json;
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
void dars::set_ettelaeieh(string darsname ,string news)
{
    string ettel;
    cout << "Enter etteleieh:" << endl;
    cin >> ettel;
    ettelaeieh[numettel] = ettel;
    numettel++;
    FILE *fp = fopen("doroos.json", "r");
    json jsonarray;
    if (fp != nullptr)
    {
        fseek(fp, 0, SEEK_END);
        int fpsize = ftell(fp);
        fseek(fp, 0, SEEK_SET);
        if (fpsize > 0)
        {
            char *readfile = new char[fpsize + 1];
            int sizefile = fread(readfile, 1, fpsize, fp);
            readfile[sizefile] = '\0';
            fclose(fp);
            try
            {
                jsonarray = json::parse(readfile);
            }
            catch (const json::parse_error &e)
            {
                cout << "dobareh parse" << endl;
                delete[] readfile;
                return;
            }
            delete[] readfile;
        }
        else
        {
            jsonarray = json::array();
            fclose(fp);
        }
    }
    else
    {
        exit(0);
    }
    int jsonsize = jsonarray.size();
    for (int i = 0;i<jsonsize;i++)
    {
        if(jsonarray[i]["darsname"] == darsname)
        {
            jsonarray[i]["ettelaeieh"].push_back(news);
            numettel++;
            break;
        }
    }
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
    float nomreh;
    cout << "Enter nomreh" << endl;
    cin >> nomreh;
    nomrehdars = nomreh;
}
string *dars::get_ettelaeieh()
{
    return ettelaeieh;
}