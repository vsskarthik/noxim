#include "Fault.h"

#define DIRECTION_NORTH         0
#define DIRECTION_EAST          1
#define DIRECTION_SOUTH         2
#define DIRECTION_WEST          3

void Fault::injectFault(int num_of_dirs){
    int availableDirections[4] = {DIRECTION_NORTH,DIRECTION_EAST,DIRECTION_SOUTH,DIRECTION_WEST};
    //int num_of_dirs = rand()%3+1;


    if (num_of_dirs == 1){

        faults.push_back(availableDirections[rand()%4]);
    }

    if (num_of_dirs == 2){
        int rand1 = rand()%4;
        int rand2 = rand()%4;
        while(rand2 == rand1)
            rand2 = rand()%4;

        faults.push_back(availableDirections[rand1]);
        faults.push_back(availableDirections[rand2]);

    }
}

void Fault::print(){
    if (faults.size() == 1){
      cout <<"(" << faults[0] << ")";
    }
    else if(faults.size() == 2){
      cout <<"(" << faults[0] << "," << faults[1] << ")";
    }
    else{
      cout << "(nf)";
    }
  }
