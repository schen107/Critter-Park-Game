/**************************************
 * 600.120 Intermediate Programming (Fall 2015)
 * Homework #9
 * BarnUI.hpp
 * Last Modified: November 9, 2015
 *
 ***** Names of Contributors:
 * Steven Chen | schen107 | schen107@jhu.edu | (302)438-0262
 * Inez Lam | ilam1 | ilam1@jhu.edu | (805)338-5461
 * Code scaffolding from: Ben Mitchell
****************************************/

#ifndef _SCHEN107ILAM1_BARNUI_H
#define _SCHEN107ILAM1_BARNUI_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <cctype>
#include <vector>
#include <ctime>
#include <cstdio>
#include "../include/Critter.hpp"
#include "../include/Barn.hpp"
#include "../include/Game.hpp"

class BarnUI {

  public:
    
    // Getter
    Barn& getBarn();

    // Checks if a string is a positive integer
    bool checkIfStringIsInt(std::string str);
   
    // Print list of critters
    void printCritterList();

    // Prints the main menu
    void printMenu();

    // Modify Menus
    void modifyCoveringMenu(int critterNumber);
    void modifyEyesMenu(int critterNumber);
    void modifyLimbsMenu(int critterNumber);
    void modifyCritterMenu(int critterNumber);

    // Gets user input for menu options
    void barnUserInterface();

  private: 
    Barn myBarn;
};

#endif
