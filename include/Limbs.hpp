/**************************************
 * 600.120 Intermediate Programming (Fall 2015)
 * Homework #9
 * Limbs.hpp
 * Last Modified: November 9, 2015
 *
 ***** Names of Contributors:
 * Steven Chen | schen107 | schen107@jhu.edu | (302)438-0262
 * Inez Lam | ilam1 | ilam1@jhu.edu | (805)338-5461
 * Code scaffolding from: Ben Mitchell
****************************************/

#ifndef _SCHEN107_ILAM1_LIMBS_HPP
#define _SCHEN107_ILAM1_LIMBS_HPP

#include "Encoding.hpp"
#include "Feature.hpp"

class Limbs : public Feature {
  
  public:
    Limbs(unsigned int p=rand()%4+1, 
          unsigned int ty=rand()%4, 
          unsigned int l=rand()%4,
          unsigned int th=rand()%4);

    // Getters and Setters
    unsigned int getPairNumber() const;
    unsigned int getType() const;
    unsigned int getLength() const;
    unsigned int getThickness() const;
    Trait getTrait() const;
    Limbs setPairNumber(unsigned int p);
    Limbs setType(unsigned int t);
    Limbs setLength(unsigned int l);
    Limbs setThickness(unsigned int th);

    // Methods
    std::string toString() const override;
    void encode(Encoding& genome) override;
    void decode(Encoding genome) override;

    // Operator overloading (for unit testing)
    bool operator== (const Limbs &other);

    // Unit test
    static void unitTest();

  private:
    // Limb Attributes
    unsigned int pairs;
    unsigned int type;
    unsigned int length;
    unsigned int thickness;

    static std::map<int, Trait> typeMap;
    static std::map<int, Trait> lengthMap;
    static std::map<int, Trait> thicknessMap;

    Trait limbTrait;
};


#endif
