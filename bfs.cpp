#include<bits/stdc++.h>
using namespace std;

class Graph
{
        int V;
        list<int> * adj;
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
            adj[u].erase(i);
        }
        void BFS(int v)
        {
            bool *visited = new bool[V];
            for(int i=0;i<V;i++)
                visited[i] = false;
            list<int> queue;
            visited[v] = true;
            queue.push_back(v);
            list<int>::iterator i;
            while(!queue.empty())
            {
                v = queue.front();
                cout<<v<<" ";
                queue.pop_front();
                for(i = adj[v].begin();i!=adj[v].end();i++)
                {
                    if(!visited[*i])
                    {
                        visited[*i] = true;
                        queue.push_back(*i);
                    }
                }
            }
        }
      /*  void BFS()
        {
            bool *visited = new bool[V];
            for(int i=0;i<V;i++)
                visited[i] = false;
            for(i=0;i<V;i++)
                DFSUtil(i,visited);
        }*/
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
    cout << "Following is Breadth First Traversal"
            " (starting from vertex 2) \n";
    g.BFS(2);

    return 0;
}
