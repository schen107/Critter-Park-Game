/**************************************
 * 600.120 Intermediate Programming (Fall 2015)
 * Homework #11
 * ParkUI.hpp
 * Last Modified: November 29, 2015
 *
 ***** Names of Contributors:
 * Steven Chen | schen107 | schen107@jhu.edu | (302)438-0262
 * Inez Lam | ilam1 | ilam1@jhu.edu | (805)338-5461
 * Code scaffolding from: Ben Mitchell
****************************************/

#ifndef _SCHEN107ILAM1_PARKUI_H
#define _SCHEN107ILAM1_PARKUI_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <cctype>
#include <vector>
#include <ctime>
#include <cstdio>
#include "../include/Display.hpp"
#include "../include/Park.hpp"
#include "../include/Game.hpp"

class ParkUI {

  public:
   
    //ParkUI (Game& gr);
    
    // Getter
    Park& getPark();

    // Checks if a string is a positive integer
    bool checkIfStringIsInt(std::string str);
   
    // Print list of displays
    void printDisplayList();

    // Prints the main menu
    void printMenu();

    // Gets user input for menu options
    void parkUserInterface();

  private: 
    Park myPark;
    //G
    //ame& myGamer;
};

#endif
