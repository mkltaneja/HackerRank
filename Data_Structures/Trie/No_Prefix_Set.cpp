#include <vector>
#include <iostream>
using namespace std;

class Trie
{
public:
    vector<Trie*> node;
    bool wordEnd;
    Trie()
    {
        this->node.assign(10, nullptr);
        this->wordEnd = false;
    }
};
Trie* t = new Trie();

bool addand_check(string s)
{
    Trie* curr = t;
    for (int i = 0; i < s.size(); i++)
    {
        int c = s[i];
        if (i == s.size()-1 && curr->node[c - 'a'])
        {
            cout<<"BAD SET\n"<<s<<endl;
            return false;
        }
        if (!curr->node[c - 'a'])
            curr->node[c - 'a'] = new Trie();
        curr = curr->node[c - 'a'];
        if (curr->wordEnd)
        {
            cout<<"BAD SET\n"<<s<<endl;
            return false;
        }
    }
    curr->wordEnd = true;
    return true;
}

int main()
{
    int n;
    cin>>n;
    while (n)
    {
        string s;
        cin>>s;
        if (!addand_check(s))
            break;
        n--;
    }
    if (n == 0)
        cout<<"GOOD SET\n";
    return 0;
}
