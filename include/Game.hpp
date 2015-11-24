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

#ifndef _SCHEN107ILAM1_GAME_H
#define _SCHEN107ILAM1_GAME_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <cctype>
#include <vector>
#include <cstdio>
#include "../include/Barn.hpp"

class Game {

  public:

    // Constructor
    Game(std::string un = "", std::string pn= "", int m = 10000, int r = 100, int c = 33, int s = 33, int w = 34, int v = 0, int p = 10);  

    // Getters and Setters
    std::string getUserName() const;
    std::string getParkName() const;
    int getMoney() const;
    int getReputation() const;
    int getCutenessReputation() const;
    int getScarinessReputation() const;
    int getWeirdnessReputation() const;
    int getVisitors() const;
    int getPrice() const;
    void setUserName(std::string un);
    void setParkName(std::string pn);
    void setMoney(int m);
    void setReputation(int r);
    void setCutenessReputation(int c);
    void setScarinessReputation(int s);
    void setWeirdnessReputation(int w);
    void setVisitors(int v);
    void setPrice(int p);

    // Unit Testing
    static void unitTest();

  private:
    std::string userName;
    std::string parkName;
    int money;
    int reputation;
    int cutenessReputation;
    int scarinessReputation;
    int weirdnessReputation;
    int visitors;
    int price;

};

#endif
