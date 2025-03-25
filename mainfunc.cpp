#include <iostream>
#include <cstdio>
#include <string>
#include "mainheader.h"
#include "json.hpp"
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
            writeininfofile(username, password, name, lastname);
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
void writeininfofile(std::string username, std::string password, std::string name, std::string lastname)
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
    if (fpsize==0)
    {
        jsonarray = json::array();
    }
    jsonarray.push_back({{"username", username}, {"password", password}, {"name", name}, {"lastname", lastname}});
    int size = jsonarray.size();
    string info = jsonarray.dump(size);
    int infosize = info.size();
    char *infoarray = new char[infosize];
    strcpy(infoarray, info.c_str());
    fprintf(fp, "%s", infoarray);
    fclose(fp);
    delete[] infoarray;
}