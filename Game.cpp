//
// Created by ruby on 12.04.18.
//

#include "Game.h"

specialScript::specialScript() {typeID = (char*) typeid(*this).name();}