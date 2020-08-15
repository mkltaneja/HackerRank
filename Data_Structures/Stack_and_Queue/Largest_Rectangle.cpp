#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the largestRectangle function below.
long largestRectangle(vector<int> h)
{
    long l = 0, b = 0;
    long maxarea = 0;
    for (long unsigned int i=0; i<h.size(); i++)
    {
        long unsigned int e = i, s = i;
        l = h[i];
        while (++e < h.size() && l <= h[e])
        {
        }
        while (--s >= 0 && l <= h[s])
        {
        }
        b = e-s-1;
        maxarea = max(maxarea, l*b);
    }
    return maxarea;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string h_temp_temp;
    getline(cin, h_temp_temp);

    vector<string> h_temp = split_string(h_temp_temp);

    vector<int> h(n);

    for (int i = 0; i < n; i++) {
        int h_item = stoi(h_temp[i]);

        h[i] = h_item;
    }

    long result = largestRectangle(h);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [](const char &x, const char &y) {
        return x == y and x == ' ';
        });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}


// ///////////////////////////////////////OR///////////////////////////////////////////////////////////

// BY USING STACKS

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the largestRectangle function below.
long largestRectangle(vector<int> h)
{
    int n = h.size();
    vector<int> lb(n, 0), rb(n, 0);
    lb[0] = -1;
    stack<int> lbs, rbs;
    lbs.push(0);
    for (int i=1; i<n; i++)
    {
        while (!lbs.empty() && h[i] <= h[lbs.top()])
            lbs.pop();
        lb[i] = lbs.empty() ? -1 : lbs.top();
        lbs.push(i);
    }
    rb[n-1] = n;
    rbs.push(n);
    for (int i=n-2; i>=0; i--)
    {
        while (!rbs.empty() && h[i] <= h[rbs.top()])
            rbs.pop();
        rb[i] = rbs.empty() ? -1 : rbs.top();
        rbs.push(i);
    }

    int maxarea = 0;
    for (int i=0;i<n;i++)
        maxarea = max((rb[i]-lb[i]-1)*h[i], maxarea);

    return maxarea;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string h_temp_temp;
    getline(cin, h_temp_temp);

    vector<string> h_temp = split_string(h_temp_temp);

    vector<int> h(n);

    for (int i = 0; i < n; i++) {
        int h_item = stoi(h_temp[i]);

        h[i] = h_item;
    }

    long result = largestRectangle(h);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [](const char &x, const char &y) {
        return x == y and x == ' ';
        });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
