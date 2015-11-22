/**************************************
 * 600.120 Intermediate Programming (Fall 2015)
 * Homework #9
 * Trait.cpp
 * Last Modified: November 9, 2015
 *
 ***** Names of Contributors:
 * Steven Chen | schen107 | schen107@jhu.edu | (302)438-0262
 * Inez Lam | ilam1 | ilam1@jhu.edu | (805)338-5461
 * Code scaffolding from: Ben Mitchell
****************************************/

#include "../include/Trait.hpp"

// Constructor
Trait :: Trait(std::string d, int c, int s, int w)
  : descriptor(d), cuteness(c), scariness(s), weirdness(w)
{
}

// Getters and Setters
std::string Trait :: getDescriptor() const {
  return descriptor;
}

int Trait :: getCuteness() const {
  return cuteness;
}

int Trait :: getScariness() const {
  return scariness;
}

int Trait :: getWeirdness() const {
  return weirdness;
}

void Trait :: setDescriptor(std::string d) {
  this->descriptor = d;
}

void Trait :: setCuteness(int c) {
  this->cuteness = c;
}

void Trait :: setScariness(int s) {
  this->scariness = s;
}

void Trait :: setWeirdness(int w) {
  this->weirdness = w;
}

// Outputs a descriptor string
std::string Trait :: toString() const {
  std::string str;
  str += "Cuteness: " + std::to_string(cuteness) + ", ";
  str += "Scariness: " + std::to_string(scariness) + ", ";
  str += "Weirdness: " + std::to_string(weirdness);
  return str;
}


// Operators
Trait Trait :: operator+ (const Trait &y) {
  Trait t;
  t.setDescriptor("");
  t.setCuteness(this->getCuteness()+y.getCuteness());
  t.setScariness(this->getScariness()+y.getScariness());
  t.setWeirdness(this->getWeirdness()+y.getWeirdness());
  return t;
}

Trait& Trait :: operator+= (const Trait &y) {
  this->setDescriptor("");
  this->setCuteness(this->getCuteness()+y.getCuteness());
  this->setScariness(this->getScariness()+y.getScariness());
  this->setWeirdness(this->getWeirdness()+y.getWeirdness());
  Trait &tr = *this;
  return tr;
}

// Unit Testing
void Trait :: unitTest() {
  std::cout << "Starting unit tests for Trait class...\n";

  int passedTests = 0;

  std::string str;
  str += "Cuteness: " + std::to_string(1) + ", ";
  str += "Scariness: " + std::to_string(1) + ", ";
  str += "Weirdness: " + std::to_string(1);
  
  Trait t("test",1,1,1);
  Trait t2("test2",2,2,2);
  Trait t3;

  if (t.toString() == str) {
    passedTests++;
  }
  if (t.getDescriptor() == "test") {
    passedTests++;
  }
  t.setDescriptor("test2"); 
  if (t.getDescriptor() == t2.getDescriptor()) {
    passedTests++;
  }
  t3 = t+t2;
  if (t3.getCuteness() == 3) {
    passedTests++;
  }
  if (t3.getScariness() == 3) {
    passedTests++;
  }
  if (t3.getWeirdness() == 3) {
    passedTests++;
  }

  std::cout << "Done with unit tests for Trait class." << std::endl 
            << "# tests passed: " << passedTests << "out of 6.";
}


