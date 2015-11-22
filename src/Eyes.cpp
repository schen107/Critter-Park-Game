/**************************************
 * 600.120 Intermediate Programming (Fall 2015)
 * Homework #9
 * Eyes.cpp
 * Last Modified: November 9, 2015
 *
 ***** Names of Contributors:
 * Steven Chen | schen107 | schen107@jhu.edu | (302)438-0262
 * Inez Lam | ilam1 | ilam1@jhu.edu | (805)338-5461
 * Code scaffolding from: Ben Mitchell
****************************************/
#include "../include/Eyes.hpp"

std::map<int, Trait> Eyes :: typeMap;
std::map<int, Trait> Eyes :: colorMap;

Eyes :: Eyes(unsigned int p, unsigned int t, unsigned int c)
  : pairs(p), type(t), color(c)
{
  // Eye trait maps (define once)
  if (typeMap.empty()) {
    Trait t1("round",3,-2,0);
    Trait t2("compound",-3,3,3);
    Trait t3("narrow",-1,2,1);
    Trait t4("piercing",-1,3,1);
    typeMap = {{0,t1},{1,t2},{2,t3},{3,t4}};

    Trait c1("magenta",2,-1,1);
    Trait c2("teal",0,1,2);
    Trait c3("green",-1,2,2);
    Trait c4("orange",1,0,2);
    colorMap = {{0,c1},{1,c2},{2,c3},{3,c4}};
  }
    
  eyeTrait = typeMap[type] + colorMap[color];
}

// Getters and Setters
unsigned int Eyes :: getPairNumber() const {
  return pairs;
}
unsigned int Eyes :: getType() const {
  return type;
}
unsigned int Eyes :: getColor() const {
  return color;
}
Trait Eyes :: getTrait() const {
  return eyeTrait;
}
Eyes Eyes :: setPairNumber(unsigned int p) {
  this->pairs = p;
  return *this;
}
Eyes Eyes :: setType(unsigned int t) {
  this->type = t;
  this->eyeTrait = typeMap[type] + colorMap[color];
  return *this;
}
Eyes Eyes :: setColor(unsigned int c) {
  this->color = c;
  this->eyeTrait = typeMap[type] + colorMap[color];
  return *this;
}


// Make string containing covering description
std::string Eyes :: toString () const {
  std::string str;

  str += std::to_string(pairs*2) + " ";
  str += colorMap[color].getDescriptor() + ", ";
  str += typeMap[type].getDescriptor() + " eyes";

  return str;
}

// Encode eye attributes into binary string
void Eyes:: encode(Encoding& genome) {

  genome.setBitField(EYES_OFFSET, 2, this->pairs - 1);
  genome.setBitField(EYES_OFFSET + 2, 2, this->type);
  genome.setBitField(EYES_OFFSET + 4, 2, this->color);
}

// Decode eye attributes from binary string
void Eyes :: decode(Encoding genome) {

  pairs = genome.getBitField(EYES_OFFSET,2) + 1;
  type = genome.getBitField(EYES_OFFSET + 2,2);
  color = genome.getBitField(EYES_OFFSET + 4,2);
  eyeTrait = typeMap[type] + colorMap[color];
}

// Operator overloading (for unit testing)
bool Eyes :: operator== (const Eyes &other) {
  return (pairs == other.getPairNumber() && type == other.getType() && color == other.getColor());
}

// Unit Testing
void Eyes :: unitTest() {
  std::cout << "Starting unit tests for Eyes...\n";

  Eyes e;

  int passedTests = 0;
  
  e.setPairNumber(2);
  if (e.getPairNumber() == 2) {
    passedTests++;
  }
  e.setType(2);
  if (e.getType() == 2) {
    passedTests++;
  }
  e.setColor(2);
  if (e.getColor() == 2) {
    passedTests++;
  }

  Eyes temp;
  
  e.setPairNumber(temp.getPairNumber());
  if (e.getPairNumber() == temp.getPairNumber()) {
    passedTests++;
  }
  e.setType(temp.getType());
  if (e.getType() == temp.getType()) {
    passedTests++;
  }
  e.setColor(temp.getColor());
  if (e.getColor() == temp.getColor()) {
    passedTests++;
  }
  
  std::cout << "Done with unit tests for Eyes. # of tests passed: " << passedTests << " out of 6.\n";

}



