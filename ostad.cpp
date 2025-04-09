#include "ostad.h"
#include <iostream>
#include "admin.h"
ostad::ostad()
{
}
void ostad::ostadcore()
{

    int option;
    float nomreh;
    string soal, namedars;
    string esmdars, khabar, tarikh_shoroo, tarikh_payan;
    cout << "Welcom ostad!" << endl;
    while (1)
    {
        cout << "what do you want to do?" << endl
             << "1-namayesh list daneshjooha" << endl
             << "2-create new dars" << endl
             << "3-sabt nomreh dars"
             << endl;
        cout << "4-create ettelaeieh" << endl
             << "5-gharardadan taklif" << endl
             << "6-sabt nomreh taklif" << endl
             << "7-show javab taklif" << endl
             << "8-exit" << endl;
        cin >> option;
        if (option == 8)
        {
            exit(0);
        }
        switch (option)
        {
        case 1:
            listdaneshjooha();
            break;
        case 2:
            newdars();
            break;
        case 3:
            darsobj.setnomrehdars();
            break;
        case 4:
            darsobj.set_ettelaeieh();
            break;
        case 5:
            darsobj.addtaklif();
            break;
        case 6:
            darsobj.setnomreh_taklif();
            break;
        case 7:
            show_javabtaklif();
            break;
        }
    }
}
void ostad::listdaneshjooha()
{
    string darsesm;
    cout << "Enter dars mored nazar:" << endl;
    cin >> darsesm;
    json jsonobj;
    jsonobj = parsejson("daneshjoo.json");
    int sizejs = jsonobj.size();
    for (int i = 0; i < sizejs; i++)
    {
        if (jsonobj[i]["dars"] == darsesm)
        {
            cout << jsonobj[i]["username"] << endl;
        }
    }
}
void ostad::newdars()
{

    string name, info;
    int zarfiatclass;
    cout << "Enter name dars:" << endl;
    cin >> name;
    cout << "Enter dars info:" << endl;
    cin.ignore();
    getline(cin, info);
    cout << "Enter zarfiat dars:" << endl;
    cin >> zarfiatclass;
    cin.ignore();
    darsobj = dars(name, info, zarfiatclass);
    creatingfile("doroos.json");
    writeindarsfile("doroos.json");
}
void ostad::writeindarsfile(string filename)
{
    FILE *fp = fopen(filename.c_str(), "r");
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
        jsonarray = json::array();
    }
    jsonarray.push_back({{"darsname", darsobj.namedars_getter()},
                         {"darsinfo", darsobj.infodars_getter()},
                         {"zarfiat", darsobj.zarfiat},
                         {"ettelaeieh", json::array()},
                         {"taklif", json::array()}});
    fp = fopen(filename.c_str(), "w");
    string info = jsonarray.dump(4);
    fwrite(info.c_str(), 1, info.size(), fp);
    fclose(fp);
}
void ostad::show_javabtaklif()
{
    string usernamed, esmdars;
    cout << "Enter username daneshjoo:" << endl;
    cin >> usernamed;
    cout << "Enter name dars:" << endl;
    cin >> esmdars;
    json jsonobj;
    jsonobj = parsejson("daneshjoo.json");
    int tedadozv = jsonobj.size();
    for (int i = 0; i < tedadozv; i++)
    {
        if (jsonobj[i]["dars"] == esmdars)
        {
            if (jsonobj[i]["username"] == usernamed)
            {
                int tedad_taklif = jsonobj[i]["taklif"].size();
                for (int j = 0; j < tedad_taklif; j++)
                {
                    cout << jsonobj[i]["taklif"][j] << endl;
                }
            }
        }
    }
}