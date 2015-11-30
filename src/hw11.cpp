/**************************************
 * 600.120 Intermediate Programming (Fall 2015)
 * Homework #11
 * hw11.cpp
 * Last Modified: November 29, 2015
 *
 ***** Names of Contributors:
 * Steven Chen | schen107 | schen107@jhu.edu | (302)438-0262
 * Inez Lam | ilam1 | ilam1@jhu.edu | (805)338-5461
 * Code scaffolding from: Ben Mitchell
****************************************/


#include "../include/CritterParkUI.hpp"


int main() {

  // Save terminal contents and cursor position
  std::cout << "\x1b" << "7"; // save cursor position
  std::cout << "\x1b[?47h"; // save screen contents
  std::cout << "\x1b[2J"; // clear screen

  printf("\nWelcome to Critter Park!\n");

  CritterParkUI myCritterPark;
  myCritterPark.critterParkUserInterface();

  // Restore things to the way they were
  std::cout << "\x1b[0m"; // Restore to default text mode
  std::cout << "\x1b[?47l"; // Restore screen contents
  std::cout << "\x1b" << "8"; // Restore cursor position

  std::cout << "Goodbye! Thank you for playing Critter Park!\n";
  return 0;
}
