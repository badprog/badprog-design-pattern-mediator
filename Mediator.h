#ifndef __BADPROG_MEDIATOR_H__
#define __BADPROG_MEDIATOR_H__

#include <iostream>
#include <string>
#include <list>
#include <memory>
#include "IMediator.h"
#include "IShip.h"

// Badprog.com

class IShip;

class Mediator : public IMediator
{
public:
	Mediator();
	virtual ~Mediator();
	virtual void spreadMessage(IShip::ENUM_ORE ore, double latitude, double longitude) override;
	virtual void addNewRegistered(std::unique_ptr<IShip> registered) override;
	virtual const std::vector<std::unique_ptr<IShip>> &getVectorOfExtractors() const override;
};

#endif // __BADPROG_MEDIATOR_H__
