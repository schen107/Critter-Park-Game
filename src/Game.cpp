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

// Static Variable Initializers
std::string Game::menuChoice = "none";
int Game::money = 10000;
Critter Game::tempCritter;
int Game::index = 0;

// Constructor
Game :: Game(std::string un, std::string pn, /*int m,*/ double r, double c, double s, double w, int v, int p) 
  : userName(un), parkName(pn), /*money(m),*/ reputation(r), cutenessReputation(c), scarinessReputation(s), weirdnessReputation(w), visitors(v), price(p)
{
}

// Getters and Setters
std::string Game :: getUserName() const {
  return userName;
}

std::string Game :: getParkName() const {
  return parkName;
}

int Game :: getMoney() {
  return money;
}

double Game :: getReputation() const {
  return reputation;
}

double Game :: getCutenessReputation() const {
  return cutenessReputation;
}

double Game :: getScarinessReputation() const {
  return scarinessReputation;
}

double Game :: getWeirdnessReputation() const {
  return weirdnessReputation;
}

int Game :: getVisitors() const {
  return visitors;
}

int Game :: getPrice() const {
  return price;
}

std::string Game :: getMenuChoice() {
  return menuChoice;
}

Critter Game :: getTempCritter() {
  return tempCritter;
}

void Game :: setUserName(std::string un) {
  this->userName = un;
}

void Game :: setParkName(std::string pn) {
  this->parkName = pn;
}

void Game :: setMoney(int m) {
  money = m;
}

void Game :: setReputation(double r) {
  this->reputation = r;
}

void Game :: setCutenessReputation(double c) {
  this->cutenessReputation = c;
}

void Game :: setScarinessReputation(double s) {
  this->scarinessReputation = s;
}

void Game :: setWeirdnessReputation(double w) {
  this->weirdnessReputation = w;
}

void Game :: setVisitors(int v) {
  this->visitors = v;
}

void Game :: setPrice(int p) {
  this->price = p;
}

void Game :: setMenuChoice(std::string s) {
  menuChoice = s;
}
    
void Game :: setTempCritter(Critter c) {
  tempCritter = c;
}

// Unit Testing
void Game :: unitTest() {

  std::cout << "Starting unit tests for Game class...\n";
  
  int passedTests = 0;
  Game test;

  test.setUserName("ben");
  if (test.getUserName() == "ben") {
    passedTests++;
  }

  test.setReputation(40.5);
  if (test.getReputation() == 40.5) {
    passedTests++;
  }
  
  test.setPrice(5);
  if (test.getPrice() == 5) {
    passedTests++;
  }


  std::cout << "Done with unit tests for Game class." 
            << "# tests passed: " << passedTests << " out of 3.\n";
}
