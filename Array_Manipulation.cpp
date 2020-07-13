#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the arrayManipulation function below.

// Method 1 -> O(n*m)
// TLE
long arrayManipulation(int n, vector<vector<int>> queries)
{
    vector<long> z(n + 1, 0);
    for (int i = 0; i < queries.size(); i++)
    {
        int a = queries[i][0], b = queries[i][1], k = queries[i][2];
        for (int j = a; j <= b; j++)
            z[j] += k;
    }

    long maxi = INT_MIN;
    for (long i : z)
        maxi = max(maxi, i);

    return maxi;
}

// Method 2 -> O(n+m)
// AC
long arrayManipulation(int n, vector<vector<int>> queries)
{
    int m = queries.size();
    vector<long> sum(n + 2, 0);
    for (int i = 0; i < m; i++)
    {
        int a = queries[i][0], b = queries[i][1], k = queries[i][2];
        sum[a] += k;
        sum[b + 1] -= k;
    }

    // Converting into Prefix Sum Array and finding maximum

    long maxi = INT_MIN;
    for (int i = 1; i <= n + 1; i++)
    {
        sum[i] += sum[i - 1];
        maxi = max(maxi, sum[i]);
    }

    return maxi;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nm_temp;
    getline(cin, nm_temp);

    vector<string> nm = split_string(nm_temp);

    int n = stoi(nm[0]);

    int m = stoi(nm[1]);

    vector<vector<int>> queries(m);
    for (int i = 0; i < m; i++)
    {
        queries[i].resize(3);

        for (int j = 0; j < 3; j++)
        {
            cin >> queries[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    long result = arrayManipulation(n, queries);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string)
{
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [](const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ')
    {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos)
    {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
