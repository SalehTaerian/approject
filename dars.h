#ifndef DARS_H
#define DARS_H
#include <iostream>
#include <string>
using namespace std;
class dars
{
private:
    string darsname;
    float nomrehdars;
public:
    int zarfiat;
    class taklif
    {
        private:
            string tarikh_shoroo;
            string tarikh_payan;
            string sharh;
            float nomreh_taklif;
        public:
            taklif(string tarikh_shoroo, string tarikh_payan, string sharh, float nomreh_taklif);
            void getter(int option);
    };
    taklif *taklif[10];
    
};
#endif