/**************************************
 * 600.120 Intermediate Programming (Fall 2015)
 * Homework #11
 * ParkUI.cpp
 * Last Modified: November 29, 2015
 *
 ***** Names of Contributors:
 * Steven Chen | schen107 | schen107@jhu.edu | (302)438-0262
 * Inez Lam | ilam1 | ilam1@jhu.edu | (805)338-5461
 * Code scaffolding from: Ben Mitchell
****************************************/

#include "../include/ParkUI.hpp"

Park& ParkUI :: getPark() {
  return myPark;
}

bool ParkUI :: checkIfStringIsInt(std::string str) {

  for (unsigned int i=0; i<str.length(); i++) {
    if (!isdigit(str[i])) {
      return false;
    }
  }
  return true;
}

// Function to print out a list of critters

void ParkUI :: printDisplayList() {

  printf("--------------------------------------------------------------------------\n");
  printf("\tYour Park:\n");

  // For empty list
  if (!myPark.getDisplayList().size()) {
    printf("You don't have any critters right now!\n");
    return;
  }

  // Print out index and name for all critters in vector
  printf("Index\t|  Name\n");
  for (unsigned int i=0; i < myPark.getDisplayList().size(); i++) {
    std::cout << i << "\t|  " 
      << myPark.getDisplayList()[i].getName()
      << std::endl;
  }
}

/* Function to print the main menu for the user
 * Prints the menu into stdout to show program options
*/
void ParkUI :: printMenu() {

  // Print statements
  printDisplayList();
  printf("--------------------------------------------------------------------------\n");
  printf("\nPark Main Menu:\n");
  printf("\tc <name> - Buy a display called <name> and add to end of display list\n");
  printf("\td <index> - display the description for the display at <index>\n");
  printf("\tr <index> - sell the display at <index>\n");
  printf("\ts - sort the displays alphabetically by their names\n");
  printf("\tt <index> - transfer critter in display <index> to barn\n");
  printf("\tb - switch to barn menu\n");
  printf("\tq - quit to decision phase menu\n");
}

// Main Menu
void ParkUI :: parkUserInterface() {
  std::string input;

  // Print menu and get user input
  printMenu();
  printf("Enter choice: ");
  std::cin >> input;

  // Check for valid user input and runs the proper function

  // Buy Display
  if (input == "c") {
    srand(time(NULL));
    std::string name;
    std::cin >> name;
    std::cout << "Creating display called " << name << "...\n";
    Display temp(name);
    std::vector<Display> tempList;
    tempList = myBarn.getDisplayList();
    tempList.push_back(temp);
    myBarn.setDisplayList(tempList);
  }

  // Modify critter
  else if (input == "m") {
    std::string ind;
    std::cin >> ind;
    if (!checkIfStringIsInt(ind)) {
      std::cerr << "Error: Index must be an integer!\n";
      barnUserInterface();
      return;
    }

    int index = stoi(ind);
    // Check for valid index
    if (index < 0){
      std::cerr << "Error: Index is less than zero!\n";
    }
    else {
      unsigned int index_us = (unsigned int) index;
      if (index_us >= (myBarn.getCritterList().size())) {
        std::cerr << "Error: Index is too big!\n";
      }
      else {
        std::cout << "Modifying critter at index " << index << "...\n";
        modifyCritterMenu(index);
      }
    }
  }

  // Breed critters
  else if (input == "b") {
    std::string c1;
    std::string c2;
    std::string name;
    std::cin >> c1 >> c2 >> name;

    if (!checkIfStringIsInt(c1) || !checkIfStringIsInt(c2)) {
      std::cerr << "Error: Indices must be integers!\n";
      barnUserInterface();
      return;
    }

    int p1 = stoi(c1);
    int p2 = stoi(c2);
    std::cout << "Breeding critters \"" << myBarn.getCritterList()[p1].getName() << "\" and \"" << myBarn.getCritterList()[p2].getName() << "\" to produce \"" << name << "\"...\n";

    std::vector<Critter> tempList = myBarn.getCritterList();
    tempList.push_back(myBarn.getCritterList()[p1].breedCritter(myBarn.getCritterList()[p2], name));
    myBarn.setCritterList(tempList);
  }

  // Display critter
  else if (input == "d") {
    std::string ind;
    std::cin >> ind;
    if (!checkIfStringIsInt(ind)) {
      std::cerr << "Error: Index must be an integer!\n";
      barnUserInterface();
      return;
    }

    int index = stoi(ind); 
    // Check for valid index
    if (index < 0){
      std::cerr << "Error: Index is less than zero!\n";
    }
    else {
      unsigned int index_us = (unsigned int) index;
      if (index_us >= (myBarn.getCritterList().size())) {
        std::cerr << "Error: Index is too big!\n";
      }
      else {
        std::cout << "Displaying critter at index " << index << "...\n";
        std::cout << myBarn.getCritterList()[index];
      }
    }
  }
  
  // Sell Critters
  else if (input == "r") {
    std::string ind;
    std::cin >> ind;
    if (!checkIfStringIsInt(ind)) {
      std::cerr << "Error: Index must be an integer!\n";
      barnUserInterface();
      return;
    }

    int index = stoi(ind); 
    // Check for valid index
    if (index < 0){
      std::cerr << "Error: Index is less than zero!\n";
    }
    else {
      unsigned int index_us = (unsigned int) index;
      if (index_us >= (myBarn.getCritterList().size())) {
        std::cerr << "Error: Index is too big!\n";
      }
      else {
        std::cout << "Selling critter at index " << index << "...\n";
        myBarn.removeCritter(index_us);
      }
    }
  }
  
  // Sort Critter
  else if (input == "s") {
    std::cout << "Sorting your critters...\n";
    myBarn.sortCritters();
  }
  // Quit option
  else if (input == "q") {
    std::cout << std::endl << "Goodbye!\n";
    printf("--------------------------------------------------------------------------\n");
    return;
  }

  // Invalid user input
  else {
    std::cerr << "Error: Invalid user input!\n";
  } 

  // Recursively calls the barn user interface
  barnUserInterface();

}
