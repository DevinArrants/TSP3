#include "climb_chromosome.hh"
#include <algorithm>
#include <random>

ClimbChromosome* clone() const override{
}


//local hill climbing: searches for the best solution in a
//neighborhood of the current chromosome
void mutate() override{
   //evaluate the fitness of the current chromosome
   double fit = get_fitness();
  
   //pick a random point p in the chromosome
   std::uniform_int_distribution<int> dis(0,order_.size() -1);
   unsigned p = dis(generator_);
   //Swap the city at index p with the city at index p-1 
   //and evaluate the resulting chromosome's fitness.
   auto begin = order_[p];
   auto end;
   if(p==0)	end = order_[order_.size() -1];
   else         end = order_[p-1];
   std::swap(begin, end);
   assert(is_valid());
   double fit1 = get_fitness;

   //reverse swap
   std::swap(begin, end);

   //swap the city at index p from original chromosome with the city at index
   //p+1 and evaluate the resulting chromosome's fitness.
   //If p==N-1, swap with the city at index 0 instread of at index N using mod

   auto end1;
   if(p == order_[order_.size() - 1])	end1 = order_[0];
   else					end1 = order_[p+1];
   std::swap(begin, end1);
   double fit2 = get_fitness;

   //reverse swap
   std::swap(begin, end1);

   //find the best fitness
   if(fit1 > fit){
	   if(fit1 > fit2){
		   std::swap(begin, end);
	   }
	   else{
		   std::swap(begin, end1);
	   }
   }

   else if(fit2 > fit){
	   if(fit2 > fit1){
		   std::swap(begin, end1);
	   }
	   else{
		   std::swap(begin, end);
	   }
   } 

}

ClimbChromosome* ClimbChromosome::close() const
{
	return new ClimChromosome(*this);
}

