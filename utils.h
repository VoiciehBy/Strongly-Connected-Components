#include <list>
#include "node.h"
#include "graph.h"
#include <stack>
#include <queue>
#include <algorithm>
#include <vector>
#include <fstream>

extern graph* transpose_of(graph* g);

extern bool in(std::list<node> list, int x);
extern void print(std::list<node> list);

extern void dfs_visit(graph* g, int v, int& time);

extern void dfs(graph* g);

extern void writeToTheFile(std::string str);