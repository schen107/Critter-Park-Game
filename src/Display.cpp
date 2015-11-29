/**************************************
 * 600.120 Intermediate Programming (Fall 2015)
 * Homework #11
 * Display.cpp
 * Last Modified: November 29, 2015
 *
 ***** Names of Contributors:
 * Steven Chen | schen107 | schen107@jhu.edu | (302)438-0262
 * Inez Lam | ilam1 | ilam1@jhu.edu | (805)338-5461
 * Code scaffolding from: Ben Mitchell
****************************************/

#include "../include/Display.hpp"

// Constructor
Display :: Display (std::string n, int max) : name(n), maxNumCritters(max)
{
}

// Getters and Setters
std::string Display :: getName() const {
  return name;
}

int Display :: getMaxNumCritters() const {
  return maxNumCritters;
}

std::vector<Critter> Display :: getCritterList() const {
  return critterList;
}

void Display::setName(std::string name) {
  this->name = name;
}

void Display :: setMaxNumCritters(int n) {
  this->maxNumCritters = n;
}

void Display::setCritterList(std::vector<Critter> list) {
  this->critterList.swap(list);
}

// String that contains description of Display
std::string Display :: toString() const {
  std::string str;

  str += "Display: \"" + name + " can hold a maximum of "
      + std::to_string(maxNumCritters) + " critter(s).\n"
      + "There are currently " + std::to_string(critterList.size()) 
      + " critter(s) inside.\n";
  if (critterList.size() > 0) {
    str += "Critters inside:\n\n";
    for (unsigned int i=0; i<critterList.size(); i++) {
      str += "Critter " + std::to_string(i) + " is named \""
          + critterList[i].getName() + "\".\n";
          + "It is covered in " + critterList[i].getCovering().toString()
          + ". It has " + critterList[i].getEyes().toString()
          + " and " + critterList[i].getLimbs().toString()
          + ".\n" + critterList[i].getTrait().toString() + "\n\n";
    }
  }
  return str;
}

// Operators
void Display :: operator= (const Display &other) {
  name = other.name;
  maxNumCritters = other.maxNumCritters;
  std::vector<Critter> temp;
  temp = other.critterList;
  critterList.swap(temp);
}

bool Display :: operator== (const Display &other) {
  return name == other.name;
}

bool Display :: operator< (const Display &other) {
  return name < other.name;
}

bool Display :: operator> (const Display &other) {
  return name > other.name;
}

// Unit Test
void Display :: unitTest() {
  std::cout << "Starting unit tests for Display...\n";

  int passedTests = 0;

  Display d("John");

  if (d.getName() == "John") {
    passedTests++;
  }

  d.setName("Ben");
  if (d.getName() == "Ben") {
    passedTests++;
  }
  
  std::cout << "Done with unit tests for Display. # of tests passed: " << passedTests << " out of 2.\n";
}

// Output Operator
std::ostream & operator<< (std::ostream & os, const Display & c) {
  os << c.toString();
  return os;
}
