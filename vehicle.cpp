#include "vehicle.h"

Vehicle::Vehicle()
{
    s = new Seller;
}
void Vehicle::viewOnly(int choice)
{
    bool open = false;
    string line;
    ifstream vin;

    switch (choice)
    {
    case 1:
        vin.open("used_cars.txt");
        open = true;
        break;
    case 2:
        vin.open("new_cars.txt");
        open = true;
        break;
    case 3:
        vin.open("bikes.txt");
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
    if (!vin.is_open())
    {
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
        cout << "Failed to open file." << endl;
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    }
    if (open == true)
    {
        int num = 1;
        while (!vin.eof())
        {
            getline(vin, v_name, ',');
            getline(vin, company, ',');
            getline(vin, model, ',');
            getline(vin, mileage, ',');
            getline(vin, price, ',');
            getline(vin, description, ',');
            getline(vin, s->name, ',');
            getline(vin, s->contact, ',');
            getline(vin, s->email, ',');
            getline(vin, fuel_type, ',');
            getline(vin, engine, ',');
            getline(vin, year, ',');
            getline(vin, city, ',');
            getline(vin, color);
            cout << num << "." << endl;
            cout << "Name: \t\t" << v_name << endl
                 << "Company: \t" << company << endl
                 << "Model: \t\t" << model << endl
                 << "Price: \t\t" << price << endl
                 << "Year: \t\t" << year << endl
                 << "City: \t\t" << city << endl
                 << endl;
            num++;
        }
    }
}
void Vehicle::viewVehicle()
{
    string line;
    int choice;
    char ch;
    int desiredLine = 0;
    cout << "\n\tView Vehicle" << endl;

    cout << "1) Used Cars" << endl;
    cout << "2) New Cars" << endl;
    cout << "3) Bikes" << endl;
    cin >> choice;

    viewOnly(choice);
    ifstream vin;

    cout << "Do  you want to expand details for any vehicle? (Y/N)";
    cin >> ch;
    if (ch == 'Y' || ch == 'y')
    {
        cout << "Select a car: ";
        cin >> desiredLine;
        vin.clear();
        vin.seekg(0);

        for (int currentLine = 1; currentLine < desiredLine; ++currentLine)
        {
            if (!getline(vin, line))
            {
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
                cout << "Error: The file does not have enough lines." << endl;
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
            }
        }
        getline(vin, v_name, ',');
        getline(vin, company, ',');
        getline(vin, model, ',');
        getline(vin, mileage, ',');
        getline(vin, price, ',');
        getline(vin, description, ',');
        getline(vin, s->name, ',');
        getline(vin, s->contact, ',');
        getline(vin, s->email, ',');
        getline(vin, fuel_type, ',');
        getline(vin, engine, ',');
        getline(vin, year, ',');
        getline(vin, city, ',');
        getline(vin, color);
        cout << "\nDetailed Information: " << endl
             << endl;
        cout << "Name: \t\t" << v_name << endl;
        cout << "Company: \t" << company << endl;
        cout << "Model: \t\t" << model << endl;
        cout << "Mileage: \t" << mileage << endl;
        cout << "Price: \t\t" << price << endl;
        cout << "Fuel Type: \t" << fuel_type << endl;
        cout << "Engine: \t" << engine << endl;
        cout << "Year: \t\t" << year << endl;
        cout << "Color: \t\t" << color << endl;
        cout << "City: \t\t" << city << endl;
        cout << "Description: \t" << description << endl;

        cout << "\nDo you want to contact the seller? (Y/N)";
        ch = 'N';
        cin >> ch;
        if (ch == 'Y' || ch == 'y')
        {
            s->contactSeller();
        }
    }
    vin.close();
}
void Vehicle::addVehicle()
{
    cout << "\n\tAdd Vehicle\n"
         << endl;
    cout << "1) Used Cars" << endl;
    cout << "2) New Cars" << endl;
    cout << "3) Bikes" << endl;
    int choice;
    cin >> choice;

    cin.ignore();

    cout << "Enter appropriate details about your vehicle below." << endl;
    cout << "Name: ";
    getline(cin, v_name);
    cout << "Company: ";
    getline(cin, company);
    cout << "Model: ";
    getline(cin, model);
    cout << "Mileage: ";
    getline(cin, mileage);
    cout << "Your offered price: ";
    getline(cin, price);
    cout << "Description: ";
    getline(cin, description);
    cout << "Fuel type: ";
    getline(cin, fuel_type);
    cout << "Engine: ";
    getline(cin, engine);
    cout << "Model Year: ";
    getline(cin, year);
    cout << "City registered: ";
    getline(cin, city);
    cout << "Color: ";
    getline(cin, color);

    ofstream vout;

    switch (choice)
    {
    case 1:
        vout.open("used_cars.txt", ios::app);
        if (!vout.is_open())
        {
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
            cout << "Failed to open file." << endl;
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        }
        else
        {
            vout << "\n"
                 << v_name << "," << company << "," << model << "," << mileage << "," << price << "," << description << "," << s->name << "," << s->contact << "," << s->email << "," << fuel_type << "," << engine << "," << year << "," << city << "," << color;
        }
        break;
    case 2:
        vout.open("new_cars.txt", ios::app);
        if (!vout.is_open())
        {
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
            cout << "Failed to open file." << endl;
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        }
        else
        {
            vout << "\n"
                 << v_name << "," << company << "," << model << "," << mileage << "," << price << "," << description << "," << s->name << "," << s->contact << "," << s->email << "," << fuel_type << "," << engine << "," << year << "," << city << "," << color;
        }
        break;
    case 3:
        vout.open("bikes.txt", ios::app);
        if (!vout.is_open())
        {
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
            cout << "Failed to open file." << endl;
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        }
        else
        {
            vout << "\n"
                 << v_name << "," << company << "," << model << "," << mileage << "," << price << "," << description << "," << s->name << "," << s->contact << "," << s->email << "," << fuel_type << "," << engine << "," << year << "," << city << "," << color;
        }
        break;
    default:
        break;
    }

    vout.close();
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << "\nAdded successfully" << endl;
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
}
void Vehicle::removeVehicle()
{
    cout << "\n\tRemove Vehicle\n"
         << endl;
    int currentLine = 0, linetodelete = 0;
    string line;
    bool open = false;
    ifstream rmin;
    ofstream temp("temp.txt");
    cout << "Select category: " << endl;
    cout << "1) Used Cars" << endl;
    cout << "2) New Cars" << endl;
    cout << "3) Bikes" << endl;
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
        rmin.open("used_cars.txt");
        if (!rmin.is_open())
        {
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
            cout << "Failed to open file." << endl;
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        }
        else
        {
            viewOnly(choice);
            cout << "Enter the number of vehicle you want to remove: " << endl;
            cin >> linetodelete;
            rmin.clear();
            rmin.seekg(0);
            while (getline(rmin, line, '\n'))
            {
                currentLine++;
                if (currentLine != linetodelete)
                {
                    temp << line << endl;
                }
            }
            remove("used_cars.txt");
            rename("temp.txt", "used_cars.txt");
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            cout << "\nRemoved Successfully" << endl;
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        }
        break;
    case 2:
        rmin.open("new_cars.txt");
        if (!rmin.is_open())
        {
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
            cout << "Failed to open file." << endl;
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        }
        else
        {
            viewOnly(choice);
            cout << "Enter the number of vehicle you want to remove: " << endl;
            cin >> linetodelete;
            rmin.clear();
            rmin.seekg(0);
            while (getline(rmin, line, '\n'))
            {
                currentLine++;
                if (currentLine != linetodelete)
                {
                    temp << line << endl;
                }
            }
            remove("new_cars.txt");
            rename("temp.txt", "new_cars.txt");
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            cout << "\nRemoved Successfully" << endl;
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        }
        break;
    case 3:
        rmin.open("bikes.txt");
        if (!rmin.is_open())
        {
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
            cout << "Failed to open file." << endl;
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        }
        else
        {
            viewOnly(choice);
            cout << "Enter the number of vehicle you want to remove: " << endl;
            cin >> linetodelete;
            rmin.clear();
            rmin.seekg(0);
            while (getline(rmin, line, '\n'))
            {
                currentLine++;
                if (currentLine != linetodelete)
                {
                    temp << line << endl;
                }
            }
            remove("bikes.txt");
            rename("temp.txt", "bikes.txt");
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            cout << "\nRemoved Successfully" << endl;
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        }
        break;
    default:
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
        cout << "\nInvalid Input" << endl;
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        break;
    }
    rmin.close();
    temp.close();
}
void Vehicle::inspectionReport(string b_name)
{
    std::cout << "----- Car Inspection Report -----\n";
    std::cout << "Customer/Dealer Name: " << b_name << "\n";
    std::cout << "Dealer Name: " << s->name << "\n";
    std::cout << "Vehicle Name: " << v_name << "\n";
    std::cout << "Engine Capacity: " << engine << "\n";
    std::cout << "Mileage: " << mileage << " miles\n";
    std::cout << "Transmission Type: " << transmissionType << "\n";
    std::cout << "Registration Number: " << registrationNumber << "\n";
    std::cout << "Fuel Type: " << fuel_type << "\n";
    std::cout << "Color: " << color << "\n";
    std::cout << "Location: " << city << "\n";
    std::cout << "Registered City: " << city << "\n";
    std::cout << "Current City: " << city << "\n";
    std::cout << "Car Features: " << description << "\n";
    std::cout << "---------------------------------\n";
}
Vehicle::~Vehicle()
{
    delete s;
}