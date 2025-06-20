#ifndef USER_H
#define USER_H

#include "header.h"
#include <iostream>
#include <string>
#include <conio.h>
#include <fstream>
#include <windows.h>
using namespace std;

class Vehicle;
class Auction;

class User
{
private:
    /* data */
public:
    char ch;
    string email, password, name, contact, email_c, password_c;
    User() {}
    virtual bool Login() = 0;
    virtual void Register() = 0;
    virtual void Menu(Vehicle &vehicle, Auction &a) = 0;
    void loadingBar()
    {
        cout << "\n\n";
        cout << setw(45) << "Loading...\n\n";
        cout << setw(25);

        for (int i = 0; i < 26; i++)
        {
            cout << "*";
        }
        cout << "\r";
        cout << setw(25);

        for (int i = 0; i < 26; i++)
        {
            cout << "#";

            Sleep(150);
        }
        cout << endl;
        system("CLS");
        cout << "\n\t\t**** WHEELER DEALER 7000 ****\n\n"
             << endl;
        Sleep(1000);
    }
    ~User() {}
};

#endif