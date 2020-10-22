#include "Routing_F.h"

RoutingAlgorithmsRegister Routing_F::routingAlgorithmsRegister("F", getInstance());

Routing_F * Routing_F::routing_F = 0;
RoutingAlgorithm * Routing_F::odd_even = 0;
RoutingAlgorithm * Routing_F::xy = 0;

Routing_F * Routing_F::getInstance() {
	if ( routing_F == 0 )
		routing_F = new Routing_F();

	return routing_F;
}


vector<int> Routing_F::route(Router * router, const RouteData & routeData)
{
    Coord current = id2Coord(routeData.current_id);
    Coord destination = id2Coord(routeData.dst_id);

		//Fault Injection
		vector<int> BlockedDirection = injectFault(true); // args: verbose(bool) return: vector<int> of Blocker Directions(may be 0,1,2)

    // Routing
    vector <int> directions;
	  if(router -> inCongestion()){ // If congested use OE
			odd_even = RoutingAlgorithms::get("ODD_EVEN");
			if(!odd_even)
				assert(false);
			directions = odd_even->route(router, routeData);
			directions.resize(1);
		}
		else{ // else use XY
			xy = RoutingAlgorithms::get("XY");
			if(!xy)
				assert(false);
			directions = xy->route(router, routeData);

		}

	    return directions;

}
