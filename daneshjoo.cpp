#include "daneshjoo.h"
using namespace std;
using json = nlohmann::json;
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
        cout << jsonarray[i]["darsname"] << endl;
    }
}
void daneshjoo::zarfiatkhali()
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
        if (jsonarray[i]["darname"] == darsname)
        {
            if (jsonarray[i]["zarfiat"] > 0)
            {
                jsonarray[i]["zarfiat"] = jsonarray[i]["zarfiat"] - 1;
                creatingfile("daneshjoo.json");
                FILE *fp = fopen("daneshjoo.json", "r");
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
                    //  اگه مشکل داره احتمالا به خاطر اینه خط بالا رو عوض کردم قبلا خط پایین بوده
                    //  jsonarray = json::array();
                }
                jsonarray.push_back({
                    {"username", usernamegetter()},
                    {"doroos" ,json::array()}
                });
                jsonarray.push_back({"doroos", darsname});
                fp = fopen("daneshjoo.json", "w");
                string info = jsonarray.dump(4);
                fwrite(info.c_str(), 1, info.size(), fp);
                fclose(fp);
            }
            else
            {
                cout << "in dars zarfiat khali nadarad!" << endl;
                // توی یه  فایل باید بنویسی
            }
        }
    }
}
void daneshjoo::moshakhasatdars()
{
    
}
void daneshjoo::showkhabar()
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
        cout << "nomarat takalif dars " << jsonarray[i]["darname"] << endl;
        int taklifsize = jsonarray[i]["taklif"].size();
        for (int j = 0; j < taklifsize; i++)
        {
            cout << jsonarray[i]["taklif"][j]["nomreh_taklif"] << endl;
        }
    }
}
void daneshjoo::nomrehostad()
{
}