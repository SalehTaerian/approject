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
#endif