/**************************************
 * 600.120 Intermediate Programming (Fall 2015)
 * Homework #11
 * Game.hpp
 * Last Modified: November 29, 2015
 *
 ***** Names of Contributors:
 * Steven Chen | schen107 | schen107@jhu.edu | (302)438-0262
 * Inez Lam | ilam1 | ilam1@jhu.edu | (805)338-5461
 * Code scaffolding from: Ben Mitchell
****************************************/

#ifndef _SCHEN107ILAM1_GAME_H
#define _SCHEN107ILAM1_GAME_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <ctype>
#include <vector>
#include <cstdio>
#include "../include/Barn.hpp"

class Game {

  public:

    // Constructor
    Game(std::string un = "", std::string pn= "", long m = 10000, int r = 0, int v = 0, int p = 10);  

    // Getters and Setters
    std::string getUsername() const;
    std::string getParkName() const;
    long getMoney() const;
    int getReputation() const;
    int getVisitors() const;
    int getPrice() const;
    void setUsername(std::string un);
    void setParkname(std::string pn);
    void setMoney(long m);
    void setReputation(int r);
    void setVisitors(int v);
    void setPrice(int p);

    // Unit Testing
    static void unitTest();

  private:
    std::string username;
    std::string parkname;
    long money;
    int reputation;
    int visitors;
    int price;

}

#endif
