/**************************************
 * 600.120 Intermediate Programming (Fall 2015)
 * Homework #11
 * CritterParkUI.hpp
 * Last Modified: November 29, 2015
 *
 ***** Names of Contributors:
 * Steven Chen | schen107 | schen107@jhu.edu | (302)438-0262
 * Inez Lam | ilam1 | ilam1@jhu.edu | (805)338-5461
 * Code scaffolding from: Ben Mitchell
****************************************/

#ifndef _SCHEN107ILAM1_CRITTERPARKUI_H
#define _SCHEN107ILAM1_CRITTERPARKUI_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <cctype>
#include <vector>
#include <cstdio>
#include "../include/GameUI.hpp"

class CritterParkUI {

  public:
    void mainMenu();
    void critterParkUserInterface();

  private:
    GameUI myGameUI;
    //std::vector<Game> myGames;

};

#endif
