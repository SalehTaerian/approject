#ifndef KARBAR_H
#define KARBAR_H
#include <iostream>
using namespace std;
#include"json.hpp"
using json = nlohmann::json;
class karbar
{
private:
    string username;
    string password;
    string name;
    string lastname;

public:
    karbar(string given_username, string givaen_password, string given_name, string given_lastname);
    karbar();
    string usernamegetter();
    string passwordgetter();
    string namegetter();
    string lastnamegetter();
    void signin(int option);
    static void writeinfile(karbar user1 ,  string filename , int panel);
    json parsejson(string filename);
};
int usernametekrari(string newusername);
int userpassexist(string user, string pass);
#endif