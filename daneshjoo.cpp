#include "daneshjoo.h"
using namespace std;
using json = nlohmann::json;
daneshjoo::daneshjoo(string username, string password, string name, string lastname) : karbar(username, password, name, lastname) {}

void daneshjoo::daneshjoocore()
{
    int option;
    cout << "welcome to your panel " << usernamegetter() << endl;
    while (1)
    {
        cout << "what do you want to do?" << endl
             << "1-namayesh list doroos" << endl
             << "2-namayesh doroos darayeh zarfiatkhali" << endl
             << "3-entekhabvahed" << endl
             << "4-moshakhasat doroos" << endl
             << "5-moshahedeh nomarat takalif" << endl
             << "6-nomrehdehi be ostad" << endl
             << "7-tahviltaklif" << endl
             <<"8-moshahedeh nomreh"<<endl
             << "9-exit" << endl;
        cin >> option;
        if (option == 9)
        {
            break;
        }
        switch (option)
        {
        case 1:
            showlistdoroos();
            break;
        case 2:
            zarfiatkhali();
            break;
        case 3:
            entekhabvahed();
            break;
        case 4:
            moshakhasatdars();
            break;
        case 5:
            nomarattakalif();
            break;
        case 6:
            nomrehostad();
            break;
        case 7:
            tahviltaklif();
            break;
        case 8:
            show_nomrehdars();
        }
    }
}
void daneshjoo::showlistdoroos()
{
    json jsonarray;
    jsonarray = parsejson("doroos.json");
    int jsonsize = jsonarray.size();
    for (int i = 0; i < jsonsize; i++)
    {
        cout << jsonarray[i]["darsname"] << endl;
    }
}
void daneshjoo::zarfiatkhali()
{
    json jsonarray;
    jsonarray = parsejson("doroos.json");
    cout << "doroos daraye zarfiat khali:" << endl;
    int jsonsize = jsonarray.size();
    for (int i = 0; i < jsonsize; i++)
    {
        if (jsonarray[i]["zafiat"] != 0)
        {
            cout << "namedars: " << jsonarray[i]["darsname"] << "\t" << "zarfiat: " << jsonarray[i]["zarfiat"] << endl;
        }
    }
}
void daneshjoo::entekhabvahed()
{
    string darsname;
    cout << "Enter darsi ke mikhay bardari:" << endl;
    cin >> darsname;
    FILE *fp;
    json jsonarray;
    jsonarray = parsejson("doroos.json");
    int jsonsize = jsonarray.size();
    for (int i = 0; i < jsonsize; i++)
    {
        if (jsonarray[i]["darsname"] == darsname)
        {
            if (jsonarray[i]["zarfiat"] > 0)
            {
                jsonarray[i]["zarfiat"] = (int)jsonarray[i]["zarfiat"] - 1;
                string matn = jsonarray.dump(4);
                int sizejsarr = matn.size();
                fp = fopen("doroos.json", "w");
                fwrite(matn.c_str(), 1, sizejsarr, fp);
                fclose(fp);
                creatingfile("daneshjoo.json");
                json jsobj = parsejson("daneshjoo.json");
                int jsarrsize = jsobj.size();
                int flag = 0;
                for (int u = 0; u < jsarrsize; u++)
                {
                    if (jsobj[u]["username"] == usernamegetter())
                    {
                        if (jsobj[u]["dars"] == darsname)
                        {
                            flag = 1;
                        }
                    }
                }
                if (!flag)
                {
                    jsobj.push_back({{"username", usernamegetter()},
                                     {"dars", darsname},
                                     {"taklif", json::array()},
                                     {"nomrehdars", 0},
                                     {"nomreh_taklif", json::array()},
                                     {"nomreh_ostad", 0}});
                }
                fp = fopen("daneshjoo.json", "w");
                string info = jsobj.dump(4);
                fwrite(info.c_str(), 1, info.size(), fp);
                fclose(fp);
            }
            else
            {
                cout << "in dars zarfiat khali nadarad!" << endl;
            }
        }
    }
}
void daneshjoo::moshakhasatdars()
{
    json jsobj;
    string esmdars;
    jsobj = parsejson("daneshjoo.json");
    json jsobjdoroos;
    jsobjdoroos = parsejson("doroos.json");
    int jssize = jsobj.size();
    int size_darsjs = jsobjdoroos.size();
    for (int i = 0; i < jssize; i++)
    {
        if (jsobj[i]["username"] == usernamegetter())
        {
            esmdars = (string)jsobj[i]["dars"];
            for (int k = 0; k < size_darsjs; k++)
            {
                if (jsobjdoroos[k]["darsname"] == esmdars)
                {
                    string matn = jsobjdoroos[k].dump(4);
                    cout << matn << endl;
                }
            }
        }
    }
}
void daneshjoo::showkhabar()
{
    json jsonarray;
    jsonarray = parsejson("doroos.json");
    int jsonsize = jsonarray.size();
    for (int i = 0; i < jsonsize; i++)
    {
        cout << "ettelaeieh ha barayeh dars " << jsonarray[i]["darname"] << endl;
        cout << jsonarray[i]["ettelaeieh"] << endl;
    }
}
void daneshjoo::nomarattakalif()
{
    json jsonarray;
    string esmdars;
    jsonarray = parsejson("daneshjoo.json");
    cout << "Enter darsi ke mikhay nomarat taklifesho bebini:" << endl;
    cin >> esmdars;
    int jsonsize = jsonarray.size();
    for (int i = 0; i < jsonsize; i++)
    {
        if (jsonarray[i]["username"] == usernamegetter())
        {
            if (jsonarray[i]["dars"] == esmdars)
            {
                int tedadtaklif = jsonarray[i]["nomreh_taklif"].size();
                for (int j = 0; j < tedadtaklif; j++)
                {
                    cout << jsonarray[i]["nomreh_taklif"][j] << endl;
                }
            }
        }
    }
}
void daneshjoo::tahviltaklif()
{
    static int taklnum = 0;
    string esmdars;
    json jsobj;
    jsobj = parsejson("daneshjoo.json");
    cout << "Enter namedars:" << endl;
    cin >> esmdars;
    cout << "Enter pasokh taklif:(be tartib vared kardan)" << endl;
    cin >> taklif;
    int jssize = jsobj.size();
    for (int i = 0; i < jssize; i++)
    {
        if (jsobj[i]["username"] == usernamegetter())
        {
            if (jsobj[i]["dars"] == esmdars)
            {
                jsobj[i]["taklif"][taklnum] = taklif;
            }
        }
    }
    string matnfile = jsobj.dump(4);
    int filesize = matnfile.size();
    FILE *fp;
    fp = fopen("daneshjoo.json", "w");
    fwrite(matnfile.c_str(), 1, filesize, fp);
    fclose(fp);
}
void daneshjoo::nomrehostad()
{
    json jsobj;
    string esmdars;
    float nomreh;
    jsobj = parsejson("daneshjoo.json");
    cout << "be ostad kodoom dars mikhay nmreh bedi?" << endl;
    cin >> esmdars;
    cout << "Enter nomreh ostad" << endl;
    cin >> nomreh;
    int jssize = jsobj.size();
    for (int i = 0; i < jssize; i++)
    {
        if (jsobj[i]["username"] == usernamegetter())
        {
            if (jsobj[i]["dars"] == esmdars)
            {
                jsobj[i]["nomreh_ostad"] = nomreh;
            }
        }
    }
    FILE *fp = fopen("daneshjoo.json", "w");
    string matnfile = jsobj.dump(4);
    int filesize = matnfile.size();
    fwrite(matnfile.c_str(), 1, filesize, fp);
    fclose(fp);
}
void daneshjoo::show_nomrehdars()
{
    json jsobj;
    string esmdars;
    cout<<"nomreh che darsi mikhay bebini?"<<endl;
    cin >> esmdars;
    jsobj = parsejson("daneshjoo.json");
    int sizefile = jsobj.size();
    for (int i = 0; i < sizefile;i++)
    {
        if (jsobj[i]["username"]==usernamegetter())
        {
            if (jsobj[i]["dars"] == esmdars)
            {
                cout << jsobj[i]["nomrehdars"] << endl;
            }
        }
    }
}