#include<bits/stdc++.h>
using namespace std;

class Graph
{
        int V;
        list<int> * adj;
        void DFSUtil(int v, bool visited[])
        {
           visited[v] = true;
           cout<<v<<" ";
           list<int>::iterator i;
           for(i=adj[v].begin(); i!=adj[v].end();i++)
           {
               if(!visited[*i])
                    DFSUtil(*i,visited);
           }
        }
    public:
        Graph(int V)
        {
            this->V = V;
            this->adj = new list<int>[V];
        }
        void addEdge(int u, int v)
        {
            adj[u].push_back(v);
        }
        void removeEdge(int u ,int v)
        {
            list<int>::iterator i;
            i = find(adj[u].begin(),adj[u].end(),v);
            adj[u].erase[i];
        }
        void DFS(int v)
        {
            bool *visited = new bool[V];
            for(int i=0;i<V;i++)
                visited[i] = false;
            DFSUtil(v,visited);
        }
        void DFS()
        {
            bool *visited = new bool[V];
            for(int i=0;i<V;i++)
                visited[i] = false;
            for(i=0;i<V;i++)
                DFSUtil(i,visited);
        }
};

int main()
{
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,2);
    g.addEdge(2,0);
    g.addEdge(2,3);
    g.addEdge(3,3);
    cout << "Following is Depth First Traversal"
            " (starting from vertex 2) \n";
    g.DFS(2);

    return 0;
}
