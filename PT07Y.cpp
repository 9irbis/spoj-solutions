#include <iostream>
#include <list>
#include <vector>
using namespace std;

class Graph{
private:
    int V;
    int nComponents;
    vector<list<int>> adj;
    bool isCyclicUtil(int start, vector<bool>& visited, int parent);
public:
    Graph(int n);
    void addEdge(int v, int w);
    bool isCyclic();
    bool isTree();
};

Graph::Graph(int n): V(n), nComponents(0), adj(V) {}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}

bool Graph::isCyclicUtil(int start, vector<bool>& visited, int parent)
{
    visited[start] = true;
    for(auto it=adj[start].begin(); it!=adj[start].end(); ++it)
    {
        if (!visited[*it])
        {
            if (isCyclicUtil(*it, visited, start))
                return true;
        }
        else if (*it != parent)
                return true;
    }
    return false;
}

bool Graph::isCyclic()
{
    vector<bool> visited(V);
    for(int u=0; u<V; u++)
    {
        if(!visited[u])
        {
            nComponents++;
            if (isCyclicUtil(u, visited, -1))
                return true;
        }
    }
    return false;
}

bool Graph::isTree()
{
    bool b = isCyclic();
    if (!b && nComponents == 1)
        return true;
    else
        return false;
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    Graph g(n);
    for(int i=0; i<m; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        g.addEdge(a-1, b-1);
    }
    if (g.isTree())
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
