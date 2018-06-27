#include <iostream>
#include "organism.h"
#include "board.h"

class Ant : public Organism
{
    public:
        //constructor for ant
        Ant(int xEntry, int yEntry, Board *thisBoard);
        
        //destructor
        ~Ant() {};
        
        //move instructions for ant
        void move();
        
        //breed instructions for ant
        void breed();
        
    private:
};