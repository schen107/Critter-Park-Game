/**************************************
 * 600.120 Intermediate Programming (Fall 2015)
 * Homework #11
 * GameUI.cpp
 * Last Modified: November 29, 2015
 *
 ***** Names of Contributors:
 * Steven Chen | schen107 | schen107@jhu.edu | (302)438-0262
 * Inez Lam | ilam1 | ilam1@jhu.edu | (805)338-5461
 * Code scaffolding from: Ben Mitchell
****************************************/

#include "../include/GameUI.hpp"

bool GameUI :: checkIfStringIsInt(std::string str) {

  for (unsigned int i=0; i<str.length(); i++) {
    if (!isdigit(str[i])) {
      return false;
    }
  }
  return true;
}

Game& GameUI :: getGame() {
  Game& gr = this->myGame;
  return gr;
}

BarnUI& GameUI:: getBarnUI() {
  BarnUI& br = this->myBarnUI;
  return br;
}

void GameUI :: printDecisionPhaseMenu() {

  
  printf("--------------------------------------------------------------------------\n");
  printf("\nDecision Phase Menu:\n");
  printf("\td - display summary of most recent stats\n");
  printf("\te - start effect phase\n");
  printf("\tb - go to barn menu\n");
  printf("\tp - go to park menu\n");
  printf("\ts <int> - set admission price as <int>\n");
  printf("\tq - quit to main menu\n");

}

void GameUI :: effectPhaseDisplay() {

  // TODO
  std::cout << "Things happen during effect phase.\n";

}

// Function for printing menus and handling input for the game
void GameUI :: gameUserInterface() {
  std::string input;

  // Print menu and get user input
  printDecisionPhaseMenu();
  printf("Enter choice: ");
  std::cin >> input;

  // Display Summary
  if (input == "d") {
    printf("--------------------------------------------------------------------------\n");
    std:: cout << "Game Information"
      << "\n\tUser Name: " << myGame.getUserName()
      << "\n\tPark Name: " << myGame.getParkName()
      << "\n\tAdmissions Price: $" << myGame.getPrice()  
      << "\n\tTotal Money: $" << myGame.getMoney()
      << "\n\tOverall Reputation: " << myGame.getReputation()
      << "\n\t\tCuteness Reputation: " << myGame.getCutenessReputation()
      << "\n\t\tScariness Reputation: " << myGame.getScarinessReputation()
      << "\n\t\tWeirdness Reputation: " << myGame.getWeirdnessReputation()
      << "\n\tDuring Last Effect Phase:"
      << "\n\t\tVisitors: " << myGame.getVisitors()
      << "\n\t\tIncome: $" << myGame.getPrice()*myGame.getVisitors()
      << "\n\t\tExpenses: $" << myBarnUI.getBarn().getCritterList().size()*10 << std::endl;
  }

  // Effect Phase
  else if (input == "e") {
    effectPhaseDisplay();
  }

  // Barn Menu
  else if (input == "b") {
    myBarnUI.barnUserInterface();
  }
  
  // Park Menu
  else if (input == "p") {
    std::cout << "Going to Park Menu\n";
    //TODO
    // myParkUI.parkUserInterface();
  }

  // Set Admission Price
  else if (input == "s") {
    std::string p;
    std::cin >> p;
    if (!checkIfStringIsInt(p)) {
      std::cerr << "Error: Price must be an integer!\n";
      gameUserInterface();
      return;
    }
    
    int newPrice = stoi(p);
    if (newPrice < 0) {
      std::cerr << "Error: Price is less than zero!\n";
    }
    else {
      myGame.setPrice(newPrice);
      std::cout << "The new admissions price for your park is $"
        << myGame.getPrice() << ".\n";
    }
  }

  // Quit to Main Menu
  else if (input == "q") {
    std::cout << std::endl << "Quitting to main menu!\n";
    printf("--------------------------------------------------------------------------\n");
    return;
  }

  // Invalid user input
  else {
    std::cerr << "Error: Invalid user input!\n";
  }

  // Recursively calls the game user interface
  gameUserInterface();

}
