#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <iomanip>
#include <conio.h>
#include <windows.h>
#include <string>
#include <fstream>

using namespace std;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

#include "user.h"
#include "buyer.cpp"
#include "seller.cpp"
#include "admin.cpp"
#include "vehicle.cpp"
#include "auction.cpp"
#include "notifications.cpp"

#endif