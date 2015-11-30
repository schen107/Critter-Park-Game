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
  return myGame;
}

BarnUI& GameUI:: getBarnUI() {
  return myBarnUI;
}

ParkUI& GameUI:: getParkUI() {
  return myParkUI;
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

  std::cout << "Starting effect phase...\n";
  srand(time(NULL));
  int numVisitors = (myGame.getReputation()-myGame.getPrice()*0.5)*(0.8+rand()%40/100);
  int expenses = myBarnUI.getBarn().getCritterList().size()*10 + myParkUI.getPark().getDisplayList().size()*20;
  int moneyMade = numVisitors*myGame.getPrice();
  myGame.setMoney(myGame.getMoney()+moneyMade-expenses);

  int totalCuteness;
  int totalScariness;
  int totalWeirdness;
  double cutenessChange;
  double scarinessChange;
  double weirdnessChange;
  double turnReputation;

  for (unsigned int i=0; i<myParkUI.getPark().getDisplayList().size(); i++) {
    totalCuteness += myParkUI.getPark().getDisplayList()[i].getCuteness();
    totalScariness += myParkUI.getPark().getDisplayList()[i].getScariness();
    totalWeirdness += myParkUI.getPark().getDisplayList()[i].getWeirdness();
  }

  for (int i=0; i<numVisitors; i++) {
    double temp = rand()%100;
    if (temp >= 0 && temp < myGame.getCutenessReputation()) {
      if (totalCuteness <= 0) {
        cutenessChange -= 0.1;
        scarinessChange += 0.05;
        weirdnessChange += 0.05;
        /*double cutenessChange = myGame.getCutenessReputation() - 0.5;
        if (cutenessChange <= 0) {
          myGame.setCutenessReputation(0);
          myGame.setScarinessReputation(myGame.getScarinessReputation()+(0.5+cutenessChange)/2);
          myGame.setWeirdnessReputation(myGame.getWeirdnessReputation()+(0.5+cutenessChange)/2);
          }
        else {
          myGame.setCutenessReputation(cutenessChange);
          myGame.setScarinessReputation(myGame.getScarinessReputation() + 0.25);
          myGame.setWeirdnessReputation(myGame.getWeirdnessReputation() + 0.25);
        }*/
        turnReputation -= 0.5;
      }
      else if (totalCuteness > 0 && totalCuteness <= 10) {
        cutenessChange += 0.1;
        scarinessChange -= 0.05;
        weirdnessChange -= 0.05;
        /*double cutenessChange = myGame.getCutenessReputation() + 0.5;
        if (cutenessChange >= 100) {
          myGame.setCutenessReputation(100);
          myGame.setScarinessReputation(myGame.getScarinessReputation()-(100.5-cutenessChange)/2);
          myGame.setWeirdnessReputation(myGame.getWeirdnessReputation()-(100.5-cutenessChange)/2);
        }
        else {
          myGame.setCutenessReputation(cutenessChange);
          myGame.setScarinessReputation(myGame.getScarinessReputation() - 0.25);
          myGame.setWeirdnessReputation(myGame.getWeirdnessReputation() - 0.25);
        }*/
        turnReputation += 0.5;
      }
      else if (totalCuteness > 10 && totalCuteness <= 20) {
        cutenessChange += 0.2;
        scarinessChange -= 0.1;
        weirdnessChange -= 0.1;
        /*double cutenessChange = myGame.getCutenessReputation() + 1;
        if (cutenessChange >= 100) {
          myGame.setCutenessReputation(100);
          myGame.setScarinessReputation(myGame.getScarinessReputation()-(101-cutenessChange)/2);
          myGame.setWeirdnessReputation(myGame.getWeirdnessReputation()-(101-cutenessChange)/2);
        }
        else {
          myGame.setCutenessReputation(cutenessChange);
          myGame.setScarinessReputation(myGame.getScarinessReputation() - 0.5);
          myGame.setWeirdnessReputation(myGame.getWeirdnessReputation() - 0.5);
        }*/
        turnReputation += 1;
      }
      else {
        cutenessChange += 0.3;
        scarinessChange -= 0.15;
        weirdnessChange -= 0.15;
        /*double cutenessChange = myGame.getCutenessReputation() + 1.5;
        if (cutenessChange >= 100) {
          myGame.setCutenessReputation(100);
          myGame.setScarinessReputation(myGame.getScarinessReputation()-(101.5-cutenessChange)/2);
          myGame.setWeirdnessReputation(myGame.getWeirdnessReputation()-(101.5-cutenessChange)/2);
        }
        else {
          myGame.setCutenessReputation(cutenessChange);
          myGame.setScarinessReputation(myGame.getScarinessReputation() - 0.75);
          myGame.setWeirdnessReputation(myGame.getWeirdnessReputation() - 0.75);
        }*/
        turnReputation += 1.5;
      }
    }
    else if (temp >= myGame.getCutenessReputation() && temp < myGame.getCutenessReputation()+myGame.getScarinessReputation()) {
      if (totalScariness <= 0) {
        cutenessChange += 0.05;
        scarinessChange -= 0.1;
        weirdnessChange += 0.05;
        /*myGame.setScarinessReputation(myGame.getScarinessReputation() - 2);
        myGame.setScarinessReputation(myGame.getScarinessReputation() + 1);
        myGame.setWeirdnessReputation(myGame.getWeirdnessReputation() + 1);*/
        turnReputation -= 0.5;
      }
      else if (totalScariness > 0 && totalScariness <= 10) {
        cutenessChange -= 0.05;
        scarinessChange += 0.1;
        weirdnessChange -= 0.05;
        /*myGame.setScarinessReputation(myGame.getScarinessReputation() + 2);
        myGame.setScarinessReputation(myGame.getScarinessReputation() - 1);
        myGame.setWeirdnessReputation(myGame.getWeirdnessReputation() - 1);*/
        turnReputation += 0.5;
      }
      else if (totalScariness > 10 && totalScariness <= 20) {
        cutenessChange -= 0.1;
        scarinessChange += 0/2;
        weirdnessChange -= 0.1;
        /*myGame.setScarinessReputation(myGame.getScarinessReputation() + 4);
        myGame.setScarinessReputation(myGame.getScarinessReputation() - 2);
        myGame.setWeirdnessReputation(myGame.getWeirdnessReputation() - 2);*/
        turnReputation += 1;
      }
      else {
        cutenessChange -= 0.15;
        scarinessChange += 0.3;
        weirdnessChange -= 0.15;
        /*myGame.setScarinessReputation(myGame.getScarinessReputation() + 6);
        myGame.setScarinessReputation(myGame.getScarinessReputation() - 3);
        myGame.setWeirdnessReputation(myGame.getWeirdnessReputation() - 3);*/
        turnReputation += 1.5;
      }
    }
    else {
      if (totalWeirdness <= 0) {
        cutenessChange += 0.05;
        scarinessChange += 0.05;
        weirdnessChange -= 0.1;
        /*myGame.setWeirdnessReputation(myGame.getWeirdnessReputation() - 2);
        myGame.setScarinessReputation(myGame.getScarinessReputation() + 1);
        myGame.setWeirdnessReputation(myGame.getWeirdnessReputation() + 1);*/
        turnReputation -= 0.5;
      }
      else if (totalWeirdness > 0 && totalWeirdness <= 10) {
        cutenessChange -= 0.05;
        scarinessChange -= 0.05;
        weirdnessChange += 0.1;
        /*myGame.setWeirdnessReputation(myGame.getWeirdnessReputation() + 2);
        myGame.setScarinessReputation(myGame.getScarinessReputation() - 1);
        myGame.setWeirdnessReputation(myGame.getWeirdnessReputation() - 1);*/
        turnReputation += 0.5;
      }
      else if (totalWeirdness > 10 && totalWeirdness <= 20) {
        cutenessChange -= 0.1;
        scarinessChange -= 0.1;
        weirdnessChange += 0.2;
        /*myGame.setWeirdnessReputation(myGame.getWeirdnessReputation() + 4);
        myGame.setScarinessReputation(myGame.getScarinessReputation() - 2);
        myGame.setWeirdnessReputation(myGame.getWeirdnessReputation() - 2);*/
        turnReputation += 1;
      }
      else {
        cutenessChange -= 0.15;
        scarinessChange -= 0.15;
        weirdnessChange += 0.3;
        /*myGame.setWeirdnessReputation(myGame.getWeirdnessReputation() + 6);
        myGame.setScarinessReputation(myGame.getScarinessReputation() - 3);
        myGame.setWeirdnessReputation(myGame.getWeirdnessReputation() - 3);*/
        turnReputation += 1.5;
      }
    }
  }

  double newCutenessRep = myGame.getCutenessReputation() + cutenessChange;
  double newScarinessRep = myGame.getScarinessReputation() + scarinessChange;
  double newWeirdnessRep = myGame.getWeirdnessReputation() + weirdnessChange;

  if (newCutenessRep <= 0) {
    //if (myGame.getCutenessReputation() == 0) {
      
    myGame.setScarinessReputation(myGame.getScarinessReputation()-newCutenessRep/2);//+myGame.getCutenessReputation()/2);
    myGame.setWeirdnessReputation(myGame.getWeirdnessReputation()-newCutenessRep/2);//+myGame.getCutenessReputation()/2);
    myGame.setCutenessReputation(0);
  }
  if (newScarinessRep <= 0) {
    myGame.setCutenessReputation(myGame.getCutenessReputation()-newScarinessRep/2);//myGame.getScarinessReputation()/2);
    myGame.setWeirdnessReputation(myGame.getWeirdnessReputation()-newScarinessRep/2);//+myGame.getScarinessReputation()/2);
    myGame.setScarinessReputation(0);
  }
  if (newWeirdnessRep <= 0) {
    myGame.setCutenessReputation(myGame.getCutenessReputation()-newWeirdnessRep/2);//+myGame.getWeirdnessReputation()/2);
    myGame.setScarinessReputation(myGame.getScarinessReputation()-newWeirdnessRep/2);//+myGame.getWeirdnessReputation()/2);
    myGame.setWeirdnessReputation(0);
  }
  if (newCutenessRep >= 100) {
    myGame.setScarinessReputation(0);//myGame.getScarinessReputation()-myGame.getCutenessReputation()/2);
    myGame.setWeirdnessReputation(0);//myGame.getWeirdnessReputation()-myGame.getCutenessReputation()/2);
    myGame.setCutenessReputation(100);
  }
  if (newScarinessRep >= 100) {
    myGame.setCutenessReputation(0);//myGame.getCutenessReputation()-myGame.getScarinessReputation()/2);
    myGame.setWeirdnessReputation(0);//myGame.getWeirdnessReputation()-myGame.getScarinessReputation()/2);
    myGame.setScarinessReputation(100);
  }
  if (newWeirdnessRep >= 100) {
    myGame.setCutenessReputation(0);//myGame.getCutenessReputation()-myGame.getWeirdnessReputation()/2);
    myGame.setScarinessReputation(0);//myGame.getScarinessReputation()-myGame.getWeirdnessReputation()/2);
    myGame.setWeirdnessReputation(100);
  }
  
  if (newCutenessRep > 0 && newCutenessRep < 100 &&
      newScarinessRep > 0 && newScarinessRep < 100 &&
      newWeirdnessRep > 0 && newScarinessRep < 100) {
    myGame.setCutenessReputation(newCutenessRep);
    myGame.setScarinessReputation(newScarinessRep);
    myGame.setWeirdnessReputation(newWeirdnessRep);
  }

  myGame.setReputation(0.7*myGame.getReputation() + 0.3*turnReputation);

  printf("--------------------------------------------------------------------------\n");
  std:: cout << "Effect Phase Results"
    << "\n\tMoney Spent: $" << expenses
    << "\n\tMoney Made: $" << moneyMade
    << "\n\tTotal Money: $" << myGame.getMoney()
    << "\n\tNumber of visitors: " << numVisitors
    << "\n\tAverage Interest Level: " << turnReputation
    << "\n\tOverall Reputation: " << myGame.getReputation()
    << "\n\t\tCuteness Reputation: " << myGame.getCutenessReputation()
    << "\n\t\tScariness Reputation: " << myGame.getScarinessReputation()
    << "\n\t\tWeirdness Reputation: " << myGame.getWeirdnessReputation() << "\n";
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
    BARN:
    std::cout << "Going to Barn Menu...\n";
    myBarnUI.barnUserInterface();
    if (Game::getMenuChoice() == "park") {
      Game::setMenuChoice("none");
      goto PARK;
    }
    if (Game::getMenuChoice() == "movetopark") {
      Game::setMenuChoice("none");
      myParkUI.printDisplayList();
      std::cout << "\nType the index of the display you want to put your critter in: ";
      std::string ind;
      std::cin >> ind;
      if (!checkIfStringIsInt(ind)) {
        std::cerr << "Error: Index must be an integer!\n";
      }
      int index = stoi(ind); 
      // Check for valid index
      if (index < 0){
        std::cerr << "Error: Index is less than zero!\n";
        goto BARN;
      }
      else {
        unsigned int index_us = (unsigned int) index;
        if (index_us >= (myParkUI.getPark().getDisplayList().size())) {
          std::cerr << "Error: Index is too big!\n";
        }
        else {
          if (myParkUI.getPark().addCritterToDisplay(index_us)) {
            myBarnUI.getBarn().removeCritter(Game::index);
          }
        }
      }
      goto BARN;
    }
  }
  
  // Park Menu
  else if (input == "p") {
    PARK:
    std::cout << "Going to Park Menu...\n";
    myParkUI.parkUserInterface();
    if (Game::getMenuChoice() == "barn") {
      Game::setMenuChoice("none");
      goto BARN;
    }
    if (Game::getMenuChoice() == "movetobarn") {
      Game::setMenuChoice("none");
      myBarnUI.getBarn().addCritter(Game::getTempCritter());  
      goto PARK;
    }
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
    //myGame("", "", 100, 33.3, 33.3, 33.4, 0, 10);  
    return;
  }

  // Invalid user input
  else {
    std::cerr << "Error: Invalid user input!\n";
  }

  // Recursively calls the game user interface
  gameUserInterface();

}
