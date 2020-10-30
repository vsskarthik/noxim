#include "Selection_FA.h"

SelectionStrategiesRegister Selection_FA::selectionStrategiesRegister("FA", getInstance());

Selection_FA * Selection_FA::selection_FA = 0;

Selection_FA * Selection_FA::getInstance() {
	if ( selection_FA == 0 )
		selection_FA = new Selection_FA();

	return selection_FA;
}

int Selection_FA::apply(Router * router, const vector < int >&directions, const RouteData & route_data){
    assert(directions.size()!=0);
		

}

void Selection_FA::perCycleUpdate(Router * router){ }
