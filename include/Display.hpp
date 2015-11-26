/**************************************
 * 600.120 Intermediate Programming (Fall 2015)
 * Homework #11
 * Display.hpp
 * Last Modified: November 29, 2015
 *
 ***** Names of Contributors:
 * Steven Chen | schen107 | schen107@jhu.edu | (302)438-0262
 * Inez Lam | ilam1 | ilam1@jhu.edu | (805)338-5461
 * Code scaffolding from: Ben Mitchell
****************************************/

#ifndef _SCHEN107ILAM1_DISPLAY_HPP
#define _SCHEN107ILAM1_DISPLAY_HPP

#include <iostream>
#include <vector>
#include "Critter.hpp"

// Display class - note, ALL DISPLAYS MUST HAVE A CRITTER AT THE MOMENT, i.e. no empty displays

class Display {

  friend std::ostream & operator<< (std::ostream & os, const Display& d);

  public:

    // Constructors
    Display(std::string n = "");
    
    // Getters and Setters
    std::string getName() const;
    Critter getCritter() const;
    void setName(std::string name);
    void setCritter(Critter c);

    // Description of Display
    std::string toString() const;
    
    // Display Operators
    void operator= (const Display &other);
    bool operator== (const Display &other);
    bool operator< (const Display &other);
    bool operator> (const Display &other);

    // Unit Test
    static void unitTest();

  private:
    // Member variables
    std::string name;
    Critter critter;
};

std::ostream & operator<< (std::ostream & os, const Display & c); 

#endif
