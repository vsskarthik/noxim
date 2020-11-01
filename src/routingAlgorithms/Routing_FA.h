#ifndef __NOXIMROUTING_FA_H__
#define __NOXIMROUTING_FA_H__

#include "RoutingAlgorithm.h"
#include "RoutingAlgorithms.h"
#include "../Router.h"


using namespace std;

class Routing_FA : RoutingAlgorithm {
	public:
		vector<int> route(Router * router, const RouteData & routeData);
		static Routing_FA * getInstance();

	private:
		Routing_FA(){};
		~Routing_FA(){};
		static Routing_FA * routing_FA;
		static RoutingAlgorithmsRegister routingAlgorithmsRegister;
		static RoutingAlgorithm * odd_even;
		static RoutingAlgorithm * xy;


};

#endif
