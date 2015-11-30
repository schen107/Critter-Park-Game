/**************************************
 * 600.120 Intermediate Programming (Fall 2015)
 * Homework #9
 * Barn.cpp
 * Last Modified: November 9, 2015
 *
 ***** Names of Contributors:
 * Steven Chen | schen107 | schen107@jhu.edu | (302)438-0262
 * Inez Lam | ilam1 | ilam1@jhu.edu | (805)338-5461
 * Code scaffolding from: Ben Mitchell
 ****************************************/


#include "../include/Barn.hpp"

// Constructor
/*Barn :: Barn() {
  Critter temp1("Critter1");
  Critter temp2("Critter2");
  Critter temp3("Critter3");
  critterList.push_back(temp1);
  critterList.push_back(temp2);
  critterList.push_back(temp3);
}*/

std::vector<Critter> Barn :: getCritterList() {
  return critterList;
}


void Barn :: setCritterList(std::vector<Critter> list) {
  this->critterList.swap(list);
}

void Barn :: addCritter(Critter c) {
  critterList.push_back(c);
}

/* Function to remove a critter from the critter vector
 * Takes in index of critter to remove, and modifies vector accordingly
 */
void Barn :: removeCritter(unsigned int critterNumber) {
  std::vector<Critter> tempList;
  for (unsigned int i=0; i < critterList.size(); i++) {
    if (i != critterNumber) {
      tempList.push_back(critterList[i]);
    }
  }
  critterList.swap(tempList);
  tempList.clear();
  // TODO: Add money to total amount
  // Money made based on Critter's characteristic scores
  // Selling amount = $100*(cuteness+scariness+weirdness)
}

// Functions for sorting critters by name
bool Barn :: compareCritters(Critter &c1, const Critter &c2) {
  return c1 < c2;
}

void Barn :: sortCritters() {
  std::sort(critterList.begin(),critterList.end(),compareCritters);
}

// Unit Testing
void Barn :: unitTest() {
  std::cout << "Starting unit tests for Barn...\n";

  int passedTests = 0;
  Barn testBarn;
  Critter testc;
  
  testBarn.critterList.push_back(testc);

  if (testBarn.getCritterList()[0] == testc) {
    passedTests++;
  }

  Critter testc2;
  std::vector<Critter> testCritterList;
  testCritterList.push_back(testc);
  testCritterList.push_back(testc2);

  testBarn.setCritterList(testCritterList);
  if (testBarn.critterList[0] == testCritterList[0] && testBarn.critterList[1] == testCritterList[1]) {
    passedTests++;
  }

  testBarn.removeCritter(1);
  if (testBarn.critterList.size() == 1) {
    passedTests++;
  }

  std::cout << "Done with unit tests for Barn. # of tests passed: " << passedTests << " out of 2.\n";
}
