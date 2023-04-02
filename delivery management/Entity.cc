#include "Entity.h"

Entity::Entity(char c, int num, const string& name, Location location): name(name), location(location){
	this->id = c + to_string(num);
}

Entity::~Entity(){
    while (!orders.empty()) {
        Order* order = orders.popFirst();
        delete order;
    }

}

void Entity::setLocation(Location loc){
	this->location = loc;
}

Location Entity::getLocation(){
	return location;
}

int Entity::getNumOrders() const{
	return orders.size();
}

Order* Entity::getNextOrder(){
	orders.popFirst();
}

void Entity::addOrder(Order* order){
	orders.addLast(order);
}

void Entity::print() const{
	cout<<"ID: "<<id<<endl;
	cout<<"Name: "<<name<<endl;
	location.print();
	cout<<"Number of orders: "<<getNumOrders()<<endl;
}

bool Entity::equals(const string& id){
	if(this->id == id){
		return true;
	}
	else{
		return false;
	}
}
