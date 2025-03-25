#ifndef KARABR_H
#define KARBAR_H
#include <iostream>
using namespace std;
class karabr
{
private:
    string username;
    string password;
    string name;
    string lastname;

public:
    void usernamegetter();
    void passwordgetter();
    void namegetter();
    void lastnamegetter();
};
#endif