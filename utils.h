#include "graph.h"
#include <list>
#include <algorithm>
#include <vector>
#include <fstream>

extern graph* transpose_of(graph* g);

extern void dfs_visit(graph& g, int v, int& time,bool is_alt=false);
extern void dfs_visit_alt(graph& g, int v, int& time);

extern std::list<node> dfs(graph& g);
extern std::list<node> dfs_alt(graph& g, graph& gt, std::vector<int> finishing_times);

extern std::list<node> kosaraju(graph* g);

extern void writeToTheFile(std::string str);