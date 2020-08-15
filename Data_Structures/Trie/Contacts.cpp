#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the contacts function below.
 */

// Method 1 (by searching all wordEnds after find)
// TLE

class Trie
{
public:
    vector<Trie*> node;
    bool wordEnd;
    Trie()
    {
        this->node.assign(26, nullptr);
        wordEnd = false;
    }
};
Trie* t = new Trie();

void add(string s)
{
    Trie* curr = t;
    for (char c : s)
    {
        if (!curr->node[c - 'a'])
            curr->node[c - 'a'] = new Trie();
        curr = curr->node[c - 'a'];
    }
    curr->wordEnd = true;
}

int countwords(Trie* root)
{
    if (!root)
        return 0;
    int count = 0;
    if (root->wordEnd)
        count++;
    for (int i = 0; i < 26; i++)
        count += countwords(root->node[i]);
    return count;
}

int find(string s)
{
    Trie* curr = t;
    for (char c : s)
    {
        if (!curr->node[c - 'a'])
            return 0;
        curr = curr->node[c - 'a'];
    }
    return countwords(curr);
}

vector<int> contacts(vector<vector<string>> queries)
{
    vector<int> ans;
    for (vector<string> v : queries)
        if (v[0] == "add")
            add(v[1]);
        else
            ans.push_back(find(v[1]));
    return ans;
}

// OR

// Method 2 (adding size(count of all wordEnd's after the particular node) in Trie class)
// AC

class Trie
{
public:
    vector<Trie*> node;
    bool wordEnd;
    int size;
    Trie()
    {
        this->node.assign(26, nullptr);
        this->wordEnd = false;
        this->size = 0;
    }
};
Trie* t = new Trie();

void add(string s)
{
    Trie* curr = t;
    for (char c : s)
    {
        if (!curr->node[c - 'a'])
            curr->node[c - 'a'] = new Trie();
        curr = curr->node[c - 'a'];
        curr->size++;
    }
    curr->wordEnd = true;
}

int find(string s)
{
    Trie* curr = t;
    for (char c : s)
    {
        if (!curr->node[c - 'a'])
            return 0;
        curr = curr->node[c - 'a'];
    }
    return curr->size;
}

vector<int> contacts(vector<vector<string>> queries)
{
    vector<int> ans;
    for (vector<string> v : queries)
        if (v[0] == "add")
            add(v[1]);
        else
            ans.push_back(find(v[1]));
    return ans;
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int queries_rows;
    cin >> queries_rows;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<string>> queries(queries_rows);
    for (int queries_row_itr = 0; queries_row_itr < queries_rows; queries_row_itr++) {
        queries[queries_row_itr].resize(2);

        for (int queries_column_itr = 0; queries_column_itr < 2; queries_column_itr++) {
            cin >> queries[queries_row_itr][queries_column_itr];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    vector<int> result = contacts(queries);

    for (int result_itr = 0; result_itr < result.size(); result_itr++) {
        fout << result[result_itr];

        if (result_itr != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
