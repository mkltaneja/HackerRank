#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the downToZero function below.
 */

 // Method 1 (using DP) --> O(n*sqrt(n))
 // TLE

void operations(int n, vector<int> &dp)
{
    for (int n=2;n<dp.size();n++)
    {
        dp[n] = dp[n-1] + 1;
        for (int i=sqrt(n);i>=2;i--)
        {
            if (n % i == 0)
            {
                dp[n] = min(dp[n], dp[n/i]+1);
            }
        }
    }
}

int downToZero(int n)
{
    vector<int> dp(n+1, 0);
    dp[1] = 1;
    operations(n, dp);
    return dp[n];
}

// OR

// Method 2 (using DP) --> O(n*logn)
// TLE
void operations(int N, vector<int> &dp)
{
    for (int n=2;n<dp.size();n++)
    {
        dp[n] = min(dp[n], dp[n-1] + 1);
        for (int j = 1; j <= n && n*j <= N; j++)
            dp[n*j] = min(dp[n*j], dp[n]+1);
    }
}

int downToZero(int n)
{
    vector<int> dp(n+1, INT_MAX);
    dp[1] = 1;
    operations(n, dp);
    return dp[n];
}

// Method 3 (using queue and map - level wise)
// TLE

int downToZero(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    queue<int> que;
    que.push(n);
    unordered_map<int, bool> m;
    m[n] = true;

    int level = 0;
    while (!que.empty())
    {
        int size = que.size();
        while (size--)
        {
            int top = que.front();
            que.pop();
            if (top == 2)
                return level + 2;

            if (!m[top-1])
                que.push(top-1);

            for (int i = 2; i*i <= top; i++)
            {
                if (top % i == 0)
                {
                    int gfac = top / i;
                    if (!m[gfac])
                        que.push(gfac);
                }
            }
        }
        level++;
    }
    return 0;
}

// Method 4 (using queue and array)
// AC

int downToZero(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    vector<int> dist(n+1, 0);
    dist[n] = 1;
    queue<int> que;
    que.push(n);
    while (!que.empty())
    {
        int top = que.front();
        que.pop();
        if (top == 2)
            return dist[top] + 1;
        if (dist[top - 1] == 0)
        {
            dist[top-1] = dist[top] + 1;
            que.push(top-1);
        }

        for (int i = 2; i*i <= top; i++)
        {
            if (top % i == 0)
            {
                int gfac = top / i;
                if (dist[gfac] == 0)
                {
                    dist[gfac] = dist[top] + 1;
                    que.push(gfac);
                }
            }
        }
    }
    return 0;
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int result = downToZero(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
