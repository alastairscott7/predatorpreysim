#include "doodlebug.h"
#include "organism.h"
#include <cstdlib>
using namespace std;

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//MEMBER FUNCTIONS FOR DOODLEBUG SUB-CLASS
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Doodlebug::Doodlebug(int xEntry, int yEntry, Board *thisBoard)
{
    //Doodlebug default constructor
    identifier='D';
    xCoord = xEntry;
    yCoord = yEntry;
    organismBoard = thisBoard;
    moveComplete = false;
    breedCounter = 0;
}

void Doodlebug::move()
{
    //This function will move the doodlebug in a random direction.
    //If there is an ant near it, the doodlebug will eat the ant
    
    //update breed and death counters, which will decide when they will breed or die
    breedCounter++;
    deathCounter++;
    
    //direction is set to a random direction
    int direction;
    direction = rand() % 4 + 1;
    
    //Check to see if there are ants nearby that can be eaten. If there is,
    //the ant will be deleted and the doodlebug will take it's place. Death
    //counter will also be reset and moveComplete will be set to true.
    if(organismBoard->getOrganism(xCoord, yCoord + 1) != NULL)
    {
        if(organismBoard->getOrganism(xCoord, yCoord + 1)->getIdentifier() == 'A')
        {
            delete organismBoard->getOrganism(xCoord, yCoord + 1);
            newLocation(xCoord, yCoord + 1);
            deathCounter = 0;
            moveComplete = true;
            return;
        }
    }
    if(organismBoard->getOrganism(xCoord + 1, yCoord) != NULL)
    {
        if(organismBoard->getOrganism(xCoord + 1, yCoord)->getIdentifier() == 'A')
        {
            delete organismBoard->getOrganism(xCoord + 1, yCoord);
            newLocation(xCoord + 1, yCoord);
            deathCounter = 0;
            moveComplete = true;
            return;
        }
    }
    if(organismBoard->getOrganism(xCoord, yCoord - 1) != NULL)
    {
        if(organismBoard->getOrganism(xCoord, yCoord - 1)->getIdentifier() == 'A')
        {
            delete organismBoard->getOrganism(xCoord, yCoord - 1);
            newLocation(xCoord, yCoord - 1);
            deathCounter = 0;
            moveComplete = true;
            return;
        }
    }
    if(organismBoard->getOrganism(xCoord - 1, yCoord) != NULL)
    {
        if(organismBoard->getOrganism(xCoord - 1, yCoord)->getIdentifier() == 'A')
        {
            delete organismBoard->getOrganism(xCoord - 1, yCoord);
            newLocation(xCoord - 1, yCoord);
            deathCounter = 0;
            moveComplete = true;
            return;
        }
    }
    
    //If there are no nearby ants, the doodlebug will move in a random direction
    //based on what direction was set to. This movement works the same as in
    //the ant sub-class
    if(direction == 1)
    {
        if(organismBoard->getOrganism(xCoord, yCoord + 1) == NULL && boundaryFlag(xCoord, yCoord + 1))
        {
            newLocation(xCoord, yCoord + 1);
            moveComplete = true;
        }
    }
    else if(direction == 2)
    {
    if(organismBoard->getOrganism(xCoord + 1, yCoord) == NULL && boundaryFlag(xCoord + 1, yCoord))
        {
            newLocation(xCoord + 1, yCoord);
            moveComplete = true;
        } 
    }
    else if(direction == 3)
    {
        if(organismBoard->getOrganism(xCoord, yCoord - 1) == NULL && boundaryFlag(xCoord, yCoord - 1))
        {
            newLocation(xCoord, yCoord - 1);
            moveComplete = true;
        }
    }
    else if(direction == 4)
    {
        if(organismBoard->getOrganism(xCoord - 1, yCoord) == NULL && boundaryFlag(xCoord - 1, yCoord))
            {
                newLocation(xCoord - 1, yCoord);
                moveComplete = true;
            }
    }
}

void Doodlebug::breed()
{
    //This function will spawn a new doodlebug in an adjacent cell
    
    //First check to see if breedcounter has exceeded it's threshold. If it has,
    //spawn new doodlebug in an unoccupied adjacent cell.
    if(breedCounter >= 8)
    {
        if((organismBoard->getOrganism(xCoord, yCoord + 1) == NULL) && boundaryFlag(xCoord, yCoord + 1))
        {
            organismBoard->setNewDoodle(xCoord, yCoord + 1);
            breedCounter = 0;
        }
        else if((organismBoard->getOrganism(xCoord + 1, yCoord) == NULL) && boundaryFlag(xCoord + 1, yCoord))
        {
            organismBoard->setNewDoodle(xCoord + 1, yCoord);
            breedCounter = 0;
        }
        else if((organismBoard->getOrganism(xCoord, yCoord - 1) == NULL) && boundaryFlag(xCoord, yCoord - 1))
        {
            organismBoard->setNewDoodle(xCoord, yCoord - 1);
            breedCounter = 0;
        }
        else if((organismBoard->getOrganism(xCoord - 1, yCoord) == NULL) && boundaryFlag(xCoord - 1, yCoord))
        {
            organismBoard->setNewDoodle(xCoord - 1, yCoord);
            breedCounter = 0;
        }
        else
        {
            //if there's no available spaces, do not breed
            breedCounter = 0;
        }
    }
}

bool Doodlebug::isStarving()
{
    //this function returns whether or not a doodlebug is starving
    
    //starving if deathcounter exceeds threshold
    if(deathCounter >= 3)
    {
        return true;
    }
    else
    {
        return false;
    }
}