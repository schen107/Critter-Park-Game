/**************************************
 * 600.120 Intermediate Programming (Fall 2015)
 * Homework #9
 * Critter.cpp
 * Last Modified: November 9, 2015
 *
 ***** Names of Contributors:
 * Steven Chen | schen107 | schen107@jhu.edu | (302)438-0262
 * Inez Lam | ilam1 | ilam1@jhu.edu | (805)338-5461
 * Code scaffolding from: Ben Mitchell
****************************************/

#include "../include/Critter.hpp"

// Constructor
Critter :: Critter (std::string n) : name(n)
{
  cr.encode(gr);
  er.encode(gr);
  lr.encode(gr);
  featureList.push_back(cr);
  featureList.push_back(er);
  featureList.push_back(lr);
  critterTrait = eye.getTrait() + cover.getTrait() + limb.getTrait();
}

// Getters and Setters
std::string Critter :: getName() const {
  return name;
}

Covering Critter :: getCovering() const {
  return cover;
}

Eyes Critter :: getEyes() const {
  return eye;
}

Limbs Critter :: getLimbs() const {
  return limb;
}

Encoding Critter :: getGenome() const {
  return genome;
}

Trait Critter :: getTrait() const {
  return critterTrait;
}

void Critter::setName(std::string name) {
  this->name = name;
}
    
void Critter :: setCovering(Covering cover) {
  this->cover = cover;
}

void Critter :: setEyes(Eyes eye) {
  this->eye = eye;
}

void Critter :: setLimbs(Limbs limb) {
  this->limb = limb;
}

void Critter :: setGenome(Encoding genome) {
  this->genome = genome;
}
    
void Critter :: setTrait(Trait trait1, Trait trait2, Trait trait3) {
  this->critterTrait = trait1 + trait2 + trait3;
}

// Breed Critter
Critter Critter :: breedCritter(const Critter p, std::string name) {
  Critter offspring(name);
  const Encoding &pr = p.getGenome();
  offspring.setGenome(getGenome().crossover(pr,CROSS_RATE).mutate(MUT_RATE));
  offspring.cover.decode(offspring.getGenome());
  offspring.eye.decode(offspring.getGenome());
  offspring.limb.decode(offspring.getGenome());
  offspring.critterTrait = offspring.eye.getTrait() + offspring.cover.getTrait() + offspring.limb.getTrait();
  return offspring;
}

// Make string containing description of Critter
std::string Critter :: toString() const {
  std::string str;

  str += "Critter: \"" + name + 
  str += "\" is covered in " + cover.toString();
  str += ".\n\t It has " + eye.toString();
  str += " and " + limb.toString() + ".\n";
  str += "\t " + critterTrait.toString() + "\n";
  return str;
}

// Operators
void Critter :: operator= (const Critter &other) {
  name = other.name;
  eye = other.getEyes();
  cover = other.getCovering();
  limb = other.getLimbs();
  er = eye;
  cr = cover;
  lr = limb;
  genome = other.getGenome();
  gr = genome;
  cr.encode(gr);
  er.encode(gr);
  lr.encode(gr);
  featureList.empty();
  featureList.push_back(cr);
  featureList.push_back(er);
  featureList.push_back(lr);
  critterTrait = eye.getTrait() + cover.getTrait() + limb.getTrait();
}

bool Critter :: operator== (const Critter &other) {
  return name == other.name;
}

bool Critter :: operator< (const Critter &other) {
  return name < other.name;
}

bool Critter :: operator> (const Critter &other) {
  return name > other.name;
}

// Unit Test
void Critter :: unitTest() {
  std::cout << "Starting unit tests for Critter...\n";

  int passedTests = 0;

  Critter c("John");

  if (c.getName() == "John") {
    passedTests++;
  }

  c.setName("Ben");
  if (c.getName() == "Ben") {
    passedTests++;
  }

  Critter temp;
  c.setCovering(temp.getCovering());
  if (c.getCovering() == temp.getCovering()) {
    passedTests++;
  }
  c.setEyes(temp.getEyes());
  if (c.getEyes() == temp.getEyes()) {
    passedTests++;
  }
  c.setLimbs(temp.getLimbs());
  if (c.getLimbs() == temp.getLimbs()) {
    passedTests++;
  }
  c.setGenome(temp.getGenome());
  if (c.getGenome() == temp.getGenome()) {
    passedTests++;
  }

  Covering co;
  c.setCovering(co);
  if (c.getCovering() == co) {
    passedTests++;
  }
  Eyes e;
  c.setEyes(e);
  if (c.getEyes() == e) {
    passedTests++;
  }
  Limbs l;
  c.setLimbs(l);
  if (c.getLimbs() == l) {
    passedTests++;
  }
  Encoding g;
  c.setGenome(g);
  if (c.getGenome() == g) {
    passedTests++;
  }
  
  std::cout << "Done with unit tests for Critter. # of tests passed: " << passedTests << " out of 10.\n";
}

// Output Operator
std::ostream & operator<< (std::ostream & os, const Critter & c) {
  os << c.toString();
  return os;
}
