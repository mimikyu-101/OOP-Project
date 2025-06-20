#include "seller.h"

Seller::Seller()
{
}
bool Seller::Login()
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

    ifstream sin;
    sin.open("seller_cred.txt");
    if (!sin.is_open())
    {
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
        cout << "Failed to open file." << endl;
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    }
    getline(sin, name, ',');
    getline(sin, contact, ',');
    getline(sin, email, ',');
    getline(sin, password, '\n');

    sin.close();
    if (email_c == email && password_c == password)
    {
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        cout << "\nAccess Granted" << endl;
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        return true;
    }
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
    cout << "\nWrong Credentials" << endl;
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    return false;
}
void Seller::Register()
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

    ofstream sout;
    sout.open("seller_cred.txt", ios::app);
    while (sout)
    {
        sout << name << "," << contact << "," << email << "," << password << endl;
        break;
    }
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << "\nAdded successfully" << endl;
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    sout.close();
    loadingBar();
}
void Seller::Menu(Vehicle &vehicle, Auction &auction)
{
    bool end = false;
    while (!end)
    {
        cout << endl
             << endl;
        cout << "1) View Vehicle" << endl;
        cout << "2) Add Vehicle" << endl;
        cout << "3) Remove Vehicle" << endl;
        cout << "4) Register in Auction" << endl;
        cout << "5) View Notifications" << endl;
        cout << "6) Logout" << endl;
        int choice;
        cin >> choice;
        loadingBar();

        switch (choice)
        {
        case 1:
            vehicle.viewVehicle();
            break;
        case 2:
            vehicle.addVehicle();
            break;
        case 3:
            vehicle.removeVehicle();
            break;
        case 4:
            auction.registerAuction();
            break;
        case 5:
            noti.viewNotifications(2);
            break;
        case 6:
            end = true;
            break;
        default:
            break;
        }
        system("pause");
    }
}
void Seller::contactSeller()
{
    cout << "\n\tSeller Information\n"
         << endl;
    cout << "Seller Name: \t\t" << name << endl;
    cout << "Seller Contact: \t" << contact << endl;
    cout << "Seller Email: \t\t" << email << endl;
}
Seller::~Seller()
{
}