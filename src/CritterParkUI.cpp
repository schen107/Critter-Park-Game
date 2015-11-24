/**************************************
 * 600.120 Intermediate Programming (Fall 2015)
 * Homework #11
 * CritterParkUI.cpp
 * Last Modified: November 29, 2015
 *
 ***** Names of Contributors:
 * Steven Chen | schen107 | schen107@jhu.edu | (302)438-0262
 * Inez Lam | ilam1 | ilam1@jhu.edu | (805)338-5461
 * Code scaffolding from: Ben Mitchell
****************************************/

#include "../include/CritterParkUI.hpp"


void CritterParkUI :: mainMenu() {

  printf("--------------------------------------------------------------------------\n");
  printf("\nMain Menu:\n");
  printf("\tn - start a new game\n");
  printf("\tq - quit the game\n");


}

void CritterParkUI :: critterParkUserInterface() {
  std::string input;

  // Print menu and get user input
  mainMenu();
  printf("Enter choice: ");
  std::cin >> input;

  // Start a new game
  if (input == "n") {
    std::cout << "Starting a new Critter Park game...\n";
    std::cout << "You will start out with 3 critters in your barn.\n";
    std::cout << "Please enter your name: ";
    std::string user;
    std::cin.ignore(1000,'\n');
    std::getline(std::cin,user);
    myGameUI.getGame().setUserName(user);
    std::cout << "Please enter the name of your critter park: ";
    std::string park;
    std::getline(std::cin,park);
    myGameUI.getGame().setParkName(park);
    myGameUI.gameUserInterface();
  }

  // Quit Critter Park
  else if (input == "q") {
    std::cout << std::endl << "Goodbye!\n";
    printf("--------------------------------------------------------------------------\n");
    return;
  }

  // Invalid user input
  else {
    std::cerr << "Error: Invalid user input!\n";
  } 

  // Recursively calls the main menu
  critterParkUserInterface();
}
