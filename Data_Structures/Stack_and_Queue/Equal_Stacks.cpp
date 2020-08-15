#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

/*
 * Complete the equalStacks function below.
 */

// Method 1
int equalStacks(vector<int> h1, vector<int> h2, vector<int> h3)
{
    reverse(h1.begin(), h1.end());
    reverse(h2.begin(), h2.end());
    reverse(h3.begin(), h3.end());
    vector<int> psum1(h1.size(), 0), psum2(h2.size(), 0), psum3(h3.size(), 0);
    psum1[0] = h1[0], psum2[0] = h2[0], psum3[0] = h3[0];
    for (unsigned long int i = 1; i < h1.size(); i++)
        psum1[i] = psum1[i - 1] + h1[i];
    for (unsigned long int i = 1; i < h2.size(); i++)
        psum2[i] = psum2[i - 1] + h2[i];
    for (unsigned long int i = 1; i < h3.size(); i++)
        psum3[i] = psum3[i - 1] + h3[i];

    // for (int i : psum1)
    //     cout << i << " ";
    // cout << endl;
    // for (int i : psum2)
    //     cout << i << " ";
    // cout << endl;
    // for (int i : psum3)
    //     cout << i << " ";
    // cout << endl;

    int mini = min(psum1.back(), min(psum2.back(), psum3.back()));
    // cout<<psum1.back()<<" "<<psum2.back()<<" "<<psum3.back()<<endl;
    while (!psum1.empty() && !psum2.empty() && !psum3.empty() && (psum1.back() != mini || psum2.back() != mini || psum3.back() != mini))
    {
        // cout<<psum1.back()<<" "<<psum2.back()<<" "<<psum3.back()<<endl;
        if (psum1.back() > mini)
            psum1.pop_back();
        if (psum2.back() > mini)
            psum2.pop_back();
        if (psum3.back() > mini)
            psum3.pop_back();

        if (psum1.back() < mini)
            mini = psum1.back();
        if (psum2.back() < mini)
            mini = psum2.back();
        if (psum3.back() < mini)
            mini = psum3.back();
    }

    return mini;
}

// OR

// Method 2
// USING MAP
int equalStacks(vector<int> h1, vector<int> h2, vector<int> h3)
{
    reverse(h1.begin(), h1.end());
    reverse(h2.begin(), h2.end());
    reverse(h3.begin(), h3.end());

    unordered_map<int, int> m;
    for (int i = 0; i < 3; ++i)
    {
        const vector<int> &v = i == 0 ? h1 : i == 1 ? h2 : h3;

        int sum = 0;
        for (int i : v)
        {
            sum += i;
            ++m[sum];
        }
    }

    int maxh = 0;
    for (auto itr : m)
        if (itr.second == 3)
            maxh = max(maxh, itr.first);
    return maxh;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n1N2N3_temp;
    getline(cin, n1N2N3_temp);

    vector<string> n1N2N3 = split_string(n1N2N3_temp);

    int n1 = stoi(n1N2N3[0]);

    int n2 = stoi(n1N2N3[1]);

    int n3 = stoi(n1N2N3[2]);

    string h1_temp_temp;
    getline(cin, h1_temp_temp);

    vector<string> h1_temp = split_string(h1_temp_temp);

    vector<int> h1(n1);

    for (int h1_itr = 0; h1_itr < n1; h1_itr++)
    {
        int h1_item = stoi(h1_temp[h1_itr]);

        h1[h1_itr] = h1_item;
    }

    string h2_temp_temp;
    getline(cin, h2_temp_temp);

    vector<string> h2_temp = split_string(h2_temp_temp);

    vector<int> h2(n2);

    for (int h2_itr = 0; h2_itr < n2; h2_itr++)
    {
        int h2_item = stoi(h2_temp[h2_itr]);

        h2[h2_itr] = h2_item;
    }

    string h3_temp_temp;
    getline(cin, h3_temp_temp);

    vector<string> h3_temp = split_string(h3_temp_temp);

    vector<int> h3(n3);

    for (int h3_itr = 0; h3_itr < n3; h3_itr++)
    {
        int h3_item = stoi(h3_temp[h3_itr]);

        h3[h3_itr] = h3_item;
    }

    int result = equalStacks(h1, h2, h3);

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