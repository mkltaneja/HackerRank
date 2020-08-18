#include <bits/stdc++.h>

using namespace std;

// Complete the powerSum function below.

int ways(int X, vector<int> &pw, int idx)
{
    if(X == 0)
        return 1;
    else if(X < 0)
        return 0;

    int count = 0;
    for(int i=idx; pw[i]<=X; i++)
        count += ways(X-pw[i], pw, i+1);
    return count;
}

int powerSum(int X, int N) 
{
    vector<int> power(X+1,0);
    for(int i=1; i<=X; i++)
        power[i] = (int)pow(i,N);
    return ways(X,power,1);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int X;
    cin >> X;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int N;
    cin >> N;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int result = powerSum(X, N);

    fout << result << "\n";

    fout.close();

    return 0;
}
