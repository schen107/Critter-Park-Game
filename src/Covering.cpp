/**************************************
 * 600.120 Intermediate Programming (Fall 2015)
 * Homework #9
 * Covering.cpp
 * Last Modified: November 9, 2015
 *
 ***** Names of Contributors:
 * Steven Chen | schen107 | schen107@jhu.edu | (302)438-0262
 * Inez Lam | ilam1 | ilam1@jhu.edu | (805)338-5461
 * Code scaffolding from: Ben Mitchell
****************************************/
#include "../include/Covering.hpp"

std::map<int, Trait> Covering :: typeMap;
std::map<int, Trait> Covering :: colorMap;
std::map<int, Trait> Covering :: textureMap;

Covering :: Covering(unsigned int ty, unsigned int c, unsigned int te)
  : type(ty), color(c), texture(te)
{
  // Covering trait maps (define once)
  if (typeMap.empty()) {
    Trait ty1("skin",0,0,-1);
    Trait ty2("fur",3,-2,0);
    Trait ty3("scales",-3,3,2);
    Trait ty4("feathers",2,0,1);
    typeMap = {{0,ty1},{1,ty2},{2,ty3},{3,ty4}};

    Trait c1("red",1,0,3);
    Trait c2("blue",0,1,2);
    Trait c3("gray",-1,2,2);
    Trait c4("yellow",2,-1,-1);
    colorMap = {{0,c1},{1,c2},{2,c3},{3,c4}};

    Trait te1("smooth",1,-1,1);
    Trait te2("rough",-1,2,2);
    Trait te3("grainy",-2,3,2);
    Trait te4("soft",3,-2,0);
    textureMap = {{0,te1},{1,te2},{2,te3},{3,te4}};
  }
  
  coverTrait = typeMap[type] + colorMap[color] + textureMap[texture];

}

// Getters and Setters
unsigned int Covering :: getType() const {
  return type;
}
unsigned int Covering :: getColor() const {
  return color;
}
unsigned int Covering :: getTexture() const {
  return texture;
}
Trait Covering :: getTrait() const {
  return coverTrait;
}
Covering Covering :: setType(unsigned int t) {
  this->type = t;
  this->coverTrait = typeMap[type] + colorMap[color] + textureMap[texture];
  return *this;
}
Covering Covering :: setColor(unsigned int c) {
  this->color = c;
  this->coverTrait = typeMap[type] + colorMap[color] + textureMap[texture];
  return *this;
}
Covering Covering :: setTexture(unsigned int te) {
  this->texture = te;
  this->coverTrait = typeMap[type] + colorMap[color] + textureMap[texture];
  return *this;
}

// Print covering description
std::string Covering :: toString () const {
  std::string str;
  
  str += textureMap[texture].getDescriptor() + ", ";
  str += colorMap[color].getDescriptor() + " ";
  str += typeMap[type].getDescriptor();

  return str;
}

// Encode limb attributes into binary string
void Covering :: encode(Encoding& genome) {

  genome.setBitField(COVERING_OFFSET, 2, this->type);
  genome.setBitField(COVERING_OFFSET + 2, 2, this->color);
  genome.setBitField(COVERING_OFFSET + 4, 2, this->texture);
}

// Decode limb attributes from binary string
void Covering :: decode(Encoding genome) {
  
  type = genome.getBitField(COVERING_OFFSET,2);
  color = genome.getBitField(COVERING_OFFSET + 2,2);
  texture = genome.getBitField(COVERING_OFFSET + 4,2);
  coverTrait = typeMap[type] + colorMap[color] + textureMap[texture];
}

// Operator overloading (for unit testing)
bool Covering :: operator== (const Covering &other) {
  return (type == other.getType() && color == other.getColor() && texture == other.getTexture());
}

// Unit Testing
void Covering :: unitTest() {
  std::cout << "Starting unit tests for Covering...\n";

  Covering c;

  int passedTests = 0;

  c.setType(2);
  if (c.getType() == 2) {
    passedTests++;
  }
  c.setColor(2);
  if (c.getColor() == 2) {
    passedTests++;
  }
  c.setTexture(2);
  if (c.getTexture() == 2) {
    passedTests++;
  }

  Covering temp;
  
  c.setType(temp.getType());
  if (c.getType() == temp.getType()) {
    passedTests++;
  }
  c.setColor(temp.getColor());
  if (c.getColor() == temp.getColor()) {
    passedTests++;
  }
  c.setTexture(temp.getTexture());
  if (c.getTexture() == temp.getTexture()) {
    passedTests++;
  }
  
  std::cout << "Done with unit tests for Covering. # of tests passed: " << passedTests << " out of 6.\n";
}



