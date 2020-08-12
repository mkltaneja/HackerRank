#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the minimumAverage function below.
 */
unsigned long long minimumAverage(vector<vector<int>> customers)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> custlist;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> waitlist;

    for (vector<int> v : customers)
        custlist.push({v[0], v[1]});

    unsigned long long wait = 0, astart = custlist.top().first;

    while (!custlist.empty())
    {
        waitlist.push({custlist.top().second, custlist.top().first});
        custlist.pop();
        while (!waitlist.empty())
        {
            pair<int, int> top = waitlist.top();
            waitlist.pop();
            int cstart = top.second;
            int ptime = top.first;
            wait += astart - cstart + ptime;
            astart += ptime;

            while (!custlist.empty() && custlist.top().first <= astart)
            {
                waitlist.push({custlist.top().second, custlist.top().first});
                custlist.pop();
            }
        }
    }
    return wait / customers.size();
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> customers(n);
    for (int customers_row_itr = 0; customers_row_itr < n; customers_row_itr++)
    {
        customers[customers_row_itr].resize(2);

        for (int customers_column_itr = 0; customers_column_itr < 2; customers_column_itr++)
        {
            cin >> customers[customers_row_itr][customers_column_itr];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    unsigned long long int result = minimumAverage(customers);

    fout << result << "\n";

    fout.close();

    return 0;
}
