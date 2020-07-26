#include <climits>
#include <vector>
#include <iostream>
using namespace std;

class stack
{
public:
    int n;
    vector<pair<int, int>> arr;
    stack()
    {
        n = 0;
    }
    void push(int x)
    {
        int max;
        if (n != 0)
            max = arr[n - 1].second;
        if ((n == 0) || ((n != 0) && (x > max)))
        {
            arr.push_back({x, x});
        }
        else
            arr.push_back({x, max});
        n++;
    }
    void pop()
    {
        arr.pop_back();
        n--;
    }
    int getMax()
    {
        return (n == 0) ? INT_MAX : arr[n - 1].second;
    }

    void display()
    {
        cout << n << endl;
        for (pair<int, int> i : arr)
            cout << i.first << " " << i.second << "  ";
        cout << endl;
    }
};

int main()
{
    int N, q, x;
    cin >> N;
    stack st;
    while (N--)
    {
        cin >> q;
        if (q == 1)
        {
            cin >> x;
            st.push(x);
        }
        else if (q == 2)
            st.pop();
        else
            cout << st.getMax() << endl;
        // st.display();
    }
    return 0;
}
