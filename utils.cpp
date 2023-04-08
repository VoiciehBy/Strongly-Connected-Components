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

std::list<node>dfs(graph* g, node* v) {
	std::stack<node> stack;
	std::list<node> path;
	std::list<node> was;
	node* n = v;

	stack.push(*n);
	path.push_back(*n);
	was.push_back(*n);

	while (!stack.empty()) {
		n = &stack.top();
		stack.pop();
		if (n->color == WHITE) {
			n->color = BLACK;
			std::list<int> tmp = g->edges[n->value];
			std::list<int>::iterator i = tmp.begin();
			while (i != tmp.end()) {
				if (!in(was, g->vertices[*i].value)) {
					stack.push(g->vertices[*i]);
					path.push_back(g->vertices[*i]);
					was.push_back(*n);
				}
				i++;
			}
		}
	}
	return path;
}

void dfs(graph* g) {
	for (int i = 0; i < g->size; i++) {
		node* v = new node(i);
		std::list<node> list = dfs(g, v);
		std::list<node>::iterator j = list.begin();
		while (j != list.end()) {
			j->printLetter();
			std::cout << ' ';
			j++;
		}
		std::cout << std::endl;
	}
}

void writeToTheFile(std::string str)
{
	std::ofstream fptr;
	fptr.open("adjacency_list.csv");
	fptr << str;
	fptr.close();
}
