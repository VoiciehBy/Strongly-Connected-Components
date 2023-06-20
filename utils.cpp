#include "utils.h"

graph* transpose_of(graph* g) {
	graph* gt = new graph(g);
	for (int i = 0; i < g->size; i++)
		for (std::list<int>::iterator j = g->edges[i].begin(); j != g->edges[i].end(); ++j)
			gt->edges[*j].push_back(i);
	return gt;
}

std::list<node> ll;

void dfs_visit(graph& g, int v, int& time, bool is_alt) {
	time += 1;
	g.vertices[v].discovery_time = time;
	g.vertices[v].color = GRAY;

	std::list<int> g_edges = g.edges[v];
	for (std::list<int>::iterator i = g_edges.begin(); i != g_edges.end(); i++) {
		if (g.vertices[*i].color == WHITE) {
			if (is_alt)
				ll.push_back(g.vertices[*i]);
			dfs_visit(g, *i, time);
		}
	}
	g.vertices[v].color = BLACK;
	time += 1;
	g.vertices[v].finish_time = time;
}

void dfs_visit_alt(graph& g, int v, int& time) {
	time += 1;
	g.vertices[v].discovery_time = time;
	g.vertices[v].color = GRAY;

	std::list<int> g_edges = g.edges[v];
	for (std::list<int>::iterator i = g_edges.begin(); i != g_edges.end(); i++) {
		if (g.vertices[*i].color == WHITE) {
			dfs_visit_alt(g, *i, time);
		}
	}
	g.vertices[v].color = BLACK;
	time += 1;
	g.vertices[v].finish_time = time;
}

std::list<node> dfs(graph& g) {
	int time = 0;
	int n = g.size;
	ll.clear();

	for (int i = 0; i < n; i++)
		g.vertices[i].color = WHITE;

	for (int i = 0; i < n; i++)
		if (g.vertices[i].color == WHITE)
			dfs_visit(g, g.vertices[i].value, time);

	return ll;
}

std::list<node> dfs_alt(graph& g, graph& gt, std::vector<int> finishing_times) {
	int time = 0, n = gt.size;
	std::vector<int>::iterator j;
	std::vector<int> discovery_times;

	ll.clear();
	std::sort(finishing_times.begin(), finishing_times.end(), std::greater_equal<int>());

	for (int i = 0; i < n; i++)
		gt.vertices[i].color = WHITE;

	j = finishing_times.begin();
	while (j != finishing_times.end())
		for (int i = 0; i < n; i++)
			if (g.vertices[i].finish_time == (*j)) {
				if (gt.vertices[i].color == WHITE)
					dfs_visit_alt(gt, gt.vertices[i].value, time);
				++j;
			}

	for (int i = 0; i < n; i++)
		discovery_times.push_back(gt.vertices[i].discovery_time);
	std::sort(discovery_times.begin(), discovery_times.end(), std::less_equal<int>());

	j = discovery_times.begin();
	while (j != discovery_times.end())
		for (int i = 0; i < n; i++)
			if (gt.vertices[i].discovery_time == (*j)) {
				ll.push_back(gt.vertices[i]);
				++j;
			}
	return ll;
}

std::list<node> kosaraju(graph* g) {
	int n = g->size;
	std::list<node> g_vertices, the_vertices, result;
	std::list<node>::iterator j;
	std::vector<int> finish_times;
	graph* gt;

	dfs(*g);
	for (int i = 0; i < n; i++)
		g_vertices.push_back(g->vertices[i]);
	gt = transpose_of(g);
	for (j = g_vertices.begin(); j != g_vertices.end(); ++j)
		finish_times.push_back((*j).finish_time);

	the_vertices = dfs_alt(*g, *gt, finish_times);
	for (j = the_vertices.begin(); j != the_vertices.end(); ++j)
		result.push_back((*j));
	delete gt;
	return result;
}

void writeToTheFile(std::string str)
{
	std::ofstream fptr;
	fptr.open("adjacency_list.csv");
	fptr << str;
	fptr.close();
}
