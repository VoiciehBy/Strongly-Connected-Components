#include "graph.h"

graph::graph(int size) {
	this->size = size;
	this->vertices = new node[this->size];
	for (int i = 0; i < this->size; i++)
		this->vertices[i].value = i;
	this->edges = new std::list<int>[this->size];
}

static std::map<char, int> getLetterToNumberMap() {
	static std::map<char, int> m;
	for (int i = 0; i < 20; i++) {
		char c = 'a' + i;
		m[c] = i;
	}
	return m;
}

std::map<char, int> graph::letterToNumberMap = getLetterToNumberMap();

graph::graph(graph* g) {
	this->size = g->size;
	this->vertices = new node[this->size];
	for (int i = 0; i < this->size; i++) {
		this->vertices[i].value = g->vertices[i].value;
	}

	this->edges = new std::list<int>[this->size];
}

void graph::addDirectedEdge(int v, int w) {
	edges[v].push_back(w);
	edges->sort();
}

void graph::print() {
	for (int i = 0; i < size; i++) {
		std::list<int>::iterator j = edges[i].begin();
		std::cout << char('a' + i) << ": ";
		for (; j != this->edges[i].end(); j++)
			std::cout << char('a' + *j) << ' ';
		std::cout << std::endl;
	}
}

std::string graph::printToStr() {
	std::string str = "";
	for (int i = 0; i < size; i++) {
		std::list<int>::iterator j = edges[i].begin();
		str += char('a' + i);
		str += ' ';
		for (; j != this->edges[i].end(); j++) {
			str += char('a' + *j);
			str += ' ';
		}
		str += "\n";
	}
	return str;
}

void graph::printVertices()
{
	for (int i = 0; i < this->size; i++)
		this->vertices[i].print();
}

graph::~graph() {
	delete[] vertices;
	delete[] edges;
}