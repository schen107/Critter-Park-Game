/**************************************
 * 600.120 Intermediate Programming (Fall 2015)
 * Homework #9
 * Encoding.hpp
 * Last Modified: November 9, 2015
 *
 ***** Names of Contributors:
 * Steven Chen | schen107 | schen107@jhu.edu | (302)438-0262
 * Inez Lam | ilam1 | ilam1@jhu.edu | (805)338-5461
 * Code scaffolding from: Ben Mitchell
****************************************/

#ifndef _SCHEN107_ILAM1_ENCODING_HPP
#define _SCHEN107_ILAM1_ENCODING_HPP

#include <cstdlib>
#include <iostream>

typedef unsigned long encoding_t;

class Encoding {

  public:

    // Constructor
    Encoding(encoding_t d = 0);

    // Manage BitField
    void setBitField(unsigned int offset, unsigned int width, unsigned int value);
    unsigned int getBitField(unsigned int offset, unsigned int width);

    encoding_t getData() const;
    void setData(encoding_t data);

    // Mutations and Crossovers
    Encoding mutate(double mutationRate);
    Encoding crossover(const Encoding &other, double crossoverRate);
    
    // Operator overloading (for unit testing)
    bool operator== (const Encoding &other);

    // Unit Testing
    static void unitTest();

  private:
    encoding_t data;

};

#endif
