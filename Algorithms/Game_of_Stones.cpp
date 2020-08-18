#include <bits/stdc++.h>

using namespace std;

// Complete the gameOfStones function below.

// Method 1 (by DP)
// O(n)
string gameOfStones(int n) 
{
    vector<int> dp(n+1,0);  // dp[n] == 0 or 1 --> 0 denotes second is winner and 1                                     denotes first as winner 
    dp[0] = 0, dp[1] = 0;
    for(int i = 2 ; i <= n ; i++)
    {
        int a = dp[i-2], b = INT_MAX, c = INT_MAX;
        if(i - 3 >= 0)
            b = dp[i-3];
        if(i - 5 >= 0)
            c = dp[i-5];
        dp[i] = (a == 0 || b == 0 || c == 0) ? 1 : 0;
    }
    return dp[n] == 0 ? "Second" : "First";
}

// Method 2 (observation --> pattern in dp -> 0 0 1 1 1 1 0 0 1 1 1 1 0 0.......)

string gameOfStones(int n) 
{
    return (n % 7 == 0 || n % 7 == 1) ? "Second" : "First";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string result = gameOfStones(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
