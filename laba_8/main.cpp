#include <QCoreApplication>
#include <iostream>
#include <list>
#include <vector>
void Depth_First_Search(int n, int **Graph,
                                         bool *Visited, int Node){
    Visited[Node] = true;
    std::cout << Node + 1 << std::endl;
    for (int i = 0 ; i < n ; i++)
         if (Graph[Node][i] && !Visited[i])
                  Depth_First_Search(n,Graph,Visited,i);
}




class Graph
{
    int V;
    std::list<int> *adj;
    void DFSUtil(int v, bool visited[]);
public:
    Graph(int V);
    void addEdge(int v, int w);
    void DFS(int v);
    void BFS(int s);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new std::list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}

void Graph::DFSUtil(int v, bool visited[])
{

    visited[v] = true;
    std::cout << v << " ";

    std::list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFSUtil(*i, visited);
}

void Graph::DFS(int v)
{
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
    DFSUtil(v, visited);
}

void Graph::BFS(int s)
{
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;

    std::list<int> queue;

    visited[s] = true;
    queue.push_back(s);

    std::list<int>::iterator i;

    while(!queue.empty())
    {
        s = queue.front();
        std::cout << s << " ";
        queue.pop_front();

        for (i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Graph g(7);
    g.addEdge(0,4);
    g.addEdge(0,5);
    g.addEdge(1,5);
    g.addEdge(1,6);
    g.addEdge(2,3);
    g.addEdge(2,4);
    g.addEdge(2,5);
    g.addEdge(3,2);
    g.addEdge(3,6);
    g.addEdge(4,0);
    g.addEdge(4,2);
    g.addEdge(5,0);
    g.addEdge(5,1);
    g.addEdge(5,2);
    g.addEdge(6,1);
    g.addEdge(6,3);







    g.DFS(5);
    std::cout << std::endl;
    g.BFS(5);



    return a.exec();
}
