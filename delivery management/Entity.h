#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <string>
#include "Order.h"
#include "Queue.h"
#include "Location.h"

using namespace std;

class Entity {
    public:
        Entity(char, int, const string&, Location);
        ~Entity();
        void setLocation(Location loc);
        Location getLocation();
        int getNumOrders() const;
        Order* getNextOrder();
        void addOrder(Order* order);
        void print() const;
        bool equals(const string& id);
    protected:
        string id;
        string name;
        Location location;
        Queue orders;
        
};

#endif
