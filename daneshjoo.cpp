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
             << "7-exit" << endl;
        cin >> option;
        if (option == 7)
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
            // nomrehostad()
            break;
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
                                     {"nomreh_ostad", json::array()}});
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
            int tedaddars = jsobj[i]["doroos"].size();
            for (int j = 0; j < tedaddars; j++)
            {
                esmdars = jsobj[i]["doroos"][j];
                for (int k = 0; k < size_darsjs; k++)
                {
                    if (jsobjdoroos[k]["darsname"] == esmdars)
                    {
                        cout << jsobjdoroos[k] << endl;
                    }
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
        int taklifsize = jsonarray[i]["taklif"].size();
        for (int j = 0; j < taklifsize; j++)
        {
            cout << jsonarray[i]["taklif"][j]["nomreh_taklif"] << endl;
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
    jsobj = parsejson("daneshoo.json");
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
    FILE *fp = fopen("daneshjoo.json" , "w");
    string matnfile = jsobj.dump(4);
    int filesize = matnfile.size();
    fwrite(matnfile.c_str() ,1 ,filesize ,fp);
    fclose(fp);
}