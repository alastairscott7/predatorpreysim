#include <iostream>
#include "organism.h"
#include "board.h"

using namespace std;

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//MEMBER FUNCTIONS OF ORGANISM CLASS
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

char Organism::getIdentifier()
{
    //used to retrieve organism identifier
    return identifier;
}

void Organism::setMoveStatus(bool moveStatus) 
{
    //flags the organism as moved or not moved
    moveComplete = moveStatus;
}

bool Organism::isStarving()
{
    //by default organisms are not starving
    return false;
}


bool Organism::getMovementStatus()
{
    //function to check if organism has moved this turn    
    return moveComplete;
}

bool Organism::boundaryFlag(int x, int y)
{
    //will return true if coordinates within boundary, or false if outside
    return (x >= 0) && (x < 20) && (y >= 0) && (y < 20);
}

void Organism::newLocation(int xx, int yy) 
{
    //This function will move an organism to a new location
    
    //move organism to new location
    organismBoard->setOrganism(xx, yy, organismBoard->getOrganism(xCoord, yCoord));
        
    //set old location to NULL
    organismBoard->setOrganism(xCoord, yCoord, NULL);
    
    //update coordinates
    xCoord = xx;
    yCoord = yy;
}