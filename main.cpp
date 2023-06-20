#include "graph.h"
#include "utils.h"
#include <iostream>

graph* create_graph(int n) {
	graph* g = new graph(n);
	g->addDirectedEdge(graph::letterToNumberMap['a'], graph::letterToNumberMap['b']);

	g->addDirectedEdge(graph::letterToNumberMap['b'], graph::letterToNumberMap['c']);
	g->addDirectedEdge(graph::letterToNumberMap['b'], graph::letterToNumberMap['f']);

	g->addDirectedEdge(graph::letterToNumberMap['c'], graph::letterToNumberMap['d']);
	g->addDirectedEdge(graph::letterToNumberMap['c'], graph::letterToNumberMap['g']);

	g->addDirectedEdge(graph::letterToNumberMap['d'], graph::letterToNumberMap['c']);
	g->addDirectedEdge(graph::letterToNumberMap['d'], graph::letterToNumberMap['h']);

	g->addDirectedEdge(graph::letterToNumberMap['e'], graph::letterToNumberMap['a']);

	g->addDirectedEdge(graph::letterToNumberMap['f'], graph::letterToNumberMap['j']);

	g->addDirectedEdge(graph::letterToNumberMap['g'], graph::letterToNumberMap['k']);

	g->addDirectedEdge(graph::letterToNumberMap['h'], graph::letterToNumberMap['l']);

	g->addDirectedEdge(graph::letterToNumberMap['i'], graph::letterToNumberMap['e']);

	g->addDirectedEdge(graph::letterToNumberMap['j'], graph::letterToNumberMap['n']);

	g->addDirectedEdge(graph::letterToNumberMap['k'], graph::letterToNumberMap['o']);

	g->addDirectedEdge(graph::letterToNumberMap['l'], graph::letterToNumberMap['p']);

	g->addDirectedEdge(graph::letterToNumberMap['m'], graph::letterToNumberMap['i']);

	g->addDirectedEdge(graph::letterToNumberMap['n'], graph::letterToNumberMap['q']);
	g->addDirectedEdge(graph::letterToNumberMap['n'], graph::letterToNumberMap['r']);

	g->addDirectedEdge(graph::letterToNumberMap['o'], graph::letterToNumberMap['s']);

	g->addDirectedEdge(graph::letterToNumberMap['p'], graph::letterToNumberMap['t']);

	g->addDirectedEdge(graph::letterToNumberMap['q'], graph::letterToNumberMap['m']);
	g->addDirectedEdge(graph::letterToNumberMap['q'], graph::letterToNumberMap['r']);

	g->addDirectedEdge(graph::letterToNumberMap['r'], graph::letterToNumberMap['s']);

	g->addDirectedEdge(graph::letterToNumberMap['s'], graph::letterToNumberMap['t']);
	g->addDirectedEdge(graph::letterToNumberMap['s'], graph::letterToNumberMap['r']);

	g->addDirectedEdge(graph::letterToNumberMap['t'], graph::letterToNumberMap['t']);
	return g;
}

graph* create_cormen_graph(int n) {
	graph* g = new graph(n);
	g->addDirectedEdge(graph::letterToNumberMap['a'], graph::letterToNumberMap['b']);

	g->addDirectedEdge(graph::letterToNumberMap['b'], graph::letterToNumberMap['c']);
	g->addDirectedEdge(graph::letterToNumberMap['b'], graph::letterToNumberMap['e']);
	g->addDirectedEdge(graph::letterToNumberMap['b'], graph::letterToNumberMap['f']);

	g->addDirectedEdge(graph::letterToNumberMap['c'], graph::letterToNumberMap['d']);
	g->addDirectedEdge(graph::letterToNumberMap['c'], graph::letterToNumberMap['g']);

	g->addDirectedEdge(graph::letterToNumberMap['d'], graph::letterToNumberMap['c']);
	g->addDirectedEdge(graph::letterToNumberMap['d'], graph::letterToNumberMap['h']);

	g->addDirectedEdge(graph::letterToNumberMap['e'], graph::letterToNumberMap['a']);
	g->addDirectedEdge(graph::letterToNumberMap['e'], graph::letterToNumberMap['f']);

	g->addDirectedEdge(graph::letterToNumberMap['f'], graph::letterToNumberMap['g']);

	g->addDirectedEdge(graph::letterToNumberMap['g'], graph::letterToNumberMap['f']);
	g->addDirectedEdge(graph::letterToNumberMap['g'], graph::letterToNumberMap['h']);

	g->addDirectedEdge(graph::letterToNumberMap['h'], graph::letterToNumberMap['h']);
	return g;
}

int main() {
	graph* g = create_graph(20);
	std::cout << "Strongly Connected Components of graph G:" << std::endl;
	std::list<node> result = kosaraju(g);
	std::list<node>::iterator j = result.begin();
	while (j != result.end()) {
		int d_0 = 0, d_1 = 0;
		if (j != result.begin()) {
			d_0 = (*j).discovery_time;
			j++;
			if (j == result.end())
				j--;
			else {
				d_1 = (*j).discovery_time;
				j--;
			}
		}
		(*j).printLetter();
		std::cout << ' ';
		if (d_1 - d_0 > 1)
			std::cout << std::endl;
		++j;
	}
	delete g;
	return 0;
}