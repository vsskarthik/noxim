#include "Routing_CXY.h"

RoutingAlgorithmsRegister Routing_CXY::routingAlgorithmsRegister("CXY", getInstance());

Routing_CXY * Routing_CXY::routing_CXY = 0;
RoutingAlgorithm * Routing_CXY::odd_even = 0;
RoutingAlgorithm * Routing_CXY::xy = 0;

Routing_CXY * Routing_CXY::getInstance() {
	if ( routing_CXY == 0 )
		routing_CXY = new Routing_CXY();

	return routing_CXY;
}



vector<int> Routing_CXY::route(Router * router, const RouteData & routeData)
{
    Coord current = id2Coord(routeData.current_id);
    Coord destination = id2Coord(routeData.dst_id);
    vector <int> directions;
		//cout << routeData.current_id << endl;
		// If Congested
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
