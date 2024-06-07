#include <iostream>
#include <list>
#include <stack>
using namespace std;

class Graph {
	int V;
	list<int>* adj;
	void fillOrder(int v, bool visited[],
				stack<int>& Stack);
	void DFSUtil(int v, bool visited[]);

public:
	Graph(int V);
	~Graph();
	void addEdge(int v, int w);
	void printSCCs();
	Graph getTranspose();
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}
Graph::~Graph()
{
	delete[] this->adj;
}

void Graph::DFSUtil(int v, bool visited[])
{
	visited[v] = true;
	cout << v << " ";

	list<int>::iterator i;

	for (i = adj[v].begin();
		i != adj[v].end(); ++i) {

		if (!visited[*i])
			DFSUtil(*i, visited);
	}
}

Graph Graph::getTranspose()
{
	Graph g(V);
	for (int v = 0; v < V; v++) {
		for (auto i = adj[v].begin();
			i != adj[v].end(); ++i) {
			g.adj[*i].push_back(v);
		}
	}
	return g;
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
}

void Graph::fillOrder(int v, bool visited[],
					stack<int>& Stack)
{
	visited[v] = true;

	list<int>::iterator i;

	for (i = adj[v].begin();
		i != adj[v].end(); ++i) {

		if (!visited[*i]) {
			fillOrder(*i, visited, Stack);
		}
	}

	Stack.push(v);
}

void Graph::printSCCs()
{
	stack<int> Stack;

	bool* visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;

	for (int i = 0; i < V; i++)
		if (visited[i] == false)
			fillOrder(i, visited, Stack);

	Graph gr = getTranspose();

	for (int i = 0; i < V; i++)
		visited[i] = false;

	while (Stack.empty() == false) {

		int v = Stack.top();
		Stack.pop();

		if (visited[v] == false) {
			gr.DFSUtil(v, visited);
			cout << endl;
		}
	}

	delete[] visited;
}

int main()
{
	// Given Graph
	Graph g(5);
	g.addEdge(1, 0);
	g.addEdge(0, 2);
	g.addEdge(2, 1);
	g.addEdge(0, 3);
	g.addEdge(3, 4);

	// Function Call to find the SCC
	// using Kosaraju's Algorithm
	g.printSCCs();

	return 0;
}
