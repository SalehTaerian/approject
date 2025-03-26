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
    
    karbar(string given_username, string givaen_password, string given_name, string given_lastname);
    string usernamegetter();
    string passwordgetter();
    string namegetter();
    string lastnamegetter();
};
#endif