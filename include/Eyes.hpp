/**************************************
 * 600.120 Intermediate Programming (Fall 2015)
 * Homework #9
 * Eyes.hpp
 * Last Modified: November 9, 2015
 *
 ***** Names of Contributors:
 * Steven Chen | schen107 | schen107@jhu.edu | (302)438-0262
 * Inez Lam | ilam1 | ilam1@jhu.edu | (805)338-5461
 * Code scaffolding from: Ben Mitchell
****************************************/

#ifndef _SCHEN107_ILAM1_EYES_HPP
#define _SCHEN107_ILAM1_EYES_HPP

#include "Encoding.hpp"
#include "Feature.hpp"

class Eyes : public Feature {
  
  public:
    Eyes(unsigned int p=rand()%4+1, 
         unsigned int t=rand()%4, 
         unsigned int c=rand()%4);

    // Getters and Setters
    unsigned int getPairNumber() const;
    unsigned int getType() const;
    unsigned int getColor() const;
    Trait getTrait() const;
    Eyes setPairNumber(unsigned int p);
    Eyes setType(unsigned int t);
    Eyes setColor(unsigned int c);

    // Methods
    std::string toString() const override;
    void encode(Encoding& genome) override;
    void decode(Encoding genome) override;
    
    // Operator overloading (for unit testing)
    bool operator== (const Eyes &other);

    // Unit test
    static void unitTest();


  private:
    // Eyes Attributes
    unsigned int pairs;
    unsigned int type;
    unsigned int color;

    static std::map<int, Trait> typeMap;
    static std::map<int, Trait> colorMap;    
   
    Trait eyeTrait;
};


#endif
