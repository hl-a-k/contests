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

// Constructor of class
Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}
Graph::~Graph()
{
	delete[] this->adj;
}

// Recursive function to print DFS
// starting from v
void Graph::DFSUtil(int v, bool visited[])
{
	// Mark the current node as
	// visited and print it
	visited[v] = true;
	cout << v << " ";

	// Recur for all the vertices
	// adjacent to this vertex
	list<int>::iterator i;

	// Traverse Adjacency List of node v
	for (i = adj[v].begin();
		i != adj[v].end(); ++i) {

		// If child node *i is unvisited
		if (!visited[*i])
			DFSUtil(*i, visited);
	}
}

// Function to get the transpose of
// the given graph
Graph Graph::getTranspose()
{
	Graph g(V);
	for (int v = 0; v < V; v++) {
		// Recur for all the vertices
		// adjacent to this vertex
		for (auto i = adj[v].begin();
			i != adj[v].end(); ++i) {
			// Add to adjacency list
			g.adj[*i].push_back(v);
		}
	}

	// Return the reversed graph
	return g;
}

// Function to add an Edge to the given
// graph
void Graph::addEdge(int v, int w)
{
	// Add w to v’s list
	adj[v].push_back(w);
}

// Function that fills stack with vertices
// in increasing order of finishing times
void Graph::fillOrder(int v, bool visited[],
					stack<int>& Stack)
{
	// Mark the current node as
	// visited and print it
	visited[v] = true;

	// Recur for all the vertices
	// adjacent to this vertex
	list<int>::iterator i;

	for (i = adj[v].begin();
		i != adj[v].end(); ++i) {

		// If child node *i is unvisited
		if (!visited[*i]) {
			fillOrder(*i, visited, Stack);
		}
	}

	// All vertices reachable from v
	// are processed by now, push v
	Stack.push(v);
}

// Function that finds and prints all
// strongly connected components
void Graph::printSCCs()
{
	stack<int> Stack;

	// Mark all the vertices as
	// not visited (For first DFS)
	bool* visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;

	// Fill vertices in stack according
	// to their finishing times
	for (int i = 0; i < V; i++)
		if (visited[i] == false)
			fillOrder(i, visited, Stack);

	// Create a reversed graph
	Graph gr = getTranspose();

	// Mark all the vertices as not
	// visited (For second DFS)
	for (int i = 0; i < V; i++)
		visited[i] = false;

	// Now process all vertices in
	// order defined by Stack
	while (Stack.empty() == false) {

		// Pop a vertex from stack
		int v = Stack.top();
		Stack.pop();

		// Print SCC of the popped vertex
		if (visited[v] == false) {
			gr.DFSUtil(v, visited);
			cout << endl;
		}
	}

	delete[] visited;
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
