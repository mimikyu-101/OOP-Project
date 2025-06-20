#ifndef BUYER_H
#define BUYER_H

#include "user.h"
#include "vehicle.h"
#include "auction.h"
#include "notifications.h"

class Buyer : public User
{
private:
    Notifications noti;

public:
    Buyer();
    bool Login();
    void Register();
    void Menu(Vehicle &vehicle, Auction &auction);
    ~Buyer();
};

#endif