#include "header.h"

int main()
{
    cout << "\n\t\t**** WHEELER DEALER 7000 ****\n\n"
         << endl;

    int choice = 0;
    bool l = false;

    Vehicle v;
    Auction a;
    User *u1;

    do
    {
        cout << "\nWho are you: " << endl;
        cout << "1) Buyer" << endl;
        cout << "2) Seller" << endl;
        cout << "3) Admin" << endl;
        cout << "4) Exit" << endl;
        cin >> choice;

        if (choice == 1)
        {
            u1 = new Buyer;
            cout << endl;
            cout << "1) Login" << endl;
            cout << "2) Register" << endl;
            cin >> choice;
            switch (choice)
            {
            case 1:
                l = u1->Login();
                if (l == true)
                {
                    u1->Menu(v, a);
                }
                break;
            case 2:
                u1->Register();
                l = u1->Login();
                if (l == true)
                {
                    u1->Menu(v, a);
                }
                break;
            default:
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
                cout << "\nInvalid Input" << endl;
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
                break;
            }
        }
        else if (choice == 2)
        {
            u1 = new Seller;
            cout << endl;
            cout << "1) Login" << endl;
            cout << "2) Register" << endl;
            cin >> choice;
            switch (choice)
            {
            case 1:
                l = u1->Login();
                if (l == true)
                {
                    u1->Menu(v, a);
                }
                break;
            case 2:
                u1->Register();
                l = u1->Login();
                if (l == true)
                {
                    u1->Menu(v, a);
                }
                break;
            default:
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
                cout << "\nInvalid Input" << endl;
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
                break;
            }
        }
        else if (choice == 3)
        {
            u1 = new Admin;
            cout << endl;
            l = u1->Login();
            if (l == true)
            {
                u1->Menu(v, a);
            }
        }
    } while (choice == 1 || choice == 2 || choice == 3);

    delete u1;
    cout << "\n\n\t\t\tGood Bye !!\n"
         << endl;

    return 0;
}