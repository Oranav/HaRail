/* HaRail - Public transport fastest-route finder for Israel Railways
* Copyright(C) 2014  haha01haha01

* This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

* This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

* You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.*/

#ifndef __NODE_H__
#define __NODE_H__

#include "common.h"

class Node {
public:
	// Class Methods
	Node(Station *station, int time)
		: station(station),
		station_time(time),
		edges(),
		visited(false),
		best_cost(UNEXPLORED_COST),
		best_source(nullptr),
		best_dest(nullptr) {}
	virtual ~Node() {}

	// Property Accessors
	Station *getStation() const { return station; }
	int getStationTime() const { return station_time; }
	vector<Edge *>& getEdges() { return edges; }
	const vector<Edge *>& getEdges() const { return edges; }
	bool getVisited() const { return visited; }
	void setVisited(bool visited) { this->visited = visited; }
	int getBestCost() const { return best_cost; }
	void setBestCost(int best_cost) { this->best_cost = best_cost; }
	Edge *getBestSource() const { return best_source; }
	void setBestSource(Edge *best_source) { this->best_source = best_source; }
	Edge *getBestDest() const { return best_dest; }
	void setBestDest(Edge *best_dest) { this->best_dest = best_dest; }

	// Constants
	static const int UNEXPLORED_COST = INT_MAX;

protected:
	// Fields
	Station *station;
	int station_time;
	vector<Edge *> edges;
	bool visited;
	int best_cost;
	Edge *best_source;
	Edge *best_dest;

	UNCOPYABLE_CLASS(Node);
};

#endif //__NODE_H__