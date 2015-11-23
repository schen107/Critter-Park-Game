/**************************************
 * 600.120 Intermediate Programming (Fall 2015)
 * Homework #11
 * Game.cpp
 * Last Modified: November 29, 2015
 *
 ***** Names of Contributors:
 * Steven Chen | schen107 | schen107@jhu.edu | (302)438-0262
 * Inez Lam | ilam1 | ilam1@jhu.edu | (805)338-5461
 * Code scaffolding from: Ben Mitchell
****************************************/

#include "../include/Game.hpp"

// Constructor
Game :: Game(std::string un, std::string pn, long m, int r, int v, int p) 
  : username(un), parkname(pn), money(m), reputation(r), visitors(v), price(p)
{
}

// Getters and Setters
std::string Game :: getUsername() const {
  return username;
}

std::string Game :: getParkName() const {
  return parkname;
}

long Game :: getMoney() const {
  return money;
}

int Game :: getReputation() const {
  return reputation;
}

int Game :: getVisitors() const {
  return visitors;
}

int Game :: getPrice() const {
  return price;
}

void Game :: setUsername(std::string un) {
  this->username = un;
}

void Game :: setParkname(std::string pn) {
  this->parkname = pn;
}

void Game :: setMoney(long m) {
  this->money = m;
}

void Game :: setReputation(int r) {
  this->reputation = r;
}

void Game :: setVisitors(int v) {
  this->visitors = v;
}

void Game :: setPrice(int p) {
  this->price = p;
}

// Unit Testing
void Game :: unitTest() {

  std::cout << "Starting unit tests for Game class...\n";

  int passedTests = 0;

  std::cout << "Done with unit tests for Game class." << std::endl 
            << "# tests passed: " << passedTests << "out of 6.";
}
