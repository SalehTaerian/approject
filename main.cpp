#include <iostream>
#include "karbar.cpp"
#include "daneshjoo.cpp"
#include "admin.cpp"
#include "ostad.cpp"
#include "dars.cpp"
#include "mainfunc.cpp"
using namespace std;
int main()
{
    int option;
    cout << "----------welcome to yekestan----------" << endl;
    cout << "choose option:" << endl;
    cout << "1-signin" << endl;
    cout << "2-signup" << endl;
    cin >> option;
    karbar::signin(option);
    if (option == 2)
    {
        karbar::signin(2);
    }
    // مشکل پارس کردن سر اخرین حرف فایل جیسون که علامت سوال نشون می ده
}