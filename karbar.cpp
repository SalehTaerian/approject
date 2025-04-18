#ifndef KARBAR_CPP
#define KARBAR_CPP
#include "karbar.h"
#include <iostream>
#include "json.hpp"
#include "admin.h"
#include "ostad.h"
#include "daneshjoo.h"
using namespace std;
using json = nlohmann::json;
karbar::karbar()
{
}
karbar::karbar(string given_username, string given_password, string given_name, string given_lastname)
{
    username = given_username;
    password = given_password;
    name = given_name;
    lastname = given_lastname;
}
string karbar::usernamegetter()
{
    return username;
}
string karbar::passwordgetter()
{
    return password;
}
string karbar::namegetter()
{
    return name;
}
string karbar::lastnamegetter()
{
    return lastname;
}
void karbar::signin(int option)
{
    int panel, ramzshab, flag = 0;
    cout << "choose panel:" << endl
         << "1-daneshjoo" << endl
         << "2-ostad" << endl;
    cin >> panel;
    while (1)
    {
        if (panel != 1 && panel != 2)
        {
            cout << "incorrect option try again!" << endl;
            cin >> panel;
        }
        else
        {
            break;
        }
    }
    while (1)
    {

        if (option == 1)
        {
            cout << "Enter username" << endl;
            cin >> username;
            cout << "Enter password" << endl;
            cin >> password;
            if (username == "Admin" && password == "Admin")
            {
                admin adminobj;
                adminobj.admincore();
            }
            else
            {

                while (1)
                {
                    if (!userpassexist(username, password))
                    {
                        cout << "incorrect username or password try again!" << endl;
                        cout << "Enter username" << endl;
                        cin >> username;
                        cout << "Enter password" << endl;
                        cin >> password;
                    }
                    else
                        break;
                }
            }
            if (panel == 2)
            {
                cout << "Enter ramz shab:" << endl;
                cin >> ramzshab;
                if (ramzshab != 12345)
                {
                    while (1)
                    {
                        cout << "wrong ramzshab enter again!" << endl;
                        cin >> ramzshab;
                        if (ramzshab == 12345)
                        {
                            break;
                        }
                    }
                }
                ostad ostadobj;
                ostadobj.ostadcore();
            }
            else if (panel == 1)
            {
                daneshjoo daneshjooobj(username, password, name, lastname);
                json jsobj;
                jsobj = parsejson("info.json");
                int sizeinfofile =jsobj.size();
                for (int i = 0; i < sizeinfofile;i++)
                {
                    if  (jsobj[i]["username"]==username)
                    {
                        if((int)jsobj[i]["paneloption"]!=1)
                        {
                            cout << "lotafan az panel ostad vared shavid!" << endl;
                            exit(0);
                        }
                    }
                }
                    daneshjooobj.daneshjoocore();
                break;
            }
        }
        else if (option == 2)
        {
            cout << "Enter username" << endl;
            cin >> username;
            while (1)
            {
                if (usernametekrari(username))
                {
                    cout << "this username already exist! try another!" << endl;
                    cin.ignore();
                    cin >> username;
                    cin.ignore();
                }
                else
                {
                    break;
                }
            }
            cout << "Enter password" << endl;
            cin >> password;
            cout << "Enter name" << endl;
            cin >> name;
            cout << "Enter lastname" << endl;
            cin >> lastname;
            if (panel == 2)
            {
                cout << "Enter ramzshab!";
                cin >> ramzshab;
                if (ramzshab != 12345)
                {
                    while (1)
                    {
                        cout << "wrong ramz! enter again:";
                        cin >> ramzshab;
                        if (ramzshab == 12345)
                        {
                            break;
                        }
                    }
                }
            }
            karbar user1(username, password, name, lastname);
            writeinfile(user1, "info.json", panel);
            break;
        }
        else
        {
            cout << "Wrong option!";
            cout << "enter again!" << endl;
            cin >> option;
        }
    }
}
void karbar::writeinfile(karbar user1, string filename, int panel)
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
        exit(0);
        //  اگه مشکل داره احتمالا به خاطر اینه خط بالا رو عوض کردم قبلا خط پایین بوده
        //  jsonarray = json::array();
    }
    jsonarray.push_back({{"name", user1.namegetter()},
                         {"lastname", user1.lastnamegetter()},
                         {"username", user1.usernamegetter()},
                         {"password", user1.passwordgetter()},
                         {"paneloption", panel}});
    fp = fopen(filename.c_str(), "w");
    string info = jsonarray.dump(4);
    fwrite(info.c_str(), 1, info.size(), fp);
    fclose(fp);
}
int usernametekrari(string newusername)
{
    json jsonobj;
    int flag = 0;
    karbar usertmp;
    jsonobj = usertmp.parsejson("info.json");
    int sizeobj = jsonobj.size();

    for (int i = 0; i < sizeobj; i++)
    {
        if (newusername == jsonobj[i]["username"])
        {
            flag = 1;
        }
    }
    if (flag)
        return 1;
    return 0;
}
int userpassexist(string user, string pass)
{
    json jsonobj;
    karbar usertmp;
    jsonobj = usertmp.parsejson("info.json");
    int membersize = jsonobj.size();
    for (int i = 0; i < membersize; i++)
    {
        if (user == jsonobj[i]["username"])
        {
            if (pass == jsonobj[i]["password"])
            {
                return 1;
            }
        }
    }
    return 0;
}
json karbar::parsejson(string filename)
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
                exit(0);
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
    return jsonarray;
}
#endif