#include <vector>
#include <iostream>
using namespace std;

int main()
{
    int n, m, q, si, ei;
    cin >> n >> m;
    vector<int> arr(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    while (m--)
    {
        cin >> q >> si >> ei;

// Method 1 (by taking a temporary vector and storing the values in it)

        vector<int> temp(1, 0);
        if (q == 1)
        {
            temp.insert(temp.end(), arr.begin() + si, arr.begin() + ei + 1);
            for (int i = 1; i <= n; i++)
                if (i < si || i > ei)
                    temp.push_back(arr[i]);
            // cout<<si<<" "<<ei<<endl;
            // for(int i : temp)
            //     cout<<i<<" ";
            // cout<<endl;
        }
        else
        {
            for (int i = 1; i <= n; i++)
                if (i < si || i > ei)
                    temp.push_back(arr[i]);
            temp.insert(temp.end(), arr.begin() + si, arr.begin() + ei + 1);
            // for(int i : temp)
            //     cout<<i<<" ";
            // cout<<endl;
        }
        arr = temp;
    }
    cout << abs(arr[1] - arr[n]) << endl;
    for (int i = 1; i <= n; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}
