/**************************************
 * 600.120 Intermediate Programming (Fall 2015)
 * Homework #9
 * Critter.hpp
 * Last Modified: November 9, 2015
 *
 ***** Names of Contributors:
 * Steven Chen | schen107 | schen107@jhu.edu | (302)438-0262
 * Inez Lam | ilam1 | ilam1@jhu.edu | (805)338-5461
 * Code scaffolding from: Ben Mitchell
****************************************/

#ifndef _SCHEN107_ILAM1_CRITTER_HPP
#define _SCHEN107_ILAM1_CRITTER_HPP

#include <iostream>
#include <vector>
#include "Feature.hpp"
#include "Limbs.hpp"
#include "Covering.hpp"
#include "Eyes.hpp"
#include "Encoding.hpp"

#define NUM_FEATURES 3
#define NUM_TRAITS 3

#define MUT_RATE 0.05
#define CROSS_RATE 0.1

class Critter {

  friend std::ostream & operator<< (std::ostream & os, const Critter & c);

  public:

    // Constructors
    Critter(std::string n = "");
    
    // Getters and Setters
    std::string getName() const;
    Covering getCovering() const;
    Eyes getEyes() const;
    Limbs getLimbs() const;
    Encoding getGenome() const;
    Trait getTrait() const;
    void setName(std::string name);
    void setCovering(Covering cover);
    void setEyes(Eyes eye);
    void setLimbs(Limbs limb);
    void setGenome(Encoding genome);
    void setTrait(Trait trait1, Trait trait2, Trait trait3);

    // Breed Critter
    Critter breedCritter(const Critter p, std::string name);

    // Display Critter
    std::string toString() const;

    // Critter Operators
    void operator= (const Critter &other);
    bool operator== (const Critter &other);
    bool operator< (const Critter &other);
    bool operator> (const Critter &other);

    // Unit Test
    static void unitTest();

  private:
    // Member variables
    std::string name;
    std::vector<Feature> featureList;
    Eyes eye;
    Feature &er = eye;
    Covering cover;
    Feature &cr = cover;
    Limbs limb;
    Feature &lr = limb;
    Encoding genome;
    Encoding &gr = genome;
    Trait critterTrait;
    
};

std::ostream & operator<< (std::ostream & os, const Critter & c); 

#endif
