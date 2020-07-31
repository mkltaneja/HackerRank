#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the componentsInGraph function below.
 */

int dfs(vector<vector<int>> &gp, vector<bool> &vis, int src)
{
    int count = 0;
    vis[src] = true;
    for (int e : gp[src])
        if (!vis[e])
            count += dfs(gp, vis, e);
    return count + 1;
}

vector<int> componentsInGraph(vector<vector<int>> gb)
{
    int n = gb.size();
    vector<vector<int>> graph(2 * n + 1, vector<int>());
    for (vector<int> e : gb)
    {
        graph[e[0]].push_back(e[1]);
        graph[e[1]].push_back(e[0]);
    }

    // for(int i=1;i<=2*n;i++)
    // {
    //     cout<<i<<" --> ";
    //     for(int e : graph[i])
    //         cout<<e<<" ";
    //     cout<<endl;
    // }

    vector<bool> vis(2 * n, false);

    int minvert = 2 * n;
    int maxvert = 2;
    for (int i = 1; i <= 2 * n; ++i)
    {
        if (!vis[i])
        {
            int count = dfs(graph, vis, i);
            if (count >= 2)
                minvert = min(count, minvert);
            maxvert = max(count, maxvert);
        }
    }
    return {minvert, maxvert};
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> edges(n, vector<int>(2, 0));
    for (int i = 0; i < n; i++)
        cin >> edges[i][0] >> edges[i][1];
    vector<int> result = componentsInGraph(edges);
    for (int i : result)
        cout << i << " ";

    return 0;
}
