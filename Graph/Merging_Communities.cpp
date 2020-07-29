#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// Method 1 -> using graph array
// TLE

int main()
{
    int n, q, i, j;
    cin >> n >> q;
    vector<int> comsize(n + 1, 1);
    vector<int> par(n + 1, 0);
    for (int i = 1; i <= n; ++i)
        par[i] = i;
    vector<vector<int>> graph(n + 1, vector<int>());
    while (q--)
    {
        char c;
        cin >> c;
        if (c == 'M')
        {
            cin >> i >> j;
            if (par[i] != par[j])
            {
                if (comsize[i] >= comsize[j])
                {
                    graph[par[i]].push_back(par[j]);
                    while (!graph[par[j]].empty())
                    {
                        graph[par[i]].push_back(graph[par[j]].front());
                        swap(graph[par[j]].front(), graph[par[j]].back());
                        graph[par[j]].pop_back();
                    }
                    comsize[par[i]] = graph[par[i]].size() + 1;
                    for (int child : graph[par[i]])
                    {
                        par[child] = par[i];
                        comsize[child] = comsize[par[i]];
                    }
                }
                else
                {
                    graph[par[j]].push_back(par[i]);
                    while (!graph[par[i]].empty())
                    {
                        graph[par[j]].push_back(graph[par[i]].front());
                        swap(graph[par[i]].front(), graph[par[i]].back());
                        graph[par[i]].pop_back();
                    }
                    comsize[par[j]] = graph[par[j]].size() + 1;
                    for (int child : graph[par[j]])
                    {
                        par[child] = par[j];
                        comsize[child] = comsize[par[j]];
                    }
                }
            }
        }
        else if (c == 'Q')
        {
            cin >> i;
            cout << comsize[i] << endl;
        }
    }
    return 0;
}

// OR

// Without using graph array
// AC

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int findpar(int child, vector<int> &par)
{
    if (par[child] == child)
        return child;
    return par[child] = findpar(par[child], par);
}

int main()
{
    int n, q, i, j;
    cin >> n >> q;
    vector<int> comsize(n + 1, 1);
    vector<int> par(n + 1, 0);
    for (int i = 1; i <= n; ++i)
        par[i] = i;
    while (q--)
    {
        char c;
        cin >> c;
        if (c == 'M')
        {
            cin >> i >> j;
            int pi = findpar(i, par);
            int pj = findpar(j, par);
            if (pi != pj)
            {
                if (comsize[pi] >= comsize[pj])
                {
                    par[pj] = pi;
                    comsize[pi] += comsize[pj];
                    comsize[pj] = comsize[pi];
                }
                else
                {
                    par[pi] = pj;
                    comsize[pj] += comsize[pi];
                    comsize[pi] = comsize[pj];
                }
            }
        }
        else if (c == 'Q')
        {
            cin >> i;
            cout << comsize[findpar(i, par)] << endl;
        }
    }
    return 0;
}
