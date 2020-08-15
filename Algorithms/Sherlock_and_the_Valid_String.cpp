#include <bits/stdc++.h>

using namespace std;

// Complete the isValid function below.
string isValid(string s) 
{
    unordered_map<char,int> m;
    for(char c : s)
        m[c]++;
    map<int,int> m2;
    for(auto itr : m)
        m2[itr.second]++;
    if(m2.size() == 1)
        return "YES";
    if(m2.size() > 2)
        return "NO";
    auto a = m2.begin();
    auto b = --m2.end();
    if(a->first == 1 && a->second == 1)
        return "YES";
    if(b->first - a->first == 1 && b->second == 1)
        return "YES";
    return "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = isValid(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
