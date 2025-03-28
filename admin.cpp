void admincore()
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
void addnewdaneshjoo()
{
    cout << "Enter username daneshjoo";
    
}
void showkarbaranlist()
{

}
void virayeshinfokarbar();
void hazfkarbar();
void restorekarbar();
void showdoroosinfo();