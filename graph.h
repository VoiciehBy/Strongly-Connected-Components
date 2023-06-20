#include "node.h"
#include <list>
#include <map>
#include <iostream>

#ifndef GRAPH_H
#define GRAPH_H

struct graph {
	int size;
	node* vertices;
	std::list<int>* edges;
	static std::map<char, int> letterToNumberMap;

	graph(int size);
	graph(graph* g);

	void addDirectedEdge(int v, int w);

	void print();
	std::string printToStr();
	void printVertices();
	~graph();
};

#endif // GRAPH_H