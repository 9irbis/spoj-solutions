#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <queue>
using namespace std;

class Graph{
private:
    int V;
    vector<list<int>> adj;

public:
    Graph(int n): V(n), adj(n) {}
    void addEdge(int v, int w);
    void bfs(int start, vector<int>& distances);
    int longestPath();
};

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}

void Graph::bfs(int start, vector<int>& distances)
{
    vector<bool> visited(V);
    queue<pair<int,int>> Q;
    Q.push(make_pair(start, 0));
    while(!Q.empty())
    {
        int u = Q.front().first;
        int weight = Q.front().second;
        visited[u] = true;
        for(auto it=adj[u].begin(); it!=adj[u].end(); ++it)
        {
            if (!visited[*it])
            {
                Q.push(make_pair(*it, weight+1));
            }
        }
        distances[u] = weight;
        Q.pop();
    }
}

int Graph::longestPath()
{
    vector<int> distances(V);
    bfs(0, distances);
    int mx,idx;
    mx = idx = -1;
    for(int i=0; i<V; i++)
    {
        if (distances[i] > mx)
        {
            mx = distances[i];
            idx = i;
        }
    }
    bfs(idx, distances);
    return *max_element(distances.begin(), distances.end());
}

int main()
{
    int n;
    scanf("%d", &n);
    Graph g(n);
    for(int i=0; i<n-1; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        g.addEdge(a-1, b-1);
    }
    printf("%d\n", g.longestPath());
    return 0;
}

