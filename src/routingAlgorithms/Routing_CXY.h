#ifndef __NOXIMROUTING_CXY_H__
#define __NOXIMROUTING_CXY_H__

#include "RoutingAlgorithm.h"
#include "RoutingAlgorithms.h"
#include "../Router.h"

using namespace std;

class Routing_CXY : RoutingAlgorithm {
	public:
		vector<int> route(Router * router, const RouteData & routeData);
		static Routing_CXY * getInstance();
	private:
		Routing_CXY(){};
		~Routing_CXY(){};
		static Routing_CXY * routing_CXY;
		static RoutingAlgorithmsRegister routingAlgorithmsRegister;
		static RoutingAlgorithm * odd_even;
		static RoutingAlgorithm * xy;

};

#endif
