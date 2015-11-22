/**************************************
 * 600.120 Intermediate Programming (Fall 2015)
 * Homework #9
 * Limbs.cpp
 * Last Modified: November 9, 2015
 *
 ***** Names of Contributors:
 * Steven Chen | schen107 | schen107@jhu.edu | (302)438-0262
 * Inez Lam | ilam1 | ilam1@jhu.edu | (805)338-5461
 * Code scaffolding from: Ben Mitchell
****************************************/
#include "../include/Limbs.hpp"

std::map<int, Trait> Limbs :: typeMap;
std::map<int, Trait> Limbs :: lengthMap;
std::map<int, Trait> Limbs :: thicknessMap;

Limbs :: Limbs(unsigned int p, unsigned int ty, unsigned int l, unsigned int th)
  : pairs(p), type(ty), length(l), thickness(th)
{
  // Limb trait maps (define once)
  if (typeMap.empty()) {
    Trait ty1("legs",0,0,-1);
    Trait ty2("fins",0,2,1);
    Trait ty3("wings",1,0,1);
    Trait ty4("tentacles",-3,2,3);
    typeMap = {{0,ty1},{1,ty2},{2,ty3},{3,ty4}};

    Trait l1("stubby",2,0,1);
    Trait l2("short",1,-1,0);
    Trait l3("long",0,1,1);
    Trait l4("gangly",-1,2,2);
    lengthMap = {{0,l1},{1,l2},{2,l3},{3,l4}};

    Trait th1("spindly",-1,3,2);
    Trait th2("thin",0,-1,0);
    Trait th3("round",2,0,1);
    Trait th4("thick",1,1,0);
    thicknessMap = {{0,th1},{1,th2},{2,th3},{3,th4}};
  }
  
  limbTrait = typeMap[type] + lengthMap[length] + thicknessMap[thickness];

}

// Getters and Setters
unsigned int Limbs :: getPairNumber() const {
  return pairs;
}
unsigned int Limbs :: getType() const {
  return type;
}
unsigned int Limbs :: getLength() const {
  return length;
}
unsigned int Limbs :: getThickness() const {
  return thickness;
}
Trait Limbs :: getTrait() const {
  return limbTrait;
}
Limbs Limbs :: setPairNumber(unsigned int p) {
  this->pairs = p;
  return *this;
}
Limbs Limbs :: setType(unsigned int t) {
  this->type = t;
  this->limbTrait = typeMap[type] + lengthMap[length] + thicknessMap[thickness];
  std::cout << limbTrait.toString() << std::endl;
  return *this;
}
Limbs Limbs :: setLength(unsigned int l) {
  this->length = l;
  this->limbTrait = typeMap[type] + lengthMap[length] + thicknessMap[thickness];
  return *this;
}
Limbs Limbs :: setThickness(unsigned int th) {
  this->thickness = th;
  this->limbTrait = typeMap[type] + lengthMap[length] + thicknessMap[thickness];
  return *this;
}

// Make string containing limb description
std::string Limbs :: toString () const {
  std::string str;
  
  str += std::to_string(pairs*2) + " "; 
  str += lengthMap[length].getDescriptor() + ", ";
  str += thicknessMap[thickness].getDescriptor() + " ";
  str += typeMap[type].getDescriptor();

  return str;
}


// Encode limb attributes into binary string
void Limbs :: encode(Encoding& genome) {

  genome.setBitField(LIMBS_OFFSET, 2, this->pairs - 1);
  genome.setBitField(LIMBS_OFFSET + 2, 2, this->type);
  genome.setBitField(LIMBS_OFFSET + 4, 2, this->length);
  genome.setBitField(LIMBS_OFFSET + 6, 2, this->thickness);
}

// Decode limb attributes from binary string
void Limbs :: decode(Encoding genome) {
  
  pairs = genome.getBitField(LIMBS_OFFSET,2) + 1;
  type = genome.getBitField(LIMBS_OFFSET + 2,2);
  length = genome.getBitField(LIMBS_OFFSET + 4,2);
  thickness = genome.getBitField(LIMBS_OFFSET + 6,2);
  limbTrait = typeMap[type] + lengthMap[length] + thicknessMap[thickness];
}

// Operator overloading (for unit testing)
bool Limbs :: operator== (const Limbs &other) {
  return (pairs == other.getPairNumber() && type == other.getType() && length == other.getLength() && thickness == other.getThickness());
}

// Unit Testing
void Limbs :: unitTest() {
  std::cout << "Starting unit tests for Limbs...\n";

  Limbs l;

  int passedTests = 0;
  
  l.setPairNumber(2);
  if (l.getPairNumber() == 2) {
    passedTests++;
  }
  l.setType(2);
  if (l.getType() == 2) {
    passedTests++;
  }
  l.setLength(2);
  if (l.getLength() == 2) {
    passedTests++;
  }
  l.setThickness(2);
  if (l.getThickness() == 2) {
    passedTests++;
  }

  Limbs temp;
  
  l.setPairNumber(temp.getPairNumber());
  if (l.getPairNumber() == temp.getPairNumber()) {
    passedTests++;
  }
  l.setType(temp.getType());
  if (l.getType() == temp.getType()) {
    passedTests++;
  }
  l.setLength(temp.getLength());
  if (l.getLength() == temp.getLength()) {
    passedTests++;
  }
  l.setThickness(temp.getThickness());
  if (l.getThickness() == temp.getThickness()) {
    passedTests++;
  }
  
    std::cout << "Done with unit tests for Limbs. # of tests passed: " << passedTests << " out of 8.\n";

}

