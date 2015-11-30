/**************************************
 * 600.120 Intermediate Programming (Fall 2015)
 * Homework #11
 * Park.hpp
 * Last Modified: November 29, 2015
 *
 ***** Names of Contributors:
 * Steven Chen | schen107 | schen107@jhu.edu | (302)438-0262
 * Inez Lam | ilam1 | ilam1@jhu.edu | (805)338-5461
 * Code scaffolding from: Ben Mitchell
****************************************/

#ifndef _SCHEN107ILAM1_PARK_H
#define _SCHEN107ILAM1_PARK_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "../include/Display.hpp"
#include "../include/Critter.hpp"
#include "../include/Game.hpp"

class Park {
  public:

    // Constructor
    inline Park() {
      Display temp1("Display1");
      Display temp2("Display2");
      Display temp3("Display3");
      displayList.push_back(temp1);
      displayList.push_back(temp2);
      displayList.push_back(temp3);
    }

    // Getters and Setters
    std::vector<Display> getDisplayList();
    void setDisplayList(std::vector<Display> list);
   
    // Add Critter to a display
    bool addCritterToDisplay(unsigned int displayNumber);

    // Remove critter from a display
    void removeCritterFromDisplay(unsigned int displayNumber, unsigned int critterNumber);

    // Remove displays from vector
    void removeDisplay(unsigned int displayNumber);
    
    // Sorting displays
    static bool compareDisplays(Display &d1, const Display &d2);
    void sortDisplays();

    // Unit Testing
    static void unitTest();

  protected:
    std::vector<Display> displayList;
};

#endif
