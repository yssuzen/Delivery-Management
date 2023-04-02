#ifndef FRANCHISE_H
#define FRANCHISE_H

#include <iostream>
#include <string>
#include "defs.h"
#include "Entity.h"

using namespace std;

class Franchise: public Entity {
    public:
        Franchise(const string&, Location);
        Franchise(const string&);
        ~Franchise();
        void print() const;
        static void printMenu();
        static string getMenu(int index);
        
    private:
        static const char code = 'F';
        static int nextId;
        static const string menu[MENU_ITEMS];
};

#endif
