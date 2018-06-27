#ifndef ORGANISM_H
#define ORGANISM_H

class Board;

class Organism
{
    public:
        //These are the coordinates of the organism
        int xCoord, yCoord;
        
        //counter for breeding threshold
        int breedCounter;
        
        //This is the identification character of the organism
        char identifier;
        
        //this pointer points to the board that the organism is located on
        Board *organismBoard;
        
        //getIdentifier returns idenfication character of organism
        char getIdentifier();
        
        //virtual move function
        virtual void move() = 0;
        
        //virtual breed function
        virtual void breed() = 0;
        
        //virtual function to check if organism is starving
        virtual bool isStarving();
        
        //This function signifies the organism has completed it's move for this turn
        bool moveComplete;
        
        //This function returns false if the organism tries to move out of bounds
        bool boundaryFlag(int x, int y);
        
        //This function moves the organism to it's new location
        void newLocation(int xx, int yy);
        
        //This function changes movement status
        void setMoveStatus(bool moveStatus);
        
        //This function returns whether or not the organism has moved already that turn
        bool getMovementStatus();
    
    private:
    
};

#endif