/**************************************
 * 600.120 Intermediate Programming (Fall 2015)
 * Homework #9
 * Covering.hpp
 * Last Modified: November 9, 2015
 *
 ***** Names of Contributors:
 * Steven Chen | schen107 | schen107@jhu.edu | (302)438-0262
 * Inez Lam | ilam1 | ilam1@jhu.edu | (805)338-5461
 * Code scaffolding from: Ben Mitchell
 ***************************************/

#ifndef _SCHEN107_ILAM1_COVERING_HPP
#define _SCHEN107_ILAM1_COVERING_HPP

#include "Encoding.hpp"
#include "Feature.hpp"

class Covering : public Feature {
  
  public:

    Covering(unsigned int ty=rand()%4, 
             unsigned int c=rand()%4, 
             unsigned int te=rand()%4);

    // Getters and Setters
    unsigned int getType() const;
    unsigned int getColor() const;
    unsigned int getTexture() const;
    Trait getTrait() const;
    Covering setType(unsigned int t);
    Covering setColor(unsigned int c);
    Covering setTexture(unsigned int te);

    // Methods
    std::string toString() const override;
    void encode(Encoding& genome) override;
    void decode(Encoding genome) override;

    // Operator overloading (for unit testing)
    bool operator== (const Covering &other);

    // Unit test
    static void unitTest();

  private:
    // Covering Attributes
    unsigned int type;
    unsigned int color;
    unsigned int texture;

    static std::map<int, Trait> typeMap;
    static std::map<int, Trait> colorMap;
    static std::map<int, Trait> textureMap;

    Trait coverTrait;
};


#endif
