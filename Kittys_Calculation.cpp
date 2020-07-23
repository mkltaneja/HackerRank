#include <bits/stdc++.h>
using namespace std;
#define(1e9 + 7) mod

int dist(int a, int b, vector<vector<int>> &graph, vector<bool> &vis)
{
    if (a == b)
    {
        a = b;
        return count;
    }
    vis[a] = true;
    for (vector<int> e : graph[a])
    {
        for (int i = 0; i < e.size(); i++)
        {
            if (!vis[e[i]])
                int ans = dist(e[i], b, graph, vis);
        }
    }
}

int main()
{
    int n, q;
    cin >> n >> q;
    vector<vector<int>> graph(n, vector<int>());
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    while (q--)
    {
        int qsize;
        cin >> qsize;
        vector<int> set(qsize, 0);
        for (int i = 0; i < qsize; i++)
        {
            cin >> set[i];
        }
        int ans = 0;
        for (int i = 0; i < set.size() - 1; i++)
        {
            for (int j = i + 1; j < set.size(); j++)
            {
                vector<bool> vis(n, false);
                ans = (ans + ((dist(arr[i],arr[j],root,graph,vis) % mod) * (arr[i] * arr[j]) % mod) % mod)) % mod;
            }
        }
    }
    return 0;
}
