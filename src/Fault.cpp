#include "Fault.h"



void Fault::injectFault(int num_of_dirs){
    int availableDirections[4] = {0,1,2,3};
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
    /*
    if(verbose){
        string referenceDirections[4] = {"NORTH","EAST","SOUTH","WEST"};

        if(faults.size()){
            cout << "Fault Found in Directions: ";
            for(int i:faults)
                cout << referenceDirections[i] << ", ";
            cout << endl;
        }
        else
            cout << "No Fault" << endl;
    }
    */
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
