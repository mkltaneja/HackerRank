#include <string>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    int t, q;
    string s = "";
    stack<string> ps;
    cin>>t;
    while (t--)
    {
        cin>>q;
        if (q == 1)
        {
            string str;
            cin>>str;
            ps.push(s);
            s += str;
            // cout<<q<<" "<<ps.top()<<" "<<s<<endl;
        }
        else if (q == 2)
        {
            int k;
            cin>>k;
            ps.push(s);
            s.erase(s.end()-k, s.end());
            // cout<<q<<" "<<ps.top()<<" "<<s<<endl;
        }
        else if (q == 3)
        {
            int k;
            cin>>k;
            cout<<s[k-1]<<endl;
        }
        else if (q == 4)
        {
            s = ps.top();
            ps.pop();
            // cout<<q<<" "<<ps.top()<<" "<<s<<endl;
        }
    }
    return 0;
}
