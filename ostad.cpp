#include "ostad.h"
#include <iostream>
#include "admin.h"
void ostad::ostadcore()
{

    int option;
    int shomarehdars;
    string esmdars, khabar;
    cout << "Welcom ostad!" << endl;
    cout << "what do you want to do?" << endl
         << "1-namayesh list daneshjooha" << endl
         << "2-create new dars" << endl
         << "3-sabt nomreh dars"
         << endl;
    cout << "4-create ettelaeieh" << endl
         << "5-gharardadan taklif" << endl
         << "6-sabt nomreh taklif" << endl;
    cin >> option;
    switch (option)
    {
    case 1:
        // listdaneshjooha(access);
        break;
    case 2:
        newdars();
        break;
    case 3:
        cout << "Enter shomareh dars mored nazar" << endl;
        cin >> shomarehdars;
        doroos[shomarehdars].setnomrehdars();
        break;
    case 4:
        cout << "Enter shomareh dars mored nazar" << endl;
        cin >> shomarehdars;
        cout << "Enter name dars:" << endl;
        cin >> esmdars;
        cout << "Enter ettelaeieh" << endl;
        cin >> khabar;
        doroos[shomarehdars].set_ettelaeieh(esmdars, khabar);
        break;
    case 5:
        cout << "Enter shomareh dars mored nazar" << endl;
        cin >> shomarehdars;
        doroos[shomarehdars].addtaklif();
        break;
    case 6:
        cout << "Enter shomareh dars mored nazar" << endl;
        cin >> shomarehdars;
        doroos[shomarehdars].setnomreh_taklif();
    }
}
void ostad::listdaneshjooha(admin access)
{
    // access.showkarbaranlist();
    // حواست باشه تو اینطوری به کل اعضا دسترسی پیدا می کنی نه فقط دانشجوها
}
void ostad::newdars()
{

    string name, info;
    int zarfiatclass;
    cout << "Enter name dars:" << endl;
    cin >> name;
    cout << "Enter dars info:" << endl;
    cin >> info;
    cout << "Enter zarfiat dars:" << endl;
    cin >> zarfiatclass;
    doroos[darscounter] = dars(name, info, zarfiatclass);
    darscounter++;
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
    jsonarray.push_back({{"darsname", doroos[darscounter].namedars_getter()},
                         {"darsinfo", doroos[darscounter].infodars_getter()},
                         {"zarfiat", doroos[darscounter].zarfiat},
                         {"ettelaeieh", json::array()},
                         {"taklif", json::array()}});
    fp = fopen(filename.c_str(), "w");
    string info = jsonarray.dump(4);
    fwrite(info.c_str(), 1, info.size(), fp);
    fclose(fp);
}