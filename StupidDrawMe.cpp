#include "StupidDrawMe.h"

DrawMe::DrawMe(Triangle triangle()) {typeID = (char*) typeid(*this).name();}

DrawMe::~DrawMe() {};
