#ifndef KARBAR_CPP
#define KARBAR_CPP
#include "karbar.h"
#include <iostream>
#include "json.hpp"
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
                admincore();
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
                ostad();
            }
            daneshjoo();
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
#endif