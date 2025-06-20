#include "buyer.h"

Buyer::Buyer()
{
}
bool Buyer::Login()
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

    ifstream bin;
    bin.open("buyer_cred.txt");

    getline(bin, name, ',');
    getline(bin, contact, ',');
    getline(bin, email, ',');
    getline(bin, password, '\n');

    bin.close();
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
void Buyer::Register()
{
    cin.ignore();
    cout << "\n\tRegister" << endl;
    cout << "Enter your full name: " << endl;
    getline(cin, name, '\n');
    cout << "Enter your contact number: " << endl;
    cin >> contact;
    cout << "Enter your email: " << endl;
    cin >> email;
    cout << "Set a strong password: " << endl;
    cin >> password;

    ofstream bout;
    bout.open("buyer_cred.txt", ios::app);
    while (bout)
    {
        bout << name << "," << contact << "," << email << "," << password << endl;
        break;
    }
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << "\nAdded successfully" << endl;
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    bout.close();
}
void Buyer::Menu(Vehicle &vehicle, Auction &auction)
{
    bool end = false;
    while (!end)
    {
        cout << endl
             << endl;
        cout << "1) View Vehicles" << endl;
        cout << "2) View Auction" << endl;
        cout << "3) Request Inspection Report" << endl;
        cout << "4) View Notification" << endl;
        cout << "5) Logout" << endl;
        int choice;
        cin >> choice;
        loadingBar();

        switch (choice)
        {
        case 1:
            vehicle.viewVehicle();
            break;
        case 2:
            auction.viewAuction(1);
            break;
        case 3:
            vehicle.inspectionReport(name);
            break;
        case 4:
            noti.viewNotifications(1);
            break;
        case 5:
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
Buyer::~Buyer()
{
}