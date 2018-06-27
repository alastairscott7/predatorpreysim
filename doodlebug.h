
#include "board.h"
#include "organism.h"

class Doodlebug : public Organism
{
    public:
    
        //counter for starving threshold
        int deathCounter;
    
        //constructor
        Doodlebug(int xEntry, int yEntry, Board *thisBoard);
        
        //Destructor
        ~Doodlebug() {};
        
        //movement instructions for doodlebug
        void move();
        
        //breed instructions for doodlebug
        void breed();
        
        //flag for starving doodlebug
        bool isStarving();
        
    private:
};