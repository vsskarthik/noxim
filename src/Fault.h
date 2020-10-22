#ifndef _FAULT_H__
#define _FAULT_H__

vector<int> injectFault(bool verbose){
    vector<int> BlockedDirection;
    int availableDirections[4] = {DIRECTION_NORTH,DIRECTION_EAST,DIRECTION_SOUTH,DIRECTION_WEST};
    int num_of_dirs = rand()%3+1;

    if (num_of_dirs == 2){
        BlockedDirection.push_back(availableDirections[rand()%4]);
    }
    if (num_of_dirs == 3){
        int rand1 = rand()%4;
        int rand2 = rand()%4;
        while(rand2 == rand1)
            rand2 = rand()%4;

        BlockedDirection.push_back(availableDirections[rand1]);
        BlockedDirection.push_back(availableDirections[rand2]);
    }


    if(verbose){
        string referenceDirections[4] = {"NORTH","EAST","SOUTH","WEST"};

        if(BlockedDirection.size()){
            cout << "Fault Found in Directions: ";
            for(int i:BlockedDirection)
                cout << referenceDirections[i] << ", ";
            cout << endl;
        }
        else
            cout << "No Fault" << endl;
    }
    return BlockedDirection;


}


#endif
