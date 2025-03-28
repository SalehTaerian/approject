#include <iostream>
#include <cstdio>
#include <string>
#include "mainheader.h"
#include "json.hpp"
#include "karbar.cpp"
using namespace std;
using json = nlohmann::json;
void welcome()
{
    cout << "----------welcome to yekestan----------";
    cout << endl;
}
void signin()
{
    int option, panel, ramzshab, flag = 0;
    string username, password, name, lastname;
    cout << "choose your panel:" << endl
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
    cout << "choose your option:" << endl;
    cout << "1-signin" << endl;
    cout << "2-signup" << endl;
    cin >> option;
    while (1)
    {

        if (option == 1)
        {
            cout << "Enter your username" << endl;
            cin >> username;
            cout << "Enter your password" << endl;
            cin >> password;
            if (username == "Admin" && password == "Admin")
            {
                admin();
            }
            else
            {

                while (1)
                {
                    if (!userpassexist(username, password))
                    {
                        cout << "incorrect username or password try again!" << endl;
                        cout << "Enter your username" << endl;
                        cin >> username;
                        cout << "Enter your password" << endl;
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
                ostad();
            }
            daneshjoo();
            break;
        }
        else if (option == 2)
        {
            cout << "Enter your username" << endl;
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
            cout << "Enter your password" << endl;
            cin >> password;
            cout << "Enter your name" << endl;
            cin >> name;
            cout << "Enter your lastname" << endl;
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
            writeininfofile(user1);
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
void writeininfofile(karbar user1)
{
    FILE *fp = fopen("info.json", "r");
    json jsonarray;
    if (fp != nullptr)
    {
        fseek(fp, 0, SEEK_END);
        int fpsize = ftell(fp);
        fseek(fp, 0, SEEK_SET);
        if (fpsize > 0)
        {
            char *readfile = new char[fpsize + 1];
            fread(readfile, 1, fpsize, fp);
            readfile[fpsize] = '\0';
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
    jsonarray.push_back({{"name", user1.namegetter()},
                         {"lastname", user1.lastnamegetter()},
                         {"username", user1.usernamegetter()},
                         {"password", user1.passwordgetter()}});
    fp = fopen("info.json", "w");
    string info = jsonarray.dump(4);
    fprintf(fp, "%s", info.c_str());
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
    fread(readfile, 1, filesize, fp);
    readfile[filesize] = '\0';
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
    fread(readfile, 1, filesize, fp);
    readfile[filesize] = '\0';
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