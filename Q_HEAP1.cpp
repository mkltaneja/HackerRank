#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class heap
{
private:
    vector<int> arr;

public:
    int n;

    heap()
    {
        this->n = 0;
    }

    void upheapify(int ci)
    {
        int pi = (ci - 1) / 2;
        if (arr[pi] > arr[ci])
        {
            swap(arr[pi], arr[ci]);
            upheapify(pi);
        }
    }
    void downheapify(int pi)
    {
        int i = pi;
        int li = 2 * pi + 1;
        int ri = 2 * pi + 2;
        if (li < n && arr[li] < arr[i])
            i = li;
        if (ri < n && arr[ri] < arr[i])
            i = ri;
        if (i != pi)
        {
            swap(arr[i], arr[pi]);
            downheapify(i);
        }
    }

    void push(int x)
    {
        arr.push_back(x);
        n++;
        upheapify(n - 1);
    }
    void pop(int x)
    {
        // cout<<"Entered POP\n";
        queue<unsigned long long int> que;
        if (n == 0)
            return;
        que.push(0);
        while (!que.empty())
        {
            unsigned long long int i = que.front();
            que.pop();
            if (arr[i] == x)
            {
                // cout<<"Found x: "<<x<<"\n";
                swap(arr[i], arr[n - 1]);
                arr.pop_back();
                n--;
                downheapify(i);
                upheapify(i);
                return;
            }
            unsigned long long int li = 2 * i + 1;
            unsigned long long int ri = 2 * i + 2;
            if (li < n && arr[li] <= x)
                que.push(li);
            if (ri < n && arr[ri] <= x)
                que.push(ri);
        }
    }
    int getMin()
    {
        if (n == 0)
            return -1;
        return arr[0];
    }

    void display()
    {
        cout << "n = " << n << endl;
        for (int i : arr)
            cout << i << " ";
        cout << endl;
    }
};

int main()
{
    int q;
    cin >> q;
    heap minheap;
    while (q--)
    {
        // cout<<"q : "<<q<<endl;
        int op, x;
        cin >> op;
        if (op == 1)
        {
            cin >> x;
            // cout<<"PUSHED "<<x<<"\n";
            minheap.push(x);
        }
        if (op == 2)
        {
            cin >> x;
            // cout<<"POPPED "<<x<<"\n";
            minheap.pop(x);
        }
        if (op == 3)
            cout << minheap.getMin() << endl;
        // minheap.display();
        // cout<<endl;
    }

    return 0;
}
