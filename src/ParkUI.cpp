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

/*ParkUI :: ParkUI (Game& gr) : myGamer(gr)
{
}*/

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
    printf("You don't have any displays right now!\n");
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
  printf("\tbuy <name> - Buy a display called <name> for $150 and add to end of display list\n");
  printf("\td <index> - display the description for the display at <index>\n");
  printf("\tsell <index> - sell the display at <index> for $100\n");
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
  if (input == "buy") {
    srand(time(NULL));
    if (Game::getMoney() < 150) {
      std::cout << "Sorry, you don't have enough money to buy a display!\n";
    }
    else {
      Game::setMoney(Game::getMoney()-150);
      std::string name;
      std::cin >> name;
      std::cout << "Buying display called " << name << "...\n";
      Display temp(name);
      std::vector<Display> tempList;
      tempList = myPark.getDisplayList();
      tempList.push_back(temp);
      myPark.setDisplayList(tempList);
      std::cout << "You now have $" << Game::getMoney() << " left.\n";
    }
  }

  // Display description
  else if (input == "d") {
    std::string ind;
    std::cin >> ind;
    if (!checkIfStringIsInt(ind)) {
      std::cerr << "Error: Index must be an integer!\n";
      parkUserInterface();
      return;
    }

    int index = stoi(ind); 
    // Check for valid index
    if (index < 0){
      std::cerr << "Error: Index is less than zero!\n";
    }
    else {
      unsigned int index_us = (unsigned int) index;
      if (index_us >= (myPark.getDisplayList().size())) {
        std::cerr << "Error: Index is too big!\n";
      }
      else {
        std::cout << "Displaying display at index " << index << "...\n";
        std::cout << myPark.getDisplayList()[index];
      }
    }
  }
  
  // Sell Displays
  else if (input == "sell") {
    std::string ind;
    std::cin >> ind;
    if (!checkIfStringIsInt(ind)) {
      std::cerr << "Error: Index must be an integer!\n";
      parkUserInterface();
      return;
    }

    int index = stoi(ind); 
    // Check for valid index
    if (index < 0){
      std::cerr << "Error: Index is less than zero!\n";
    }
    else {
      unsigned int index_us = (unsigned int) index;
      if (index_us >= (myPark.getDisplayList().size())) {
        std::cerr << "Error: Index is too big!\n";
      }
      else {
        std::cout << "Selling display at index " << index << "...\n";
        myPark.removeDisplay(index_us);
        Game::setMoney(Game::getMoney() + 100);
        std::cout << "Your display sold for $100.\n";
        std::cout << "You now have $" << Game::getMoney() << ".\n";
      }
    }
  }
  
  // Sort Critter
  else if (input == "s") {
    std::cout << "Sorting your displays...\n";
    myPark.sortDisplays();
  }
  
  // Transfer critter to barn
  else if (input == "t") {
    std::string ind;
    std::cin >> ind;
    if (!checkIfStringIsInt(ind)) {
      std::cerr << "Error: Index must be an integer!\n";
      parkUserInterface();
      return;
    }

    int index = stoi(ind); 
    // Check for valid index
    if (index < 0){
      std::cerr << "Error: Index is less than zero!\n";
    }
    else {
      unsigned int index_us = (unsigned int) index;
      if (index_us >= (myPark.getDisplayList().size())) {
        std::cerr << "Error: Index is too big!\n";
      }
      else {
        std::cout << myPark.getDisplayList()[index];
        std::cout << "Enter the index of the critter you want to move to the barn: ";         
        std::string ind1;
        std::cin >> ind1;
        if (!checkIfStringIsInt(ind1)) {
          std::cerr << "Error: Index must be an integer!\n";
          parkUserInterface();
          return;
        }

        int index1 = stoi(ind1); 
        // Check for valid index
        if (index1 < 0){
          std::cerr << "Error: Index is less than zero!\n";
        }
        else {
          unsigned int index1_us = (unsigned int) index1;
          if (index1_us >= (myPark.getDisplayList().size())) {
            std::cerr << "Error: Index is too big!\n";
          }
          else {
            std::cout << "Transferring critter at index " << index1_us << "...\n";
            Game::setMenuChoice("movetobarn");
            Critter c = myPark.getDisplayList()[index_us].getCritterList()[index1_us];
            Game::setTempCritter(c);
            myPark.removeCritterFromDisplay(index_us, index1_us);
            return;
          }
        }     
      }
    }
  }

  // Goto to barn menu
  else if (input == "b") {
    Game::setMenuChoice("barn");
    return;
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

  // Recursively calls the park user interface
  parkUserInterface();

}
