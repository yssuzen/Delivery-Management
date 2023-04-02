#include "Pierres.h"

Pierres::Pierres():drivers(), franchises(){}

Pierres::~Pierres(){
	for(int i = 0; i < drivers.size(); i++){
		delete drivers[i];
	}
	drivers.clear();
	
	for(int i = 0; i < franchises.size(); i++){
		delete franchises[i];
	}
	franchises.clear();
}

void Pierres::addDriver(const string& name, Location loc){
	drivers.push_back(new Driver(name, loc));
}

void Pierres::addFranchise(const string& name, Location loc){
	franchises.push_back(new Franchise(name, loc));
}

void Pierres::takeOrder(const string& customerName, int menuItem, Location loc){
	Franchise* closestFranchise = findClosestFranchise(loc);
	Order* newOrder = new Order(customerName, menuItem, loc);
	closestFranchise->addOrder(newOrder);
}

void Pierres::driverPickup(const string& franchiseId, int numOrders){
	Franchise* franchise = nullptr;
	for(Franchise* f: franchises){
		if(f->equals(franchiseId)){
			franchise = f;
			break;
		}
	}
	
	if(franchise == nullptr){
		cout<<"There is not franchise with the given ID: "<<franchiseId<<endl;
		return;
	}
	
	Driver* closestDriver = findClosestAvailableDriver(franchise->getLocation());
	if(closestDriver->isFree()){
		closestDriver->setLocation(franchise->getLocation());
		for(int i = 0; i < franchise->getNumOrders(); i++){
			Order* transferOrder = franchise->getNextOrder();
			closestDriver->addOrder(transferOrder);
		}
	}else{
		cout<<"Driver is not available at the moment."<<endl;
	}
}

void Pierres::driverDeliver(const string& driverId, int numOrders){
	Driver* driver = nullptr;
	for(Driver* d: drivers){
		if(d->equals(driverId)){
			driver = d;
			break;
		}
	}
	
	if(driver == nullptr){
		cout<<"There is not driver with the given ID"<<endl;
		return;
	}else{
		for(int i = 0; i<driver->getNumOrders(); i++){
			Order* deliveredOrder = driver->getNextOrder();
			driver->setLocation(deliveredOrder->getLocation());
			cout<<"Delivering:\n"<<endl;
			deliveredOrder->print();
			delete deliveredOrder;
		}
	}
}

void Pierres::printFranchises() const{
	cout<<"Franchises:\n"<<endl;
	for(Franchise* f : franchises){
		f->print();
	}
}

void Pierres::printDrivers() const{
	cout<<"Drivers:\n"<<endl;
	for(Driver* d: drivers){
		d->print();
	}
}

Driver* Pierres::findClosestAvailableDriver(Location loc){
	Driver* closestDriver = drivers.at(0);
	double minDistance = drivers.at(0)->getLocation().getDistance(loc) - loc.getDistance(loc);
	
	for(int i = 1; i < drivers.size(); i++){
		double distance = drivers[i]->getLocation().getDistance(loc) - loc.getDistance(loc);
		if(distance < minDistance){
			minDistance = distance;
			closestDriver = drivers[i];
		}
	}
	
	return closestDriver;
}

Franchise* Pierres::findClosestFranchise(Location loc){
	Franchise* closestFranchise = franchises[0];
	double minDistance = franchises[0]->getLocation().getDistance(loc) - loc.getDistance(loc);
	
	for(int i = 1; i < franchises.size(); i++){
		double distance = franchises[i]->getLocation().getDistance(loc) - loc.getDistance(loc);
		if(distance < minDistance){
			minDistance = distance;
			closestFranchise = franchises[i];
		}
	}
	
	return closestFranchise;
}
