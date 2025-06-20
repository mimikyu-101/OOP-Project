#ifndef SELLER_H
#define SELLER_H

#include "user.h"
#include "vehicle.h"
#include "auction.h"
#include "notifications.h"

class Seller : public User
{
private:
    Notifications noti;

public:
    Seller();
    bool Login();
    void Register();
    void Menu(Vehicle &vehicle, Auction &auction);
    void contactSeller();
    ~Seller();
};

#endif