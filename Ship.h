#ifndef __BADPROG_SHIP_H__
#define __BADPROG_SHIP_H__

#include <memory>
#include "IShip.h"
 
// Badprog.com

class IMediator;

class Ship : public IShip
{
public:
	Ship(std::string _name);
	virtual ~Ship();
	virtual void sendMessage(IMediator &mediator, const IShip::ENUM_ORE &ore, double latitude, double longitude) override;
	virtual void receiveMessage(IShip::ENUM_ORE ore, double latitude, double longitude) override;
	virtual const std::string &getName() const override;
	const std::string getOreInString(const IShip::ENUM_ORE &ore) const;


private:
	std::string _name;
	std::vector<std::string> _vectorOre;
};

#endif // __BADPROG_SHIP_H__