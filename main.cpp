#include <bits/stdc++.h>

using namespace std;
class Graph
{
	int V;
	vector<int> *edgs;
	bool *visited;

	void dfs1(int v, stack<int> &S);
	void dfs2(int v, stack<int> &componet);


public:
	Graph(int V);
	~Graph();
	void addEdge(int f, int t);
	void initVisited();
	void printSCCs();
	Graph transfer();
};

void Graph::dfs1(int v, stack<int> &S)
{
	this->visited[v] = true;

	for (auto j = this->edgs[v].begin(); j != this->edgs[v].end(); j++)
	{
		if (!this->visited[*j])
		{
			dfs1(*j, S);
		}
	}

	S.push(v);
}

void Graph::dfs2(int v, stack<int> &componet)
{
	this->visited[v] = true;

	for (auto j = this->edgs[v].begin(); j != this->edgs[v].end(); j++)
	{
		if (!this->visited[*j])
		{
			dfs2(*j, componet);
		}
	}

	componet.push(v);
}

Graph::Graph(int V)
{
	this->V = V;
	this->edgs = new vector<int>[V];
	this->visited = new bool[V];
}

Graph::~Graph()
{
	delete[] this->edgs;
	delete[] this->visited;
}

Graph Graph::transfer() {
	Graph g(this->V);
	for(int i=0; i<this->V; i++) {
		for(auto j=edgs[i].begin(); j!= edgs[i].end(); j++) {
			g.addEdge(*j, i);
		}
	}

	return g;
}

void Graph::addEdge(int f, int t)
{
	this->edgs[f].push_back(t);
}

void Graph::initVisited()
{
	memset(this->visited, false, this->V);
}

void Graph::printSCCs()
{
	stack<int> S;
	this->initVisited();
	for (int i = 0; i < this->V; i++)
	{
		if (!this->visited[i])
		{
			dfs1(i, S);
		}
	}
	Graph tg = this->transfer();
	tg.initVisited();
	while (!S.empty())
	{
		if (!tg.visited[S.top()])
		{
			stack<int> component;
			tg.dfs2(S.top(), component);
			while(!component.empty()) {
				cout << component.top() << " ";
				component.pop();
			}
			cout << endl;
		}

		S.pop();
	}
}

// Driver Code
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
