#include"admin.h"
#include"karbar.h"
void admin::admincore()
{
    int option;
    cout << "welcome boss!" << endl;
    cout << "what do you want to do?" << endl
         << "1-add new daneshjoo" << endl
         << "2-show list karbaran" << endl;
    cout << "3-virayesh karbaran" << endl
         << "4-hazf karbar" << endl
         << "5-restore karbar" << endl;
    cout << "6-show ettelaat doroos" << endl;
    cin >> option;
    switch (option)
    {
    case 1:
        addnewdaneshjoo();
    case 2:
        showkarbaranlist();
    case 3:
        virayeshinfokarbar();
    case 4:
        hazfkarbar();
    case 5:
        restorekarbar();
    case 6:
        showdoroosinfo();
    }
}
void admin::addnewdaneshjoo()
{
    signin(2);
}
void showkarbaranlist()
{
    FILE *fp;
    json jsobj;
    fp = fopen("info.json", "r");
    fseek(fp, 0, SEEK_END);
    int filesize = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    char *readfile = new char[filesize + 1];
    fread(readfile, 1, filesize, fp);
    readfile[filesize] = '\0';
    try
    {
        jsobj = json::parse(readfile);
    }
    catch (const json::parse_error &e)
    {
        cout << "dobareh parse" << endl;
        delete[] readfile;
        return;
    }

    int jsonarray_size = jsobj.size();
    cout << "asami:" << endl;
    for (int i = 0; i < jsonarray_size; i++)
    {
        cout << jsobj[i]["name"]<<endl;
    }
}
void virayeshinfokarbar()
{
    
}
void hazfkarbar();
void restorekarbar();
void showdoroosinfo();