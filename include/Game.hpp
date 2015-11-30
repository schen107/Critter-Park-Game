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
#include "../include/Critter.hpp"

class Game {

  public:

    // Constructor
    Game(std::string un = "", std::string pn= "", /*int m = 10000,*/ double r = 100, double c = 33.3, double s = 33.3, double w = 33.4, int v = 0, int p = 10);  

    // Getters and Setters
    std::string getUserName() const;
    std::string getParkName() const;
    static int getMoney();
    double getReputation() const;
    double getCutenessReputation() const;
    double getScarinessReputation() const;
    double getWeirdnessReputation() const;
    int getVisitors() const;
    int getPrice() const;
    static std::string getMenuChoice();
    static Critter getTempCritter();
    void setUserName(std::string un);
    void setParkName(std::string pn);
    static void setMoney(int m);
    void setReputation(double r);
    void setCutenessReputation(double c);
    void setScarinessReputation(double s);
    void setWeirdnessReputation(double w);
    void setVisitors(int v);
    void setPrice(int p);
    static void setMenuChoice(std::string s);
    static void setTempCritter(Critter c);

    static int index;

    // Unit Testing
    static void unitTest();

  private:
    std::string userName;
    std::string parkName;
    static int money;
    double reputation;
    double cutenessReputation;
    double scarinessReputation;
    double weirdnessReputation;
    int visitors;
    int price;
    static std::string menuChoice;
    static Critter tempCritter;

};

#endif
