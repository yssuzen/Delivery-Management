#include "Order.h"

Order::Order(const string& name, int menuItem, Location location) : name(name), menuItem(menuItem), location(location) {}

Location Order::getLocation() const{
	return location;	
}

void Order::print() const{
	cout<<"Customer Name: "<<name<<endl;
	cout<<"Menu Item order: "<<menuItem<<endl;
	//cout<<"Menu Item order: "<<Franchise::menu[menuItem]<<endl;
}
