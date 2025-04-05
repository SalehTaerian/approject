#ifndef KARBAR_CPP
#define KARBAR_CPP
#include "karbar.h"
#include <iostream>
#include "json.hpp"
#include "admin.h"
using namespace std;
using json = nlohmann::json;
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
    string username, password, name, lastname;
    cout << "choose panel:" << endl
         << "1-daneshjoo" << endl
         << "2-ostad" << endl;
    cin >> panel;
    while (1)
    {
        if (panel != 1 && panel != 2)
        {
            cout << "incorrect option try again!";
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
                // admin::admincore();
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
                // ostad();
            }
            // daneshjoo();
            break;
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
            writeinfile(user1, "info.json");
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
void karbar::writeinfile(karbar user1, string filename)
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
                         {"password", user1.passwordgetter()}});
    fp = fopen(filename.c_str(), "w");
    string info = jsonarray.dump(4);
    fwrite(info.c_str(), 1, info.size(), fp);
    fclose(fp);
}
int usernametekrari(string newusername)
{
    json jsonobj;
    int flag = 0;
    FILE *fp = fopen("info.json", "r");
    fseek(fp, 0, SEEK_END);
    int filesize = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    char *readfile = new char[filesize + 1];
    int sizefile = fread(readfile, 1, filesize, fp);
    readfile[sizefile] = '\0';
    try
    {
        jsonobj = json::parse(readfile);
    }
    catch (const json::parse_error &e)
    {
        cout << "dobareh parse" << endl;
        delete[] readfile;
        return -1;
    }
    int sizeobj = jsonobj.size();

    for (int i = 0; i < sizeobj; i++)
    {
        if (newusername == jsonobj[i]["username"])
        {
            flag = 1;
        }
    }
    delete[] readfile;
    fclose(fp);
    if (flag)
        return 1;
    return 0;
}
int userpassexist(string user, string pass)
{
    json jsonobj;
    FILE *fp = fopen("info.json", "r");
    fseek(fp, 0, SEEK_END);
    int filesize = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    if (filesize == 0)
    {
        fclose(fp);
        return 0;
    }
    char *readfile = new char[filesize + 1];
    int sizefile = fread(readfile, 1, filesize, fp);
    readfile[sizefile] = '\0';
    cout << "File Content: " << readfile << endl;
    cout << "Last char before null termination: " << readfile[filesize - 1] << endl;
    for (int i = filesize - 5; i < filesize; i++)
    { // آخرین ۵ کاراکتر رو چک کن
        cout << "Char at " << i << ": " << int(readfile[i]) << " (" << readfile[i] << ")" << endl;
    }
    if (readfile[filesize - 1] == '\r')
    {
        cout << "jjj";
    }
    try
    {
        jsonobj = json::parse(readfile);
    }
    catch (const json::parse_error &e)
    {
        cout << "dobareh parse" << endl;
        delete[] readfile;
        fclose(fp);
        return 0;
    }
    int membersize = jsonobj.size();
    for (int i = 0; i < membersize; i++)
    {
        if (user == jsonobj[i]["username"])
        {
            if (pass == jsonobj[i]["password"])
            {
                fclose(fp);
                delete[] readfile;
                return 1;
            }
        }
    }
    fclose(fp);
    return 0;
}
#endif