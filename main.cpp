#include <iostream>
#include <ctime>
#include "organism.h"
#include "ant.h"
#include "doodlebug.h"
#include "board.h"

using namespace std;

int main() {
    //Create simulation board
    Board simulation;
    //draw the board in the console
    simulation.drawGrid();
    
    //main program loop: will iterate through all organism functions
    //for one turn and then redraw the board in the console each time
    //the user presses the enter key
    while(cin.get() == '\n')
    {
        simulation.moveOrganisms();
        simulation.starveOrganisms();
        simulation.breedOrganisms();
        simulation.drawGrid();
        simulation.resetMovementStatus();
    }
}