#ifndef DRIVER_H
#define DRIVER_H

#include <iostream>
#include <string>
#include "Entity.h"

using namespace std;

class Driver: public Entity {
    public:
        Driver(const string&, Location);
        Driver(const string&);
        ~Driver();
        bool isFree();
        void print() const;
    private:
        static const char code = 'D';
        static int nextId;
};

#endif
