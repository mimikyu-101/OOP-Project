#ifndef AUCTION_H
#define AUCTION_H

#include "user.h"
#include "seller.h"
#include "vehicle.h"

class Seller;
class Vehicle;

class Auction
{
private:
    double startingBid, currentBid;
    bool isOpen;
    Seller *s;
    Vehicle *v;

public:
    Auction();
    void registerAuction();
    void viewAuction(int choice);
    ~Auction();
};

#endif