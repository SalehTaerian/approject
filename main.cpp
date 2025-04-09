#include <iostream>
#include "karbar.cpp"
#include "daneshjoo.cpp"
#include "admin.cpp"
#include "ostad.cpp"
#include "dars.cpp"
using namespace std;
int main()
{
    int option;
    cout << "----------welcome to yekestan----------" << endl;
    cout << "choose option:" << endl;
    cout << "1-signin" << endl;
    cout << "2-signup" << endl;
    cin >> option;
    karbar karbartmp;
    karbartmp.signin(option);
    if (option == 2)
    {
        karbartmp.signin(1);
    }
}