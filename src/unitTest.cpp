/**************************************
 * 600.120 Intermediate Programming (Fall 2015)
 * Homework #9
 * unitTest.cpp
 * Last Modified: November 9, 2015
 *
 ***** Names of Contributors:
 * Steven Chen | schen107 | schen107@jhu.edu | (302)438-0262
 * Inez Lam | ilam1 | ilam1@jhu.edu | (805)338-5461
 * Code scaffolding from: Ben Mitchell
****************************************/

#include "../include/Trait.hpp"
#include "../include/Limbs.hpp"
#include "../include/Eyes.hpp"
#include "../include/Covering.hpp"
#include "../include/Critter.hpp"
#include "../include/Encoding.hpp"
#include "../include/Barn.hpp"
#include "../include/Display.hpp"
#include "../include/Park.hpp"
#include "../include/Game.hpp"

int main() {

  Trait::unitTest();
  Limbs::unitTest();
  Eyes::unitTest();
  Covering::unitTest();
  Encoding::unitTest();
  Critter::unitTest();
  Barn::unitTest();
  Display::unitTest();
  Park::unitTest();
  Game::unitTest();

  return 0;
}
