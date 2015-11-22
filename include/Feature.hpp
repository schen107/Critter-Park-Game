/**************************************
 * 600.120 Intermediate Programming (Fall 2015)
 * Homework #9
 * Feature.hpp
 * Last Modified: November 9, 2015
 *
 ***** Names of Contributors:
 * Steven Chen | schen107 | schen107@jhu.edu | (302)438-0262
 * Inez Lam | ilam1 | ilam1@jhu.edu | (805)338-5461
 * Code scaffolding from: Ben Mitchell
****************************************/

#ifndef _SCHEN107_ILAM1_FEATURE_HPP
#define _SCHEN107_ILAM1_FEATURE_HPP

#define NUM_FEATURES 3
#define NUM_TRAITS 3

#define COVERING_OFFSET 0
#define EYES_OFFSET 6
#define LIMBS_OFFSET 12

#define COVERING_WIDTH 6
#define EYES_WIDTH 6
#define LIMBS_WIDTH 8

#include <iostream>
#include <string>
#include <map>
#include <cstdlib>
#include "Encoding.hpp"
#include "Trait.hpp"

class Feature {
  
  friend std::ostream & operator<< (std::ostream & os, const Feature & f);

  public:

    // Methods
    virtual std::string toString() const;
    virtual void encode(Encoding & genome);
    virtual void decode(Encoding genome);
};

std::ostream & operator<< (std::ostream & os, const Feature & c);

#endif
