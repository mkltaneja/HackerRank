#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the timeConversion function below.
 */
string timeConversion(string s) 
{
    if((s[s.size()-2] == 'A' && stoi(s.substr(0,2)) != 12) || (s[s.size()-2] == 'P' && stoi(s.substr(0,2)) == 12))
        return s.substr(0,s.size()-2);
    int t = stoi(s.substr(0,2));
    t = (t+12) % 24;
    s[1] = t%10 + '0';
    t /= 10;
    s[0] = t + '0';
    return s.substr(0,s.size()-2);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
