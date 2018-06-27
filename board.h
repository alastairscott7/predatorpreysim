#ifndef BOARD_H
#define BOARD_H

#include "organism.h"

class Board
{
    public:
    //grid board where the organisms are located
    Organism *grid[20][20];
    
    //Default constructor
    Board();
    
    //Destructor
    ~Board();
    
    //Returns the organism at a location
    Organism* getOrganism(int x, int y) const;
    
    //sets the organism at a location
    void setOrganism(int x, int y, Organism* spawn);
    
    //Goes through grid and moves all organisms
    void moveOrganisms();
    
    //Resets all movement flags
    void resetMovementStatus();
    
    //draws the grid to the console
    void drawGrid();
    
    //initializes the board
    void initializeBoard();
    
    //go through grid and get organisms to Breed
    void breedOrganisms();
    
    //function that creates a new ant (used during breeding)
    void setNewAnt(int x, int y);
    
    //function that creates a new doodlebug (used during breeding)
    void setNewDoodle(int x, int y);
    
    //function that will starve organisms that are beyond the defined threshold
    void starveOrganisms();
    
    private:
};

#endif