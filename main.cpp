#include <vector>

#define INF 2147483647

using namespace std;

vector <int> dijkstra(vector < vector <int> > G, int s)
{
    int n = G.size();
    vector <int> d(n, INF);
    vector <bool> used(n, false);
    vector <int> way(n);

    d[s] = 0;
    way[s] = -1;
    int dm = INF;
    int in;
    for (int i = 0; i < n; i++)
    {
        dm = INF;
        for (int j = 0; j < n; j++)
            if (!used[j] && d[j] < dm)
            {
                dm = d[j];
                in = j;
            }
        used[in] = true;
        for (int j = 0; j < n; j++)
        {
            if (G[in][j] != -1)
            {
                if (d[j] > d[in] + G[in][j])
                {
                    d[j] = d[in] + G[in][j];
                    way[j] = in;
                }
            }
        }
    }
    return d;
}

