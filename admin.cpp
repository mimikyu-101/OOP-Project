#include "admin.h"

Admin::Admin()
{
}
bool Admin::Login()
{
    cout << "\n\tLogin" << endl;
    cout << "Email: ";
    cin >> email_c;
    cout << "Password: ";
    while (true)
    {
        ch = _getch();

        if (ch == '\r')
        {
            break;
        }
        else if (ch == '\b' && !password_c.empty())
        {
            password_c.pop_back();
            cout << "\b \b";
        }
        else
        {
            password_c.push_back(ch);
            cout << '*';
        }
    }
    loadingBar();

    ifstream ain;
    ain.open("admin_cred.txt");

    getline(ain, name, ',');
    getline(ain, contact, ',');
    getline(ain, email, ',');
    getline(ain, password, '\n');

    ain.close();
    if (email_c == email && password_c == password)
    {
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        cout << "\nAccess Granted" << endl;
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        return true;
    }
    else
    {
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
        cout << "\nWrong Credentials" << endl;
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        return false;
    }
}
void Admin::Menu(Vehicle &vehicle, Auction &auction)
{
    bool end = false;
    while (!end)
    {
        cout << endl
             << endl;
        cout << "1) Add Vehicle" << endl;
        cout << "2) Remove Vehicle" << endl;
        cout << "3) Manage Inspection Requests" << endl;
        cout << "4) Add Notification" << endl;
        cout << "5) Remove notifications and comments" << endl;
        cout << "6) Logout" << endl;
        int choice;
        cin >> choice;
        loadingBar();

        switch (choice)
        {
        case 1:
            vehicle.addVehicle();
            break;
        case 2:
            vehicle.removeVehicle();
            break;
        case 3:
            vehicle.inspectionReport("Someone");
            break;
        case 4:
            noti.addNotification();
            break;
        case 5:
            noti.removeNotification();
            break;
        case 6:
            end = true;
            break;
        default:
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
            cout << "\nInvalid Input" << endl;
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
            break;
        }
        system("pause");
    }
}
void Admin::Register()
{
}
Admin::~Admin()
{
}