#ifndef NOTIFICATIONS_H
#define NOTIFICATIONS_H

#include "header.h"

class Notifications
{
private:
    string notifications;

public:
    Notifications();
    void viewNotifications(int choice);
    void addNotification();
    void removeNotification();
    ~Notifications();
};

#endif