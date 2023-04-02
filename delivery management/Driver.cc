#include "Driver.h"

int Driver::nextId = 1;

Driver::Driver(const string& name, Location location): Entity(code, nextId++, name, location){}

Driver::Driver(const string& name) : Entity(code, nextId++, name, Location(0, 0)){}

Driver::~Driver(){
	
}

bool Driver::isFree(){
	return getNumOrders() == 0;
}

void Driver::print() const{
	cout<<"Driver:"<<endl;
	Entity::print();
}
