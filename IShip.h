#ifndef __BADPROG_ISHIP_H__
#define __BADPROG_ISHIP_H__

#include <memory>
#include <string>
#include <iostream>
#include <vector>

// Badprog.com

class IMediator;

class IShip
{
public: 
	enum ENUM_ORE { ORE_SILVER, ORE_GOLD };
public:
	virtual ~IShip() { std::cout << __FUNCTION__ << std::endl; };
	virtual void sendMessage(IMediator &mediator, const ENUM_ORE &ore, double latitude, double longitude) = 0;
	virtual void receiveMessage(IShip::ENUM_ORE ore, double latitude, double longitude) = 0;
	virtual const std::string &getName() const = 0;
private:

};

#endif // __BADPROG_ISHIP_H__