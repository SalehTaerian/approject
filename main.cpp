#include<iostream>  
#include"karbar.cpp"
#include"daneshjoo.cpp"
#include"admin.cpp"
#include"ostad.cpp"
#include"mainfunc.cpp"
using namespace std;
void welcome()
{
    cout << "----------welcome to yekestan----------";
    cout << endl;
}
int main()
{
    int option;
    welcome();
    cout << "choose option:" << endl;
    cout << "1-signin" << endl;
    cout << "2-signup" << endl;
    cin >> option;
    karbar::signin(option);
    //مشکل پارس کردن سر اخرین حرف فایل جیسون که علامت سوال نشون می ده
}