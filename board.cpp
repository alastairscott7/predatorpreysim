#include <iostream>
#include <cstdlib>
#include "board.h"
#include "ant.h"
#include "doodlebug.h"
using namespace std;

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//MEMBER FUNCTIONS OF BOARD CLASS
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Board::Board()
{
    //This is the default constructor for the board class
    
    //creating an empty array
    for (int y = 0; y < 20; y++)
        for (int x = 0; x < 20; x++)
            grid[x][y] = nullptr;

    //Initialize ants and doodlebugs
    initializeBoard();
}

Board::~Board() 
{
    //This is the destructor for the board class
    
    //loop to delete all grid elements
    for (int i = 0; i < 20; i++) 
    {
        for (int j = 0; j < 20; j++) 
        {
            if (grid[i][j] != NULL)
            {
                delete grid[i][j];
                grid[i][j] = nullptr;
            }
        }
    }
}

void Board::drawGrid()
{
    //This member function draws the Ants, Doodlebugs
    //and empty spaces on a 20x20 grid.
    
    //lineNum gives each line of the grid a number
    int lineNum = 0;
    
    //This loop decides what symbol represents each element of the grid
    for (int y = 0; y < 20; y++)
    {
        lineNum++;
        //cout << lineNum;
        for (int x = 0; x < 20; x++)
        {
            if (grid[x][y] == nullptr)
            {
                //empty cells
                cout << '.'; 
            }
            else
            {
                //occupied cells
                cout << grid[x][y]->getIdentifier();
            }
        }
        //next line
        cout << endl;
    }
}

void Board::initializeBoard()
{
    //This member function initializes ants and doodlebugs
    
    int doodleX, doodleY;
    int antX, antY;

    //seed random number generator
    srand(time(NULL));

    //Create 5 doodlebugs
    for (int doodleAmount = 0; doodleAmount < 5; doodleAmount++)
    {
        doodleX = rand() % 20;
        doodleY = rand() % 20;

        //If cell is occupied try again
        while (grid[doodleX][doodleY] != nullptr)
        {
            doodleX = rand() % 20;
            doodleY = rand() % 20;
        }
        grid[doodleX][doodleY] = new Doodlebug(doodleX, doodleY, this);
    }
    //Create 100 ants
    for (int antAmount = 0; antAmount < 100; antAmount++)
    {
        antX = rand() % 20;
        antY = rand() % 20;

        //If cell is occupied try again
        while (grid[antX][antY] != nullptr)
        {
            antX = rand() % 20;
            antY = rand() % 20;
        }
        grid[antX][antY] = new Ant(antX, antY, this);
    }
}

void Board::moveOrganisms()
{
    //This function will move all organisms on the grid if they haven't move
    //yet this turn
    
    //first move all doodlebugs
    for(int i = 0; i < 20; i++)
    {
        for(int j = 0; j < 20; j++)
        {
            //check for occupied grid spaces
            if(grid[i][j] != NULL)
            {
                //check movement status
                if(grid[i][j]->getMovementStatus() == false)
                {
                    //check organism is a doodlebug
                    if(grid[i][j]->getIdentifier() == 'D')
                    {
                        //move doodlebug
                        grid[i][j]->move();
                    }
                }
            }
        }
    }
    
    //next move ants
    for(int i = 0; i < 20; i++)
    {
        for(int j = 0; j < 20; j++)
        {
            //check for occupied grid spaces
            if(grid[i][j] != NULL)
            {
                //check movement status
                if(grid[i][j]->getMovementStatus() == false)
                {
                    //check organism is an ant
                    if(grid[i][j]->getIdentifier() == 'A')
                    {
                        //move ant
                        grid[i][j]->move();
                    }
                }
            }
        }
    }
}

Organism* Board::getOrganism(int x, int y) const 
{
    //This function will return the organism occupying a grid location
    
    if ((x >= 0) && (x < 20) && (y >= 0) && (y < 20)) 
    {
        return grid[x][y];
    } else 
    {
        return NULL;
    }
}

void Board::setOrganism(int x, int y, Organism* newOrganism) 
{
    //This function will set the organism at a certain grid location
    //to a new organism passed into the function
    
    if ((x >= 0) && (x < 20) && (y >= 0) && (y < 20)) 
    {
        grid[x][y] = newOrganism;
    }
}

void Board::setNewAnt(int x, int y)
{
    //This function will create a new and at location passed in
    
    if ((x >= 0) && (x < 20) && (y >= 0) && (y < 20)) 
    {
        grid[x][y] = new Ant(x, y, this);
    }
}

void Board::setNewDoodle(int x, int y)
{
    //This function will create a new doodlebug at location passed in
    
    if ((x >= 0) && (x < 20) && (y >= 0) && (y < 20)) 
    {
        grid[x][y] = new Doodlebug(x, y, this);
    }
}

void Board::breedOrganisms()
{
    //This function will attempt to make all organisms breed in the grid
    
    for(int i = 0; i < 20; i++)
    {
        for(int j = 0; j < 20; j++)
        {
            if(grid[i][j] != NULL)
            {
                grid[i][j]->breed();
            }
        }
    }
}

void Board::starveOrganisms()
{
    //This function will starve all doodlebugs that have not eaten recently
    for (int i = 0; i < 20; i++) 
    {
        for (int j = 0; j < 20; j++)
        {
            //check for doodlebugs that are starving
            if ((grid[i][j] != NULL) && grid[i][j]->isStarving()) 
            {
                delete grid[i][j];
                grid[i][j] = NULL;
            }
        }
    }
}

void Board::resetMovementStatus() 
{
    //This function will reset the movement status of all organisms
    //on the grid.
    for(int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            if(grid[i][j] != NULL)
            {
                grid[i][j]->setMoveStatus(false);
            }
        }
    }
}