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
    //ظزفیت کم نکرد
    if (option == 2)
    {
        karbartmp.signin(1);
    }
    //احمق نمره باید توی فایل دانشجو باشه و گرنه بقیه هم نمرش می بینن و البته بقیه نمه نمی توننن داشته باشن تکلیفش هم همینظور
}