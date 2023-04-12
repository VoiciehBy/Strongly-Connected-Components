#include "utils.h"

graph* transpose_of(graph* g) {
	graph* gt = new graph(g);

	for (int i = 0; i < g->size; i++) {
		std::list<int>::iterator j;
		for (j = g->edges[i].begin(); j != g->edges[i].end(); ++j)
			gt->edges[*j].push_back(i);
	}

	return gt;
}

bool in(std::list<node> list, int x) {
	std::list<node>::iterator i = list.begin();
	while (i != list.end()) {
		if (*i == x)
			return true;
		i++;
	}
	return false;
}

void print(std::list<node> list)
{
	std::list<node>::iterator i = list.begin();
	while (i != list.end()) {
		std::cout << ' ';
		i->printLetter();
		i++;
	}
}

void dfs_visit(graph* g, int v, int& time) {
	time = time + 1;
	g->vertices[v].discovery_time = time;
	g->vertices[v].color = GRAY;
	std::list<int> tmp = g->edges[v];
	std::list<int>::iterator i = tmp.begin();
	while (i != tmp.end()) {
		if (g->vertices[*i].color == WHITE) {
			std::cout << char('a' + *i) << ' ';
			dfs_visit(g, *i, time);
		}
		i++;
	}
	g->vertices[v].color = BLACK;
	time = time + 1;
	g->vertices[v].finish_time = time;
}

void dfs(graph* g) {
	for (int i = 0; i < g->size; i++)
		g->vertices[i].color = WHITE;

	int time = 0;
	for (int i = 0; i < g->size; i++)
		if (g->vertices[i].color == WHITE)
			dfs_visit(g, g->vertices[i].value, time);
}

void writeToTheFile(std::string str)
{
	std::ofstream fptr;
	fptr.open("adjacency_list.csv");
	fptr << str;
	fptr.close();
}
