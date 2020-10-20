#ifndef _FAULT_H__
#define _FAULT_H__

int injectFault(){
  bool verbose = true;
	int BlockedDirection = NULL;
	int availableDirections[4] = {DIRECTION_NORTH,DIRECTION_EAST,DIRECTION_SOUTH,DIRECTION_WEST};
	string referenceDirections[4] = {"NORTH","EAST","SOUTH","WEST"};
	if (rand()%2){ // Check if fault is there at router
			//Choose random fault directions
			BlockedDirection = availableDirections[rand()%4];
			//cout << "Fault Found at: " << referenceDirections[BlockedDirection] << endl;
	}
	else{
		//cout << "No Fault" << endl;
	}

  if(verbose){
    if(BlockedDirection)
      cout << "Fault Found at: " << referenceDirections[BlockedDirection]<< endl;
    else
      cout << "No Fault" << endl;
    }
	return BlockedDirection;

}


#endif
