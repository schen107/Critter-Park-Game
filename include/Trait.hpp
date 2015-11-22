/**************************************
 * 600.120 Intermediate Programming (Fall 2015)
 * Homework #9
 * Trait.hpp
 * Last Modified: November 9, 2015
 *
 ***** Names of Contributors:
 * Steven Chen | schen107 | schen107@jhu.edu | (302)438-0262
 * Inez Lam | ilam1 | ilam1@jhu.edu | (805)338-5461
 * Code scaffolding from: Ben Mitchell
****************************************/

#ifndef _SCHEN107_ILAM1_TRAIT_HPP
#define _SCHEN107_ILAM1_TRAIT_HPP

#include <iostream>
#include <string>
#include <map>

class Trait {

    public:
    
    // Constructors
    Trait(std::string d = "", int c = 0, int s = 0, int w = 0);

    // getters and setters
    std::string getDescriptor() const;
    int getCuteness() const;
    int getScariness() const;
    int getWeirdness() const;
    void setDescriptor(std::string d);
    void setCuteness(int c);
    void setScariness(int s);
    void setWeirdness(int w);

    // To String function
    std::string toString() const;

    // Unit Testing
    static void unitTest();
    
    // Trait operators
    Trait operator+ (const Trait &y);
    Trait& operator+= (const Trait &y);

  protected:
    std::string descriptor;
    int cuteness;
    int scariness;
    int weirdness;
    
    
};

#endif
