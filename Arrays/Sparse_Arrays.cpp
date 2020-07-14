#include <bits/stdc++.h>

using namespace std;

// Complete the matchingStrings function below.
vector<int> matchingStrings(vector<string> strings, vector<string> queries)
{
    vector<int> count(queries.size(), 0);
    for (int i = 0; i < queries.size(); i++)
        for (string s : strings)
            if (s == queries[i])
                count[i]++;
    return count;
}

// OR

vector<int> matchingStrings(vector<string> strings, vector<string> queries)
{
    unordered_map<string, int> s;
    for (string str : strings)
    {
        if (s.find(str) == s.end())
            s.insert({str, 1});
        else
            s[str]++;
    }
    vector<int> count(queries.size(), 0);
    for (int i = 0; i < queries.size(); i++)
        if (s.find(queries[i]) != s.end())
            count[i] += s[queries[i]];
    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int strings_count;
    cin >> strings_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> strings(strings_count);

    for (int i = 0; i < strings_count; i++)
    {
        string strings_item;
        getline(cin, strings_item);

        strings[i] = strings_item;
    }

    int queries_count;
    cin >> queries_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> queries(queries_count);

    for (int i = 0; i < queries_count; i++)
    {
        string queries_item;
        getline(cin, queries_item);

        queries[i] = queries_item;
    }

    vector<int> res = matchingStrings(strings, queries);

    for (int i = 0; i < res.size(); i++)
    {
        fout << res[i];

        if (i != res.size() - 1)
        {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

// DAY 11 (Subsets)=================================================

// by subsequence
void subset_rec(vector<int> &nums, int idx, vector<vector<int>> &ans, vector<int> sub)
{
    if (idx == nums.size())
    {
        ans.push_back(sub);
        return;
    }

    sub.push_back(nums[idx]);
    subset_rec(nums, idx + 1, ans, sub);
    sub.pop_back();
    subset_rec(nums, idx + 1, ans, sub);
}

vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> ans;
    subset_rec(nums, 0, ans, {});
    return ans;
}
