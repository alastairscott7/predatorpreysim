#include <cstdlib>
#include <iostream>
#include "ant.h"
#include "organism.h"
#include "board.h"
using namespace std;

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//MEMBER FUNCTIONS OF ANT SUB-CLASS
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Ant::Ant(int xEntry, int yEntry, Board *thisBoard)
{
    //Ant default constructor
    identifier='A';
    xCoord = xEntry;
    yCoord = yEntry;
    organismBoard = thisBoard;
    moveComplete = false;
    breedCounter = 0;
}

void Ant::move()
{
    //This function will move an ant in a random direction
    
    //increment breed counter, one more turn towards being able to breed
    breedCounter++;
    
    //int direction is set to a random direction between 1 and 4
    int direction;
    direction = rand() % 4 + 1;
    
    //if statement which determines how to move the ant based on what direction was selected
    if(direction == 1)
    {
        //direction 1 is down
        //check that space below is free and valid
        if(organismBoard->getOrganism(xCoord, yCoord + 1) == NULL && boundaryFlag(xCoord, yCoord + 1))
        {
            //call new location function to move one space down
            newLocation(xCoord, yCoord + 1);
            
            //update move complete so that the ant will not move again this turn
            moveComplete = true;
        }
    }
    else if(direction == 2)
    {
        //direction 2 is right
        //check that space right is free and valid
       if(organismBoard->getOrganism(xCoord + 1, yCoord) == NULL && boundaryFlag(xCoord + 1, yCoord))
        {
            //call new location function to move one space right
            newLocation(xCoord + 1, yCoord);
            
            //update move complete so that the ant will not move again this turn
            moveComplete = true;
        } 
    }
    else if(direction == 3)
    {
        //direction 3 is up
        //check that space above is free and valid
        if(organismBoard->getOrganism(xCoord, yCoord - 1) == NULL && boundaryFlag(xCoord, yCoord - 1))
        {
            //call new location function to move one space up
            newLocation(xCoord, yCoord - 1);
            
            //update move complete so that the ant will not move again this turn
            moveComplete = true;
        }
    }
    else if(direction == 4)
    {
        //direction 4 is left
        //check that space left is free and valid
        if(organismBoard->getOrganism(xCoord - 1, yCoord) == NULL && boundaryFlag(xCoord - 1, yCoord))
        {
            //call new location function to move one space left
            newLocation(xCoord - 1, yCoord);
            
            //update move complete so that the ant will not move again this turn
            moveComplete = true;
        }
    }
}

void Ant::breed()
{
    //This function will spawn a new ant in an unoccupied cell
    
    //check if breed counter has exceeded the breeding threshold value
    if(breedCounter >= 3)
    {
        //try to find an unoccupied cell to spawn new ant into, then reset breed counter
        if((organismBoard->getOrganism(xCoord, yCoord + 1) == NULL) && boundaryFlag(xCoord, yCoord + 1))
        {
            organismBoard->setNewAnt(xCoord, yCoord + 1);
            breedCounter = 0;
        }
        else if((organismBoard->getOrganism(xCoord + 1, yCoord) == NULL) && boundaryFlag(xCoord + 1, yCoord))
        {
            organismBoard->setNewAnt(xCoord + 1, yCoord);
            breedCounter = 0;
        }
        else if((organismBoard->getOrganism(xCoord, yCoord - 1) == NULL) && boundaryFlag(xCoord, yCoord - 1))
        {
            organismBoard->setNewAnt(xCoord, yCoord - 1);
            breedCounter = 0;
        }
        else if((organismBoard->getOrganism(xCoord - 1, yCoord) == NULL) && boundaryFlag(xCoord - 1, yCoord))
        {
            organismBoard->setNewAnt(xCoord - 1, yCoord);
            breedCounter = 0;
        }
        else
        {
            //if no cells unoccupied, do not breed
            breedCounter = 0;
        }
    }
}