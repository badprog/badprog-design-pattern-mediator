#include <iostream>
#include <string>
#include "Ship.h"
#include "IMediator.h"

// Badprog.com

//-----------------------------------------------------------------------------
// CTOR
//-----------------------------------------------------------------------------
Ship::Ship(std::string name) : _name(name) {
	_vectorOre.push_back("Silver");
	_vectorOre.push_back("Gold");
}

//-----------------------------------------------------------------------------
// DTOR
//-----------------------------------------------------------------------------
Ship::~Ship() {
	std::cout << __FUNCTION__ << " byebye I was the " << _name << std::endl;
}

//-----------------------------------------------------------------------------
// getName
//-----------------------------------------------------------------------------
const std::string &Ship::getName() const {
	return _name;
}

//-----------------------------------------------------------------------------
// sendMessage
//-----------------------------------------------------------------------------
void Ship::sendMessage(IMediator &mediator, const IShip::ENUM_ORE &ore, double latitude, double longitude) {
	std::cout << getName() << " is going to send a message to its Mediator:" << std::endl;
	std::cout << "\"" << getOreInString(ore) << "\" found! Latitude: " << latitude << " and longitude: " << longitude << "." << std::endl << std::endl;
	mediator.spreadMessage(ore, latitude, longitude);
}

//-----------------------------------------------------------------------------
// receiveMessage
//-----------------------------------------------------------------------------
void Ship::receiveMessage(IShip::ENUM_ORE ore, double latitude, double longitude) {
	std::cout << this->getName() << " is receiving a message: " << std::endl;
	std::cout << "Alright I'm going to extract \"" << getOreInString(ore) << "\" at GPS coordinates (" << latitude << ", " << longitude << "). Let's go!" << std::endl << std::endl;
}

//-----------------------------------------------------------------------------
// receiveMessage
//-----------------------------------------------------------------------------
const std::string Ship::getOreInString(const IShip::ENUM_ORE &ore) const {
	return _vectorOre.at(ore);
}