#include "Routing_FA.h"

RoutingAlgorithmsRegister Routing_FA::routingAlgorithmsRegister("FA", getInstance());

Routing_FA * Routing_FA::routing_FA = 0;
RoutingAlgorithm * Routing_FA::odd_even = 0;
RoutingAlgorithm * Routing_FA::xy = 0;

Routing_FA * Routing_FA::getInstance() {
	if ( routing_FA == 0 )
		routing_FA = new Routing_FA();

	return routing_FA;
}


vector<int> Routing_FA::route(Router * router, const RouteData & routeData)
{
    Coord current = id2Coord(routeData.current_id);
    Coord destination = id2Coord(routeData.dst_id);

    // Routing
    vector <int> directions,temp_dirs;
		odd_even = RoutingAlgorithms::get("ODD_EVEN");
		if(!odd_even)
			assert(false);
		temp_dirs = odd_even->route(router, routeData);

		if(temp_dirs.size() == 2){
			int ci0 = router->CI(temp_dirs[0]);
			int ci1 = router->CI(temp_dirs[1]);

			if(ci0 < ci1){
				directions.push_back(temp_dirs[0]);
			}
			else if(ci0 > ci1){
				directions.push_back(temp_dirs[1]);
			}
			else if(ci0 == ci1){
				directions = temp_dirs;
			}
		}

		return temp_dirs;

}
