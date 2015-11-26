/**************************************
 * 600.120 intermediate programming (fall 2015)
 * homework #11
 * game.hpp
 * last modified: november 29, 2015
 *
 ***** names of contributors:
 * steven chen | schen107 | schen107@jhu.edu | (302)438-0262
 * inez lam | ilam1 | ilam1@jhu.edu | (805)338-5461
 * code scaffolding from: ben mitchell
****************************************/

#ifndef _SCHEN107ILAM1_GAMEUI_H
#define _SCHEN107ILAM1_GAMEUI_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <cctype>
#include <vector>
#include <cstdio>
#include "../include/Game.hpp"
#include "../include/BarnUI.hpp"
#include "../include/ParkUI.hpp"

class GameUI {

  public:
    bool checkIfStringIsInt(std::string str);

    // Getters and Setters
    Game& getGame();
    BarnUI& getBarnUI();

    void printDecisionPhaseMenu();
    void effectPhaseDisplay();
    void gameUserInterface();

  private:
    Game myGame;
    BarnUI myBarnUI;
    ParkUI myParkUI;

};

#endif
