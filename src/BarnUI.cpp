/**************************************
 * 600.120 Intermediate Programming (Fall 2015)
 * Homework #9
 * BarnUI.cpp
 * Last Modified: November 9, 2015
 *
 ***** Names of Contributors:
 * Steven Chen | schen107 | schen107@jhu.edu | (302)438-0262
 * Inez Lam | ilam1 | ilam1@jhu.edu | (805)338-5461
 * Code scaffolding from: Ben Mitchell
 ****************************************/


#include "../include/BarnUI.hpp"


Barn& BarnUI :: getBarn() {
  return myBarn;
}

bool BarnUI :: checkIfStringIsInt(std::string str) {

  for (unsigned int i=0; i<str.length(); i++) {
    if (!isdigit(str[i])) {
      return false;
    }
  }
  return true;
}

// Function to print out a list of critters

void BarnUI :: printCritterList() {

  printf("--------------------------------------------------------------------------\n");
  printf("\tYour Barn:\n");

  // For empty list
  if (!myBarn.getCritterList().size()) {
    printf("You don't have any critters right now!\n");
    return;
  }

  // Print out index and name for all critters in vector
  printf("Index\t|  Name\t|  Characteristic Scores\n");
  for (unsigned int i=0; i < myBarn.getCritterList().size(); i++) {
    std::cout << i << "\t|  " 
      << myBarn.getCritterList()[i].getName() << "\t|  " 
      << myBarn.getCritterList()[i].getTrait().toString()
      << std::endl;
  }
}

/* Function to print the main menu for the user
 * Prints the menu into stdout to show program options
*/
void BarnUI :: printMenu() {

  // Print statements
  printCritterList();
  printf("--------------------------------------------------------------------------\n");
  printf("\nBarn Main Menu:\n");
  printf("\tc <name> - Buy a randomized critter called <name> and add to end of critter list\n");
  printf("\tm <index> - modify the critter at <index>\n");
  printf("\tb <index1> <index2> <name> - breed the critters at <index1> and <index2>, with the offspring named <name>\n");
  printf("\td <index> - display the description for the critter at <index>\n");
  printf("\tr <index> - sell the critter at <index>\n");
  printf("\ts - sort the critters alphabetically by their names\n");
  printf("\tt <index> - transfer critter at <index> to park");
  printf("\tp - switch to park menu\n");
  printf("\tq - quit to decision phase menu\n");
}

// Menu for modifying covering
void BarnUI :: modifyCoveringMenu(int critterNumber) {
  std::vector<Critter> tempList = myBarn.getCritterList();
  Critter& cr = tempList[critterNumber];
  printf("--------------------------------------------------------------------------\n");
  std::cout << "Your Critter has " << myBarn.getCritterList()[critterNumber].getCovering();
  std::cout << ".\nOptions:\n";
  std::cout << "\t1 <int> - Change the covering type (0) skin (1) fur (2) scales (3) feathers\n" 
    << "\t2 <int> - Change the covering color: (0) red (1) blue (2) gray (3) yellow\n" 
    << "\t3 <int> - Change the covering texture: (0) smooth (1) rough (2) grainy (3) soft\n" 
    << "\t4 - Quit modifying covering feature\n"
    << "Enter the attribute you want to modify and the number you want to modify to: ";

  std::string is;
  std::string js;
  int i;
  int j;

  std::cin >> is;
  if (!checkIfStringIsInt(is)) {
    std::cerr << "Error: Indices must be integers!\n";
    modifyCoveringMenu(critterNumber);
    return;
  }
  // if not quitting
  if (is != "4") {
    std::cin >> js;
    if (!checkIfStringIsInt(js)) {
      std::cerr << "Error: Indices must be integers!\n";
      modifyCoveringMenu(critterNumber);
      return;
    }
    j = stoi(js);
  }

  i = stoi(is);
  switch (i) {
    case 1:
      {
        cr.setCovering(cr.getCovering().setType(j));
        cr.setTrait(cr.getCovering().getTrait(),cr.getEyes().getTrait(),cr.getLimbs().getTrait());
        myBarn.setCritterList(tempList);
        break;
      }
    case 2:
      {
        cr.setCovering(cr.getCovering().setColor(j));
        cr.setTrait(cr.getCovering().getTrait(),cr.getEyes().getTrait(),cr.getLimbs().getTrait());
        myBarn.setCritterList(tempList);
        break;
      }
    case 3:
      {
        cr.setCovering(cr.getCovering().setTexture(j));
        cr.setTrait(cr.getCovering().getTrait(),cr.getEyes().getTrait(),cr.getLimbs().getTrait());
        myBarn.setCritterList(tempList);
        break;
      }
    case 4:
      {
        std::cout << "Quitting modify covering feature menu!\n";
        return;
      }
    default:
      {
        std::cerr << "Error: First input must be between 1-4!\n";
        modifyCoveringMenu(critterNumber);
        return;
      }
  }

  modifyCoveringMenu(critterNumber);

}


// Menu for modifying eyes
void BarnUI :: modifyEyesMenu(int critterNumber) {
  std::vector<Critter> tempList = myBarn.getCritterList();
  Critter& cr = tempList[critterNumber];
  printf("--------------------------------------------------------------------------\n");
  std::cout << "Your Critter has " << myBarn.getCritterList()[critterNumber].getEyes();
  std::cout << ".\nOptions:\n";
  std::cout << "\t1 <int> - Change the number of pairs of eyes (must be between 1 and 4)\n" 
    << "\t2 <int> - Change the eye type: (0) round (1) compound (2) narrow (3) piercing\n" 
    << "\t3 <int> - Change the eye color: (0) magenta (1) teal (2) green (3) orange\n" 
    << "\t4 - Quit modifying eye feature\n"
    << "Enter the attribute you want to modify and the number you want to modify to: ";

  std::string is;
  std::string js;
  int i;
  int j;

  std::cin >> is;
  if (!checkIfStringIsInt(is)) {
    std::cerr << "Error: Indices must be integers!\n";
    modifyEyesMenu(critterNumber);
    return;
  }
  // if not quitting
  if (is != "4") {
    std::cin >> js;
    if (!checkIfStringIsInt(js)) {
      std::cerr << "Error: Indices must be integers!\n";
      modifyEyesMenu(critterNumber);
      return;
    }
    j = stoi(js);
  }

  i = stoi(is);
  switch (i) {
    case 1:
      {
        cr.setEyes(cr.getEyes().setPairNumber(j));
        cr.setTrait(cr.getCovering().getTrait(),cr.getEyes().getTrait(),cr.getLimbs().getTrait());
        myBarn.setCritterList(tempList);
        break;
      }

    case 2:
      {
        cr.setEyes(cr.getEyes().setType(j));
        cr.setTrait(cr.getCovering().getTrait(),cr.getEyes().getTrait(),cr.getLimbs().getTrait());
        myBarn.setCritterList(tempList);
        break;
      }
    case 3:
      {
        cr.setEyes(cr.getEyes().setColor(j));
        cr.setTrait(cr.getCovering().getTrait(),cr.getEyes().getTrait(),cr.getLimbs().getTrait());
        myBarn.setCritterList(tempList);
        break;
      }
    case 4:
      {
        std::cout << "Quitting modify eyes feature menu!\n";
        return;
      }
    default:
      {
        std::cerr << "Error: First input must be between 1-3!\n";
        modifyEyesMenu(critterNumber);
        return;
      }
  }

  modifyEyesMenu(critterNumber);

}

// Menu for modifying limbs
void BarnUI :: modifyLimbsMenu(int critterNumber) {
  std::vector<Critter> tempList = myBarn.getCritterList();
  Critter& cr = tempList[critterNumber];
  printf("--------------------------------------------------------------------------\n");
  std::cout << "Your Critter has " << myBarn.getCritterList()[critterNumber].getLimbs();
  std::cout << ".\nOptions:\n";
  std::cout << "\t1 <int> - Change the number of pairs of limbs (must be between 1 and 4)\n" 
    << "\t2 <int> - Change the limb type: (0) legs (1) fins (2) wings (3) tentacles\n" 
    << "\t3 <int> - Change the limb length: (0) stubby (1) short (2) long (3) gangly\n" 
    << "\t4 <int> - Change the limb thickness: (0) spindly (1) thin (2) round (3) thick\n"
    << "\t5 - Quit modifying limb feature\n"
    << "Enter the attribute you want to modify and the number you want to modify to: ";
  std::string is;
  std::string js;
  int i;
  int j;

  std::cin >> is;
  if (!checkIfStringIsInt(is)) {
    std::cerr << "Error: Indices must be integers!\n";
    modifyLimbsMenu(critterNumber);
    return;
  }
  // if not quitting
  if (is != "5") {
    std::cin >> js;
    if (!checkIfStringIsInt(js)) {
      std::cerr << "Error: Indices must be integers!\n";
      modifyLimbsMenu(critterNumber);
      return;
    }
    j = stoi(js);
  }

  i = stoi(is);
  switch (i) {
    case 1:
      {
        cr.setLimbs(cr.getLimbs().setPairNumber(j));
        cr.setTrait(cr.getCovering().getTrait(),cr.getEyes().getTrait(),cr.getLimbs().getTrait());
        myBarn.setCritterList(tempList);
        break;
      }
    case 2:
      {
        cr.setLimbs(cr.getLimbs().setType(j));
        cr.setTrait(cr.getCovering().getTrait(),cr.getEyes().getTrait(),cr.getLimbs().getTrait());
        myBarn.setCritterList(tempList);
        break;
      }
    case 3:
      {
        cr.setLimbs(cr.getLimbs().setLength(j));
        cr.setTrait(cr.getCovering().getTrait(),cr.getEyes().getTrait(),cr.getLimbs().getTrait());
        myBarn.setCritterList(tempList);
        break;
      }
    case 4:
      {
        cr.setLimbs(cr.getLimbs().setThickness(j));
        cr.setTrait(cr.getCovering().getTrait(),cr.getEyes().getTrait(),cr.getLimbs().getTrait());
        myBarn.setCritterList(tempList);
        break;
      }
    case 5:
      {
        std::cout << "Quitting modify limb feature menu!\n";
        return;
      }
    default:
      {
        std::cerr << "Error: First input must be between 1-5!\n";
        modifyLimbsMenu(critterNumber);
        return;
      }
  }

  modifyLimbsMenu(critterNumber);

}

// Menu for modifying critters
void BarnUI :: modifyCritterMenu(int critterNumber) {

  printf("--------------------------------------------------------------------------\n");
  std::cout << myBarn.getCritterList()[critterNumber];
  printf("\nModify Your Critter's...\n");
  printf("\t(1) Name\n\t(2) Covering \n\t(3) Eyes\n\t(4) Limbs\n\t(5) Quit\n");
  printf("Enter the index of the feature you want to modify (Be careful!): ");

  std::string ind;
  std::cin >> ind;
  printf("--------------------------------------------------------------------------\n");

  if (!checkIfStringIsInt(ind)) {
    std::cerr << "Error: Index must be an integer!\n";
    modifyCritterMenu(critterNumber);
    return;
  }

  int index = stoi(ind);
  switch(index) {          
    case 1: 
      {
        std::cout << "Your critter named \"" 
          << myBarn.getCritterList()[critterNumber].getName() <<  "\" will be modified.\n";
        std::cout << "Please enter the new name: ";
        std::string newName;
        std::cin >> newName;
        myBarn.getCritterList()[critterNumber].setName(newName);
        break;
      }
    case 2: 
      {
        std::cout << "Your critter named \"" 
          << myBarn.getCritterList()[critterNumber].getName() <<  "\" will be modified.\n";
        modifyCoveringMenu(critterNumber);
        break;
      }
    case 3:
      {
        std::cout << "Your critter named \"" 
          << myBarn.getCritterList()[critterNumber].getName() <<  "\" will be modified.\n";
        modifyEyesMenu(critterNumber);
        break;
      }
    case 4: 
      {
        std::cout << "Your critter named \"" 
          << myBarn.getCritterList()[critterNumber].getName() <<  "\" will be modified.\n";
        modifyLimbsMenu(critterNumber);
        break;
      }
    case 5: 
      {
        printf("Quitting the modify critter menu!\n");
        return;
      }
    default: 
      {
        std::cerr << "Error: Please choose an index between 1 and 5!\n";
        modifyCritterMenu(critterNumber);
        return;
      }
  }

  modifyCritterMenu(critterNumber);

}


// Main Menu
void BarnUI :: barnUserInterface() {
  std::string input;

  // Print menu and get user input
  printMenu();
  printf("Enter choice: ");
  std::cin >> input;

  // Check for valid user input and runs the proper function

  // Buy Critter
  if (input == "c") {
    srand(time(NULL));
    std::string name;
    std::cin >> name;
    std::cout << "Creating critter named " << name << "...\n";
    Critter temp(name);
    std::vector<Critter> tempList;
    tempList = myBarn.getCritterList();
    tempList.push_back(temp);
    myBarn.setCritterList(tempList);
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
