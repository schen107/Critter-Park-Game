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
Game :: Game(std::string un, std::string pn, int m, int r, int c, int s, int w, int v, int p) 
  : userName(un), parkName(pn), money(m), reputation(r), cutenessReputation(c), scarinessReputation(s), weirdnessReputation(w), visitors(v), price(p)
{
}

// Getters and Setters
std::string Game :: getUserName() const {
  return userName;
}

std::string Game :: getParkName() const {
  return parkName;
}

int Game :: getMoney() const {
  return money;
}

int Game :: getReputation() const {
  return reputation;
}

int Game :: getCutenessReputation() const {
  return cutenessReputation;
}

int Game :: getScarinessReputation() const {
  return scarinessReputation;
}

int Game :: getWeirdnessReputation() const {
  return weirdnessReputation;
}

int Game :: getVisitors() const {
  return visitors;
}

int Game :: getPrice() const {
  return price;
}

void Game :: setUserName(std::string un) {
  this->userName = un;
}

void Game :: setParkName(std::string pn) {
  this->parkName = pn;
}

void Game :: setMoney(int m) {
  this->money = m;
}

void Game :: setReputation(int r) {
  this->reputation = r;
}

void Game :: setCutenessReputation(int c) {
  this->cutenessReputation = c;
}

void Game :: setScarinessReputation(int s) {
  this->scarinessReputation = s;
}

void Game :: setWeirdnessReputation(int w) {
  this->weirdnessReputation = w;
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
