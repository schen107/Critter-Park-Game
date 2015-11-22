/**************************************
 * 600.120 Intermediate Programming (Fall 2015)
 * Homework #9
 * Encoding.cpp
 * Last Modified: November 9, 2015
 *
 ***** Names of Contributors:
 * Steven Chen | schen107 | schen107@jhu.edu | (302)438-0262
 * Inez Lam | ilam1 | ilam1@jhu.edu | (805)338-5461
 * Code scaffolding from: Ben Mitchell
****************************************/

#include "../include/Encoding.hpp"

Encoding :: Encoding(encoding_t d) : data(d)
{
}

// Modify data bit-string to put an assigned value to its offset.
void Encoding :: setBitField(unsigned int offset, unsigned int width, unsigned int value) {

  encoding_t mask = 0;
  for (unsigned int i = 0; i < width; i++) {
    mask+=1;
    mask <<= 1;
  }
  mask >>= 1;
  mask <<= offset;
  mask = ~mask;
  value <<= offset;

  data &= mask;
  data |= value;
}

// Retrieve bit-string from data interpreted as an unsigned integer.
unsigned int Encoding :: getBitField(unsigned int offset, unsigned int width) {

  unsigned int value;
  encoding_t mask = 0;
  encoding_t copy = data;

  for (unsigned int i = 0; i < width; i++) {
    mask+=1;
    mask <<= 1;
  }

  mask >>= 1;
  mask <<= offset;
  copy &= mask;
  copy >>= offset;
  value = (unsigned int) copy;
  return value;
}

encoding_t Encoding :: getData() const {
  return data;
}

void Encoding :: setData(encoding_t data) {
  this->data = data;
}

// Mutation
Encoding Encoding :: mutate(double mutationRate) {
  
  double r; // Mutation rate
  encoding_t mask = 0;
  for (unsigned int i = 0; i<sizeof(encoding_t)*8; i++) {
    r = (double) rand()/RAND_MAX;
    if (r < mutationRate) {
      mask+=1;
    }
    mask <<= 1;
  }
  mask >>= 1;
  data ^= mask;

  return *this;

}

// Crossover
Encoding Encoding :: crossover(const Encoding &other, double crossoverRate) {
  
  Encoding offspring(0);
  double r; // Crossover rate
  bool p1 = true;
  encoding_t mask = 0;
  for (unsigned int i = 0; i<sizeof(encoding_t)*8; i++) {
    r = (double) rand()/RAND_MAX;
    if (r < crossoverRate) {
      p1 = !p1;
      if (p1) {
        mask+=1;
      }
      mask <<= 1;
    }
  }
  offspring.setData((data & mask) | (other.getData() & ~mask));

  return offspring;
}

bool Encoding :: operator== (const Encoding &other) {
  return data == other.getData();
}

// Unit Testing
void Encoding :: unitTest() {
  std::cout << "Starting unit tests for Encoding class...\n";

  int passedTests = 0;

  Encoding g(10);
  encoding_t test = 26;
  if (g.getBitField(0,4) == 10) {
    passedTests++;
  }
  g.setBitField(4,1,1);
  if (g.getData() == test) {
    passedTests+=2;
  }
  g.setData(10);
  if (g.getBitField(0,4) == 10) {
    passedTests++;
  }
  Encoding mutateTest = g.mutate(0);
  if (mutateTest.getData() == 10) {
    passedTests++;
  }
  Encoding parent(20);
  Encoding crossoverTest = g.crossover(parent,0);
  if (parent == crossoverTest) {
    passedTests+=2;
  }

  std::cout << "Done with unit tests for Encoding. # of tests passed: " << passedTests << " out of 7.\n";

}
