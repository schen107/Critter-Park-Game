/**************************************
 * 600.120 Intermediate Programming (Fall 2015)
 * Homework #9
 * Feature.cpp
 * Last Modified: November 9, 2015
 *
 ***** Names of Contributors:
 * Steven Chen | schen107 | schen107@jhu.edu | (302)438-0262
 * Inez Lam | ilam1 | ilam1@jhu.edu | (805)338-5461
 * Code scaffolding from: Ben Mitchell
****************************************/

#include "../include/Feature.hpp"

// Method that outputs a string containing the descriptor for the feature
std::string Feature :: toString() const {
  std::string str = "";
  return str;
}

// Genome functions
void Feature :: encode(Encoding & genome) {
  genome = genome;
}

void Feature:: decode(Encoding genome) {
  genome = genome;
}

// Output operator
std::ostream & operator<< (std::ostream & os, const Feature & f) {
  os << f.toString();
  return os;
}
