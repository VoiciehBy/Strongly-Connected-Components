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

int main() {
	int n = 20;

	graph* g = create_graph(n);
	graph* gt = transpose_of(g);

	/*g->print();
	std::cout << std::endl << std::endl;
	std::cout << "transpose of G:" << std::endl;
	gt->print();*/

	writeToTheFile(g->printToStr());

	std::cout << "G:" << std::endl;
	dfs(g);

	std::cout << "transpose of G:" << std::endl;
	dfs(gt);
	delete g;
	delete gt;
	return 0;
}