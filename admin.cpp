#include "admin.h"
#include "karbar.h"
admin::admin()
{
}
void admin::admincore()
{
    cout << "welcome boss!" << endl;
    while (1)
    {
        int option;
        cout << "what do you want to do?" << endl
             << "1-add new ostad or daneshjoo" << endl
             << "2-show list karbaran" << endl;
        cout << "3-virayesh karbaran" << endl
             << "4-hazf karbar" << endl
             << "5-restore karbar" << endl;
        cout << "6-show ettelaat doroos" << endl
             << "7-exit" << endl;
        cin >> option;
        if (option == 7)
        {
            exit(0);
        }
        switch (option)
        {
        case 1:
            addnewdaneshjoo();
            break;
        case 2:
            showkarbaranlist();
            break;
        case 3:
            virayeshinfokarbar();
            break;
        case 4:
            hazfkarbar();
            break;
        case 5:
            restorekarbar();
            break;
        case 6:
            showdoroosinfo();
            break;
        }
    }
}
void admin::addnewdaneshjoo()
{
    karbar tmp;
    tmp.signin(2);
}
void admin::showkarbaranlist()
{
    FILE *fp;
    json jsobj;
    fp = fopen("info.json", "r");
    fseek(fp, 0, SEEK_END);
    int filesize = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    char *readfile = new char[filesize + 1];
    int sizefile = fread(readfile, 1, filesize, fp);
    readfile[sizefile] = '\0';
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
        cout << jsobj[i]["name"] << endl;
    }
    fclose(fp);
    delete[] readfile;
}
void admin::virayeshinfokarbar()
{
    json jsobj;
    int option, flag = 0;
    string username, newname, newlastname, newpass;
    cout << "what do ypu want to change:" << endl
         << "1-name" << endl;
    cout << "2-latname" << endl
         << "3-password" << endl;
    cin >> option;
    FILE *fp;
    fp = fopen("info.json", "r");
    fseek(fp, 0, SEEK_END);
    int filesize = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    char *readfile = new char[filesize + 1];
    int sizefile = fread(readfile, 1, filesize, fp);
    readfile[sizefile] = '\0';
    try
    {
        jsobj = json::parse(readfile);
    }
    catch (const json::parse_error &e)
    {
        cout << "dobareh parse" << endl;
        fclose(fp);
        delete[] readfile;
        return;
    }
    cout << "Enter the username of karbar that you wanna change:" << endl;
    cin >> username;
    int jsonarray_size = jsobj.size();
    for (int i = 0; i < jsonarray_size; i++)
    {
        if (jsobj[i]["username"] == username)
        {
            if (option == 1)
            {
                cout << "name jadid" << endl;
                cin >> newname;
                jsobj[i]["name"] = newname;
            }
            else if (option == 2)
            {
                cout << "lastname jadid" << endl;
                cin >> newlastname;
                jsobj[i]["lastname"] = newlastname;
            }
            else if (option == 3)
            {
                cout << "password jadid" << endl;
                cin >> newpass;
                jsobj[i]["password"] = newpass;
            }
            else
            {
                cout << "dalghak enghgadr eshtebah nazan digeh ah!!!!!" << endl;
                exit(0);
            }
            fclose(fp);
            break;
        }
    }
    fp = fopen("info.json", "w");
    string changedinfo = jsobj.dump(4);
    fwrite(changedinfo.c_str(), 1, changedinfo.size(), fp);
    fclose(fp);
    delete[] readfile;
}
void admin::hazfkarbar()
{
    FILE *fp;
    json jsobj;
    string username;
    int flag = 0;
    fp = fopen("info.json", "r+");
    fseek(fp, 0, SEEK_END);
    int filesize = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    char *readfile = new char[filesize + 1];
    int size = fread(readfile, 1, filesize, fp);
    readfile[size] = '\0';
    cout << readfile << endl;
    try
    {
        jsobj = json::parse(readfile);
    }
    catch (const json::parse_error &e)
    {
        cout << "dobareh parse" << endl;
        fclose(fp);
        delete[] readfile;
        return;
    }
    cout << "Enter the username of karbar that you wanna delete:" << endl;
    cin >> username;
    for (int i = 0; i < jsobj.size(); i++)
    {
        if (jsobj[i]["username"] == username)
        {
            karbar user1(jsobj[i]["username"], jsobj[i]["password"], jsobj[i]["name"], jsobj[i]["lastname"]);
            karbar::writeinfile(user1, "restore.json", (int)jsobj[i]["paneloption"]);
            jsobj.erase(jsobj.begin() + i);
            flag = 1;
            break;
        }
    }
    if (!flag)
    {
        cout << "user not found!" << endl;
    }
    fclose(fp);
    delete[] readfile;
    fp = fopen("info.json", "w");
    string newinfo = jsobj.dump(4);
    fwrite(newinfo.c_str(), 1, newinfo.size(), fp);
    fclose(fp);
}
void admin::restorekarbar()
{
    json jsobj;
    creatingfile("restore.json");
    FILE *fp = fopen("restore.json", "r+");
    fseek(fp, 0, SEEK_END);
    int filesize = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    if (filesize == 0)
    {
        cout << "don't have any karbar in trashfile";
        return;
    }
    char *readfile = new char[filesize + 1];
    int size = fread(readfile, 1, filesize, fp);
    readfile[size] = '\0';
    try
    {
        jsobj = json::parse(readfile);
    }
    catch (const json::parse_error &e)
    {
        cout << "dobareh parse" << endl;
        fclose(fp);
        delete[] readfile;
        return;
    }
    for (int i = 0; i < jsobj.size(); i++)
    {
        karbar user1(jsobj[i]["username"], jsobj[i]["password"], jsobj[i]["name"], jsobj[i]["lastname"]);
        karbar::writeinfile(user1, "info.json", (int)jsobj[i]["paneloption"]);
        jsobj.erase(jsobj.begin() + i);
    }
    fclose(fp);
    FILE *fp2 = fopen("restore.json", "w");
    fclose(fp2);
    delete[] readfile;
}
void creatingfile(string filename)
{
    FILE *fp = fopen(filename.c_str(), "r");
    if (fp)
    {
        fclose(fp);
        return;
    }
    else
    {
        fclose(fp);
        fp = fopen(filename.c_str(), "w");
        fclose(fp);
    }
}
void admin::showdoroosinfo()
{
    json jsonarray = parsejson("doroos.json");
    cout << jsonarray << endl;
}
// با رابطع بین کلاس ها بعد تغریف توی کلاس استاذ باید بیای توی این قسمت