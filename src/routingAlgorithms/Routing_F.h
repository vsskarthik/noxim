#ifndef __NOXIMROUTING_F_H__
#define __NOXIMROUTING_F_H__

#include "RoutingAlgorithm.h"
#include "RoutingAlgorithms.h"
#include "../Router.h"
#include "../Fault.h"
 
using namespace std;

class Routing_F : RoutingAlgorithm {
	public:
		vector<int> route(Router * router, const RouteData & routeData);
		static Routing_F * getInstance();
        bool isFaultThere();
	private:
		Routing_F(){};
		~Routing_F(){};
		static Routing_F * routing_F;
		static RoutingAlgorithmsRegister routingAlgorithmsRegister;
		static RoutingAlgorithm * odd_even;
		static RoutingAlgorithm * xy;

};

#endif
