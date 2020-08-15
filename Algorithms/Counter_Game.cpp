#include <bits/stdc++.h>

using namespace std;

// Complete the counterGame function below.

long ispow2(long n)
{
    long x = 1, xp = 1;
    while(x <= n)
    {
        xp = x;
        x *= 2;
    }
    return xp;
}

int countpow(long n)
{
    long x = 1, count = -1;
    while(x <= n)
    {
        count++;
        x *= 2;
    }
    return count;
}

string counterGame(long n) 
{
    int count = 0;
    while(1)
    {
        long x = ispow2(n);
        if(x == n)
        {
            count += countpow(n);
            break;
        }
        count++;
        n -= x;
    }
    return (count & 1) ? "Louise" : "Richard";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        long n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string result = counterGame(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
