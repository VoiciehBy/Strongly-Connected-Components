#include <iostream>
#include <list>
#include <map>

#ifndef NODE_H
#define NODE_H

enum Color { WHITE, GRAY, BLACK };

struct node {
	int value;
	Color color;
	int discovery_time;
	int finish_time;

	node(int value = 0, Color color = WHITE,int discovery_time = 0, int finish_time = 0);
	node(const node&);

	node& operator=(const node& o);

	bool operator==(const node& o);
	bool operator<(const node& o);

	void print();
	void printLetter();
};

#endif // NODE_H