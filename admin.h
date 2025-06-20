#ifndef ADMIN_H
#define ADMIN_H

#include "user.h"
#include "vehicle.h"
#include "notifications.h"

class Admin : public User
{
private:
    Notifications noti;

public:
    Admin();
    bool Login();
    void Register();
    void Menu(Vehicle &vehicle, Auction &auction);
    ~Admin();
};

#endif