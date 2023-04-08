#include <list>
#include "node.h"
#include "graph.h"
#include <stack>
#include <algorithm>
#include <fstream>

extern graph* transpose_of(graph* g);

extern bool in(std::list<node> list, int x);
extern void print(std::list<node> list);

extern std::list<node>dfs(graph* g, node* v);

extern void dfs(graph* g);

extern void writeToTheFile(std::string str);