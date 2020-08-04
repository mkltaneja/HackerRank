#include <stack>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// Method 1 (swapping both stacks at every dequeue and print front)
// TLE
class queue
{
    stack<int> a, b;

public:
    queue()
    {
    }

    void enqueue(int x)
    {
        a.push(x);
    }
    void dequeue()
    {
        while (!a.empty())
        {
            int front = a.top();
            a.pop();
            b.push(front);
        }
        b.pop();
        while (!b.empty())
        {
            int front = b.top();
            b.pop();
            a.push(front);
        }
    }
    int front()
    {

        while (!a.empty())
        {
            int front = a.top();
            a.pop();
            b.push(front);
        }
        int top = b.top();
        while (!b.empty())
        {
            int front = b.top();
            b.pop();
            a.push(front);
        }
        return top;
    }
};

int main()
{
    int q, t, x;
    cin >> q;
    queue que;
    while (q--)
    {
        cin >> t;
        if (t == 1)
        {
            cin >> x;
            que.enqueue(x);
        }
        else if (t == 2)
            que.dequeue();
        else if (t == 3)
            cout << que.front() << endl;
    }
    return 0;
}

// OR
// Method 2 (not swapping at every stage)
#include <stack>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class queue
{
    stack<int> a, b;

public:
    queue()
    {
    }

    void enqueue(int x)
    {
        a.push(x);
    }
    void dequeue()
    {
        if (b.empty())
        {
            while (!a.empty())
            {
                int front = a.top();
                a.pop();
                b.push(front);
            }
        }
        b.pop();
    }
    int front()
    {
        if (b.empty())
        {
            while (!a.empty())
            {
                int front = a.top();
                a.pop();
                b.push(front);
            }
        }
        return b.top();
    }
};

int main()
{
    int q, t, x;
    cin >> q;
    queue que;
    while (q--)
    {
        cin >> t;
        if (t == 1)
        {
            cin >> x;
            que.enqueue(x);
        }
        else if (t == 2)
            que.dequeue();
        else if (t == 3)
            cout << que.front() << endl;
    }
    return 0;
}
