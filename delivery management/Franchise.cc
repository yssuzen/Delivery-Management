#include "Franchise.h"

int Franchise::nextId = 1;

const string Franchise::menu[MENU_ITEMS] = {
    "1. Large Poutine",
    "2. Medium Poutine",
    "3. Small Poutine"
};

Franchise::Franchise(const string& name, Location location): Entity(code, nextId++, name, location){}

Franchise::Franchise(const string& name) : Entity(code, nextId++, name, Location(0, 0)){}

Franchise::~Franchise(){

}

void Franchise::print() const{
	cout<<"Franchise:"<<endl;
	Entity::print();
}

void Franchise::printMenu(){
	for(int i = 0; i < MENU_ITEMS; i++){
		cout<<menu[i]<<endl;
	}
}

string Franchise::getMenu(int index){
	if(index < 0 || index > MENU_ITEMS){
		return "unkown menu item";
	}
	else{
		return menu[index];
	}
}
