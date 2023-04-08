#include <iostream>
#include <list>
#include <map>

#ifndef NODE_H
#define NODE_H

enum Color { WHITE, GRAY, BLACK };

struct node {
	int value;
	Color color;

	node(int value = 0, Color color = WHITE);
	node(const node&);

	node& operator=(const node& o);

	bool operator==(const node& o);
	bool operator<(const node& o);

	void print();
	void printLetter();
};

#endif // NODE_H