#include <bits/stdc++.h>

using namespace std;

// METHOD 1 --> naive approach  -> TLE

vector<string> split_string(string);

// Complete the poisonousPlants function below.
int poisonousPlants(vector<int> p)
{
    int d = 0;
    bool flag = true;
    while (flag)
    {
        long unsigned int size = p.size();
        vector<int> toerase;
        for (long unsigned int i=1;i<p.size();i++)
            if (p[i-1] < p[i])
                toerase.push_back(i);
        int e = 0;
        for (int i : toerase)
            p.erase(p.begin()+i-e++);
        if (p.size() == size)
            flag = false;
        else
            d++;
        // cout<<p.size()<<" "<<size<<endl;
    }
    return d;
}

// OR  ->  (BY USING STACKS)

int poisonousPlants(vector<int> p)
{
    int minp = p[0], maxd = 0;
    vector<int> days(p.size(), 0);
    stack<int> st;
    st.push(0);
    for (unsigned long int i=1;i<p.size();i++)
    {
        if (p[i] > p[i-1])
            days[i] = 1;

        minp = min(minp, p[i]);
        while (!st.empty() && p[i] <= p[st.top()])
        {
            if (p[i] > minp)
                days[i] = max(days[i], days[st.top()] + 1);
            st.pop();
        }
        maxd = max(days[i], maxd);
        st.push(i);
    }
    return maxd;
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string p_temp_temp;
    getline(cin, p_temp_temp);

    vector<string> p_temp = split_string(p_temp_temp);

    vector<int> p(n);

    for (int i = 0; i < n; i++) {
        int p_item = stoi(p_temp[i]);

        p[i] = p_item;
    }

    int result = poisonousPlants(p);

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
