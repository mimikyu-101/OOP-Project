#include "notifications.h"

Notifications::Notifications()
{
}
void Notifications::viewNotifications(int choice)
{
    cout << "\n\tNotifications" << endl;
    ifstream vnin;
    if (choice == 1)
    {
        vnin.open("buyer_notifications.txt");
        while (!vnin.eof())
        {
            getline(vnin, notifications, '\n');
            cout << notifications << endl
                 << endl;
        }
    }
    else if (choice == 2)
    {
        vnin.open("seller_notifications.txt");
        while (!vnin.eof())
        {
            getline(vnin, notifications, '\n');
            cout << notifications << endl
                 << endl;
        }
    }
    vnin.close();
}
void Notifications::addNotification()
{
    cout << endl;
    cout << "\tAdd Notification\n\n"
         << endl;
    cout << "Who gets the notification: " << endl;
    cout << "1) Buyer" << endl;
    cout << "2) Seller" << endl;
    int choice;
    cin >> choice;
    cout << "Type the notification: " << endl;
    cin.ignore();
    getline(cin, notifications);
    ofstream nout;
    if (choice == 1)
    {
        nout.open("buyer_notifications.txt", ios::app);
        while (nout)
        {
            nout << "\n"
                 << notifications;
            break;
        }
    }
    else if (choice == 2)
    {
        nout.open("seller_notifications.txt", ios::app);
        while (nout)
        {
            nout << "\n"
                 << notifications;
            break;
        }
    }

    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << "\nAdded successfully" << endl;
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    nout.close();
}
void Notifications::removeNotification()
{
    cout << "\n\tDelete Notification\n\n"
         << endl;
    cout << "1) Buyer" << endl;
    cout << "2) Seller" << endl;
    int choice;
    cin >> choice;
    ifstream nin;
    ofstream temp("temp.txt");
    int currentLine = 0, linetodelete = 0;
    switch (choice)
    {
    case 1:
        nin.open("buyer_notifications.txt");
        while (!nin.eof())
        {
            getline(nin, notifications, '\n');
            cout << notifications << endl;
        }
        nin.clear();
        nin.seekg(0);
        cout << "\nEnter the number of notification you want to delete: ";
        cin >> linetodelete;
        while (getline(nin, notifications, '\n'))
        {
            currentLine++;
            if (currentLine != linetodelete)
            {
                temp << notifications << endl;
            }
        }
        nin.close();
        temp.close();
        remove("buyer_notifications.txt");
        rename("temp.txt", "buyer_notifications.txt");
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        cout << "\nRemoved Successfully" << endl;
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        break;
    case 2:
        nin.open("seller_notifications.txt");
        while (!nin.eof())
        {
            getline(nin, notifications, '\n');
            cout << notifications << endl;
        }
        nin.clear();
        nin.seekg(0);
        cout << "\nEnter the number of notification you want to delete: ";
        cin >> linetodelete;
        while (getline(nin, notifications, '\n'))
        {
            currentLine++;
            if (currentLine != linetodelete)
            {
                temp << notifications << endl;
            }
        }
        nin.close();
        temp.close();
        remove("seller_notifications.txt");
        rename("temp.txt", "seller_notifications.txt");
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        cout << "\nRemoved Successfully" << endl;
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        break;
    default:
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
        cout << "\nInvalid Input" << endl;
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    }
}
Notifications::~Notifications()
{
}