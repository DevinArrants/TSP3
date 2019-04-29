#pragma once
#include "chromosome.hh"

class ClimbChromosome : public Chromosome
{
  public:
  ClimbChromosome* clone() const override;
  
  //local hill climbing: searches for the best solution in a 
  //neighborhood of the current chromosome
  void mutate() override;
};
