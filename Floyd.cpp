#include <iostream>
using namespace std;

class Floyd
{
    int i, j, k;

public:
    void floyds(int p[10][10], int n);
    int min(int a, int b);
    void print(int p[10][10], int vertices);
};

void Floyd::floyds(int p[10][10], int n)
{
    for (k = 1; k <= n; k++)
    {
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                if (i == j)
                    p[i][j] = 0;
                else
                    p[i][j] = min(p[i][j], p[i][k] + p[k][j]);
            }
        }
    }
}

int Floyd::min(int a, int b)
{
    if (a < b)
        return a;
    else
        return b;
}

void Floyd::print(int p[10][10], int vertices)
{
    for (int i = 1; i <= vertices; i++)
    {
        for (int j = 1; j <= vertices; j++)
        {
            cout << p[i][j] << "\t";
        }
        cout << "\n";
    }
}

int main()
{
    int p[10][10], u, v, w, vertices, edges, i, j;
    Floyd find;
    cout << "\nEnter the number of vertices:";
    cin >> vertices;
    cout << "\nEnter the number of edges:";
    cin >> edges;

    for (i = 1; i <= vertices; i++)
    {
        for (j = 1; j <= vertices; j++)
            p[i][j] = 999;
    }

    for (i = 1; i <= edges; i++)
    {
        cout << "\nEnter the end vertices of edge " << edges << " and its weight\n";
        cin >> u >> v >> w;
        p[u][v] = w;
    }

    cout << "\nMatrix of input data is\n";
    find.print(p, vertices);

    find.floyds(p, vertices);

    cout << "\nTransitive closure is\n";
    find.print(p, vertices);

    cout << "\nThe shortest paths are:\n";
    for (i = 1; i <= vertices; i++)
    {
        for (j = 1; j <= vertices; j++)
        {
            if (i != j)
            {
                cout << "\n <" << i << "," << j << "> =" << p[i][j];
            }
        }
    }
    return 0;
}