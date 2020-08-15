#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the truckTour function below.
 */

// Method 1 (using queue) --> O(n^2)
// TLE
int truckTour(vector<vector<int>> petrolpumps)
{
    int n = petrolpumps.size();
    queue<pair<int, pair<int, int>>> que;   // <petrol,<index, size>>
    for (int i = 0; i < n; i++)
        if (petrolpumps[i][0] >= petrolpumps[i][1])
            que.push({ petrolpumps[i][0], { i, 1 } });

    while (!que.empty())
    {
        int idx = que.front().second.first;
        int size = que.front().second.second;
        int pet = que.front().first;
        que.pop();
        // cout<<idx<<" "<<size<<" "<<pet<<endl;

        int nidx = (idx + 1) % n;
        int npet = petrolpumps[nidx][0] + pet - petrolpumps[idx][1];

        if (size == n)
            return nidx;

        if (npet >= petrolpumps[nidx][1])
            que.push({ npet, { nidx, size+1 } });
    }
    return -1;
}

// Method 2 (naive method) --> O(n)
// AC

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> petrolpumps(n);
    for (int petrolpumps_row_itr = 0; petrolpumps_row_itr < n; petrolpumps_row_itr++) {
        petrolpumps[petrolpumps_row_itr].resize(2);

        for (int petrolpumps_column_itr = 0; petrolpumps_column_itr < 2; petrolpumps_column_itr++) {
            cin >> petrolpumps[petrolpumps_row_itr][petrolpumps_column_itr];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = truckTour(petrolpumps);

    fout << result << "\n";

    fout.close();

    return 0;
}
