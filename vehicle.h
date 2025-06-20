#ifndef VEHICLE_H
#define VEHICLE_H

#include "user.h"
#include "auction.h"

class Seller;

class Vehicle
{
private:
    string v_name, company, model, mileage, price, description, fuel_type, engine, year, city, color, transmissionType, registrationNumber;
    Seller *s;

public:
    Vehicle();
    void viewOnly(int choice);
    void viewVehicle();
    void addVehicle();
    void removeVehicle();
    void inspectionReport(string b_name);
    ~Vehicle();

    friend void Auction::viewAuction(int choice);
};

#endif