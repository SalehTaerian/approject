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
    int option;
    string username, password, name, lastname;
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
            // بعدا کاملش کن باید از جیسون بخونم
            break;
        }
        else if (option == 2)
        {
            cout << "Enter your username" << endl;
            cin >> username;
            cout << "Enter your password" << endl;
            cin >> password;
            cout << "Enter your name" << endl;
            cin >> name;
            cout << "Enter your lastname" << endl;
            cin >> lastname;
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
    FILE *fp;
    fp = fopen("info.json", "a+");
    if (fp == nullptr)
    {
        cout << "error in openning file" << endl;
        exit(0);
    }
    json jsonarray;
    fseek(fp, 0, SEEK_END);
    int fpsize = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    if (fpsize == 0)
    {
        jsonarray = json::array();
        jsonarray.push_back({{"username", user1.namegetter()}, {"password", user1.passwordgetter()}, {"name", user1.passwordgetter()}, {"lastname", user1.lastnamegetter()}});
        int size = jsonarray.size();
        string info = jsonarray.dump(size);
        int infosize = info.size();
        char *infoarray = new char[infosize];
        strcpy(infoarray, info.c_str());
        fprintf(fp, "%s", infoarray);
        delete[] infoarray;
    }
    if (fpsize > 0)
    {
        char *readfile = new char[fpsize+1];
        fread(readfile,1 , fpsize, fp);
        readfile[fpsize] = '\0';
        jsonarray = json::parse(readfile);
        jsonarray.push_back({{"username", user1.namegetter()}, {"password", user1.passwordgetter()}, {"name", user1.passwordgetter()}, {"lastname", user1.lastnamegetter()}});
        delete[] readfile;
        int size = jsonarray.size();
        string info = jsonarray.dump(size);
        int infosize = info.size();
        char *infoarray = new char[infosize];
        strcpy(infoarray, info.c_str());
        fclose(fp);
        fp = fopen("info.json", "w+");
        fprintf(fp, "%s", infoarray);
        delete[] infoarray;
    }
    fclose(fp);
}
