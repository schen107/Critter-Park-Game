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
Display :: Display (std::string n) : name(n)
{
}

// Getters and Setters
std::string Display :: getName() const {
  return name;
}

Critter Display :: getCritter() const {
  return critter;
}

void Display::setName(std::string name) {
  this->name = name;
}

void Display::setCritter(Critter c) {
  this->critter = c;
}

// String that contains description of Display
std::string Display :: toString() const {
  std::string str;

  str += "Display: \"" + name
      + "\" has Critter \"" + critter.getName() 
      + "\" in it. \nIt is covered in " + critter.getCovering().toString()
      + ". It has " + critter.getEyes().toString()
      + " and " + critter.getLimbs().toString()
      + ".\n" + critter.getTrait().toString() + "\n";
  return str;
}

// Operators
void Display :: operator= (const Display &other) {
  name = other.name;
  critter = other.critter;
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
