#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the runningMedian function below.
 */

// Method 1 (naive approach)
// AC

vector<double> runningMedian(vector<int> a)
{
    vector<double> med(a.size(), 0);
    for (int i = 0; i < a.size(); i++)
    {
        sort(a.begin(), a.begin() + i + 1);
        int midx = i / 2;
        int midx1 = (i + 1) / 2;
        if (i & 1)
            med[i] = (a[midx] + a[midx1]) / 2.0;
        else
            med[i] = 1.0 * a[midx];
    }
    return med;
}

// OR

// Method 2 (using heaps)
// AC

vector<double> runningMedian(vector<int> a)
{
    // for(int i=0;i<a.size();i++)
    //     cout<<(double)a[i]<<" ";
    // cout<<endl;
    if (a.size() == 1)
        return {a[0]};
    priority_queue<int, vector<int>, greater<int>> minpq;
    priority_queue<int> maxpq;

    minpq.push(max(a[0], a[1]));
    maxpq.push(min(a[0], a[1]));

    vector<double> med(a.size(), 0);
    med[0] = a[0];
    med[1] = (a[0] + a[1]) / 2.0;

    double m = med[1];
    for (int i = 2; i < a.size(); i++)
    {
        if (a[i] <= m)
            maxpq.push(a[i]);
        else
            minpq.push(a[i]);

        int szdiff = maxpq.size() - minpq.size();
        if (szdiff < -1)
        {
            maxpq.push(minpq.top());
            minpq.pop();
        }
        else if (szdiff > 1)
        {
            minpq.push(maxpq.top());
            maxpq.pop();
        }
        int lmed = maxpq.top();
        int umed = minpq.top();

        if (minpq.size() == maxpq.size())
            med[i] = (lmed + umed) / 2.0;
        else if (minpq.size() > maxpq.size())
            med[i] = umed;
        else
            med[i] = lmed;

        m = med[i];
    }
    return med;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int a_count;
    cin >> a_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> a(a_count);

    for (int a_itr = 0; a_itr < a_count; a_itr++)
    {
        int a_item;
        cin >> a_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        a[a_itr] = a_item;
    }

    vector<double> result = runningMedian(a);

    for (int result_itr = 0; result_itr < result.size(); result_itr++)
    {
        fout << result[result_itr];

        if (result_itr != result.size() - 1)
        {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
