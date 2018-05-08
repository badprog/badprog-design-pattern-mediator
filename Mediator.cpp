#include <vector>
#include "Mediator.h"
#include "IShip.h"

// Badprog.com

//-----------------------------------------------------------------------------
// CTOR
//-----------------------------------------------------------------------------
Mediator::Mediator() {
}

//-----------------------------------------------------------------------------
// DTOR
//-----------------------------------------------------------------------------
Mediator::~Mediator() {
  std::cout << __FUNCTION__ << " byebye I was the Mediator." << std::endl;
}

//-----------------------------------------------------------------------------
// spreadMessage
//-----------------------------------------------------------------------------
void Mediator::spreadMessage(IShip::ENUM_ORE ore, double latitude, double longitude)  {
  for (auto const &element : getVectorOfExtractors()) {
    element->receiveMessage(ore, latitude, longitude);
  }
}

//-----------------------------------------------------------------------------
// addNewRegistered
//-----------------------------------------------------------------------------
void Mediator::addNewRegistered(std::unique_ptr<IShip>registered) {
  _vectorOfExtractors.push_back(std::move(registered));
}

//-----------------------------------------------------------------------------
// getVectorOfShips
//-----------------------------------------------------------------------------
const std::vector<std::unique_ptr<IShip>> &Mediator::getVectorOfExtractors() const {
  return IMediator::_vectorOfExtractors;
}
