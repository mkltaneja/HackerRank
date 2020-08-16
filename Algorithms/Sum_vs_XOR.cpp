#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

// Complete the sumXor function below.

unsigned long int pow(unsigned long int n, int x)
{
    unsigned long int ans = 1;
    while(x)
    {
        if(x & 1)
            ans *= n;
        n *= n;
        x >>= 1;
    }
    return ans;
}

unsigned long sumXor(unsigned long n) 
{
    unsigned long n1 = n;
    int zeros = 0;
    while(n1)
    {
        if((n1 & 1) == 0)
            zeros++;
        n1 >>= 1;
    }
    return pow(2,zeros);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    unsigned long n = stol(ltrim(rtrim(n_temp)));

    unsigned long result = sumXor(n);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
