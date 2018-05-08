#ifndef __BADPROG_IMEDIATOR_H__
#define __BADPROG_IMEDIATOR_H__

#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include "IShip.h"

// Badprog.com

class IShip;

class IMediator
{
public:
	virtual ~IMediator() { std::cout << __FUNCTION__ << std::endl; };
	virtual void spreadMessage(IShip::ENUM_ORE ore, double latitude, double longitude) = 0;
	virtual void addNewRegistered(std::unique_ptr<IShip> registered) = 0;
	virtual const std::vector<std::unique_ptr<IShip>> &getVectorOfExtractors() const = 0;

protected:
	std::vector<std::unique_ptr<IShip>> _vectorOfExtractors;
};

#endif // __BADPROG_IMEDIATOR_H__