#include "auction.h"

Auction::Auction()
{
    s = new Seller;
    v = new Vehicle;
}
void Auction::registerAuction()
{
    cout << "\n\tRegister In Auction\n"
         << endl;
    ofstream aout;
    cout << "Select category: " << endl;
    cout << "1) Register an existing vehicle" << endl;
    cout << "2) Add a new vehicle" << endl;
    int choice;
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "Select category: " << endl;
        cout << "1) Used Cars" << endl;
        cout << "2) New Cars" << endl;
        cout << "3) Bikes" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
        case 2:
        case 3:
            v->viewOnly(choice);
            break;
        default:
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
            cout << "\nInvalid Input" << endl;
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
            break;
        }
        break;
    case 2:
        cout << "Add the vehicle first." << endl;
        v->addVehicle();
        cout << "\n\nNow viewing available vehicles.\n"
             << endl;
        v->viewOnly(choice);
    default:
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
        cout << "\nInvalid Input" << endl;
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        break;
    }
}
void Auction::viewAuction(int choice)
{
    cout << "\n\tView Auction\n"
         << endl;

    bool open = false;
    ifstream ain;

    switch (choice)
    {
    case 1:
        ain.open("auction_used.txt");
        open = true;
        break;
    case 2:
        ain.open("auction_new.txt");
        open = true;
        break;
    case 3:
        ain.open("auction_bikes.txt");
        open = true;
        break;
    default:
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
        cout << "\nInvalid Input" << endl;
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        open = false;
        return;
        break;
    }
    if (!ain.is_open())
    {
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
        cout << "Failed to open file." << endl;
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    }
    if (open == true)
    {
        int num = 1;
        while (ain.eof())
        {
            getline(ain, v->v_name, ',');
            getline(ain, v->company, ',');
            getline(ain, v->model, ',');
            getline(ain, v->mileage, ',');
            getline(ain, v->price, ',');
            getline(ain, v->description, ',');
            getline(ain, s->name, ',');
            getline(ain, s->contact, ',');
            getline(ain, s->email, ',');
            getline(ain, v->fuel_type, ',');
            getline(ain, v->engine, ',');
            getline(ain, v->year, ',');
            getline(ain, v->city, ',');
            getline(ain, v->color);
            cout << num << "." << endl;
            cout << "Name: \t\t" << v->v_name << endl
                 << "Company: \t" << v->company << endl
                 << "Model: \t\t" << v->model << endl
                 << "Price: \t\t" << v->price << endl
                 << "Year: \t\t" << v->year << endl
                 << "City: \t\t" << v->city << endl
                 << endl;
            num++;
        }
    }
}
Auction::~Auction()
{
}