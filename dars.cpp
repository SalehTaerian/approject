#include "dars.h"
#include <iostream>
#include "json.hpp"
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
    cout << "Enter namedars"<<endl;
    cin >> darsname;
    for (int i = 0; i < jsonsize; i++)
    {
        if (jsonarray[i]["darsname"] == darsname)
        {
            jsonarray[i]["taklif"].push_back({{"tarikh_shoroo", takliflist[taklifnum].tarikh_shoroo},
                                              {"tarikh_payan", takliflist[taklifnum].tarikh_payan},
                                              {"sharh_taklif", takliflist[taklifnum].sharh},
                                              {"nomreh_taklif", 0}});
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
    cout << "Enter shomareh teklif:" << endl;
    // cout << "Enter nomreh taklif:" << endl;
}
void dars::set_ettelaeieh()
{
    cout << "Enter etteleieh:" << endl;
    cin.ignore();
    getline(cin, ettelaeieh[numettel]);
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
    cout << "Enter nomreh" << endl;
    cin >> nomrehdars;
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
    for (int i = 0; i < jsonsize; i++)
    {
        if (jsonarray[i]["darsname"] == darsname)
        {
            jsonarray[i]["nomrehdars"] = nomrehdars;
            break;
        }
    }
    fp = fopen("doroos.json", "w");
    string matnfile = jsonarray.dump(4);
    int size = matnfile.size();
    fwrite(matnfile.c_str(), 1, size, fp);
    fclose(fp);
}
string *dars::get_ettelaeieh()
{
    return ettelaeieh;
}