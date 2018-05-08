#include "Ship.h"
#include "Mediator.h"
#include "IMediator.h"
#include "IShip.h"
#include "Mediator.h"
#include "Ship.h"

// Badprog.com

//-----------------------------------------------------------------------------
// main
//-----------------------------------------------------------------------------
int main() {
	auto ship1 = std::make_unique<Ship>(std::string("Scout"));
	auto ship2 = std::make_unique<Ship>(std::string("Extractor 1"));
	auto ship3 = std::make_unique<Ship>(std::string("Extractor 2"));
	auto ship4 = std::make_unique<Ship>(std::string("Extractor 3"));
	auto ship5 = std::make_unique<Ship>(std::string("Extractor 4"));
	auto mediator1 = std::make_unique<Mediator>();
	const std::vector<std::unique_ptr<IShip>> &personalVector = mediator1->getVectorOfExtractors();

	mediator1->addNewRegistered(std::move(ship2));
	mediator1->addNewRegistered(std::move(ship3));
	mediator1->addNewRegistered(std::move(ship4));
	mediator1->addNewRegistered(std::move(ship5));
	std::cout << std::endl;
	ship1->sendMessage(*mediator1, IShip::ORE_SILVER, 40.741895, -73.989308);
	std::cout << std::endl;
	std::cout << ship1->getName() << " is going to send a message:" << std::endl;
	ship1->sendMessage(*mediator1, IShip::ORE_GOLD, -33.856769, 151.215158);
	std::cout << std::endl;

	return 0;
}
