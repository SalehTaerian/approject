#ifndef KARBAR_H
#define KARBAR_H
#include <iostream>
using namespace std;
class karbar
{
private:
    string username;
    string password;
    string name;
    string lastname;

public:
    karbar(string username, string password, string name, string lastname);
    void usernamegetter();
    void passwordgetter();
    void namegetter();
    void lastnamegetter();
};
#endif