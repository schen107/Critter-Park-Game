/**************************************
 * 600.120 Intermediate Programming (Fall 2015)
 * Homework #11
 * Park.cpp
 * Last Modified: November 29, 2015
 *
 ***** Names of Contributors:
 * Steven Chen | schen107 | schen107@jhu.edu | (302)438-0262
 * Inez Lam | ilam1 | ilam1@jhu.edu | (805)338-5461
 * Code scaffolding from: Ben Mitchell
****************************************/

#include "../include/Park.hpp"

std::vector<Display> Park :: getDisplayList() {
  return displayList;
}


void Park :: setDisplayList(std::vector<Display> list) {
  this->displayList.swap(list);
}

bool Park :: addCritterToDisplay(unsigned int displayNumber) {
  std::cout << "Transferring critter to display " << displayNumber << std::endl;
  std::vector<Display> tempList;
  tempList = getDisplayList();
  if (tempList[displayNumber].addCritter(Game::getTempCritter())) {
    setDisplayList(tempList);
    return true;
  }
  else {
    return false;
  }
}

// Remove Critter from a display
void Park :: removeCritterFromDisplay(unsigned int displayNumber, unsigned int critterNumber) {
  displayList[displayNumber].removeCritter(critterNumber);
}

/* Function to remove a display from the display vector
 * Takes in index of display to remove, and modifies vector accordingly
 */
void Park :: removeDisplay(unsigned int displayNumber) {
  std::vector<Display> tempList;
  for (unsigned int i=0; i < displayList.size(); i++) {
    if (i != displayNumber) {
      tempList.push_back(displayList[i]);
    }
  }
  displayList.swap(tempList);
  tempList.clear();
  // TODO: Add money to total amount
  // Money made based on Display's characteristic scores
  // Selling amount = $100*(cuteness+scariness+weirdness)
}

// Functions for sorting displays by name
bool Park :: compareDisplays(Display &d1, const Display &d2) {
  return d1 < d2;
}

void Park :: sortDisplays() {
  std::sort(displayList.begin(),displayList.end(),compareDisplays);
}

// Unit Testing
void Park :: unitTest() {
  std::cout << "Starting unit tests for Park...\n";

  int passedTests = 0;
  Park testPark;
  Display testc;
  
  testPark.displayList.push_back(testc);

  if (testPark.getDisplayList()[0] == testc) {
    passedTests++;
  }

  Display testc2;
  std::vector<Display> testDisplayList;
  testDisplayList.push_back(testc);
  testDisplayList.push_back(testc2);

  testPark.setDisplayList(testDisplayList);
  if (testPark.displayList[0] == testDisplayList[0] && testPark.displayList[1] == testDisplayList[1]) {
    passedTests++;
  }

  testPark.removeDisplay(1);
  if (testPark.displayList.size() == 1) {
    passedTests++;
  }

  std::cout << "Done with unit tests for Park. # of tests passed: " << passedTests << " out of 3.\n";
}
