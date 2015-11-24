/**************************************
 * 600.120 Intermediate Programming (Fall 2015)
 * Homework #9
 * Barn.hpp
 * Last Modified: November 9, 2015
 *
 ***** Names of Contributors:
 * Steven Chen | schen107 | schen107@jhu.edu | (302)438-0262
 * Inez Lam | ilam1 | ilam1@jhu.edu | (805)338-5461
 * Code scaffolding from: Ben Mitchell
****************************************/

#ifndef _SCHEN107ILAM1_BARN_H
#define _SCHEN107ILAM1_BARN_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <cctype>
#include <vector>
#include <ctime>
#include <cstdio>
#include <algorithm>
#include "../include/Critter.hpp"

class Barn {
  public:

    // Constructor
    inline Barn() {
      Critter temp1("Critter1");
      Critter temp2("Critter2");
      Critter temp3("Critter3");
      critterList.push_back(temp1);
      critterList.push_back(temp2);
      critterList.push_back(temp3);
    }

    // Getters and Setters
    std::vector<Critter> getCritterList();
    void setCritterList(std::vector<Critter> list);
    
    // Remove critter from vector
    void removeCritter(unsigned int critterNumber);
    
    // Sorting critters
    static bool compareCritters(Critter &c1, const Critter &c2);
    void sortCritters();

    // Unit Testing
    static void unitTest();

  private:
    std::vector<Critter> critterList;

};

#endif
