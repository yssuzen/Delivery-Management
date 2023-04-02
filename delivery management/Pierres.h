#ifndef PIERRES_H
#define PIERRES_H

#include <iostream>
#include <string>
#include "Order.h"
#include "Entity.h"
#include "Driver.h"
#include "Franchise.h"
#include <vector>

using namespace std;

class Pierres {
    public:
        Pierres();
        ~Pierres();
        void addDriver(const string&, Location);
        void addFranchise(const string&, Location);
        void takeOrder(const string& customerName, int menuItem, Location);
        void driverPickup(const string& franchiseId, int numOrders);
        void driverDeliver(const string& driverId, int numOrders);
        void printFranchises() const;
        void printDrivers() const;
        
    private:
        vector<Driver*> drivers;
        vector<Franchise*> franchises;
        Driver* findClosestAvailableDriver(Location);
    	Franchise* findClosestFranchise(Location);
};

#endif
