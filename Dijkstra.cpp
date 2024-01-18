#include <iostream>
using namespace std;
#include <limits.h>
#define V 9

class DJK
{
    int dist[V],min,min_index;
    bool sptSet[V];
    public:
        int minDistance(int dist[],bool sptSet[]);
        void printSolution(int dist[]);
        void dijkstra(int graph[V][V],int src);
};

int DJK::minDistance(int dist[], bool sptSet[])
{
    min = INT_MAX;
 
    for (int v = 0; v < V; v++)
    {
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
    }
 
    return min_index;
}
 
void DJK::printSolution(int dist[])
{
    cout << "Vertex \t Distance from Source" << endl;
    for (int i = 0; i < V; i++)
        cout << i << " \t\t" << dist[i] << endl;
}
 
void DJK::dijkstra(int graph[V][V], int src)
{
 
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;
        
    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) 
    {
        
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;
        for (int v = 0; v < V; v++)
        {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
        }
    }
 
    printSolution(dist);
}
 
int main()
{
    int src;
    clock_t start= clock();
    DJK distfind;
    cout<<"\nEnter the source city:";
    cin>>src;
    int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

    distfind.dijkstra(graph, src);
    
    clock_t end=clock();
    double time=double(end-start)/double(CLOCKS_PER_SEC);
    cout<<"\nEXECUTION TIME :"<<fixed<<time;
 
    return 0;
}