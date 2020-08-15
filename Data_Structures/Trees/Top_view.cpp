#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
public:
    Node *insert(Node *root, int data)
    {
        if (root == NULL)
        {
            return new Node(data);
        }
        else
        {
            Node *cur;
            if (data <= root->data)
            {
                cur = insert(root->left, data);
                root->left = cur;
            }
            else
            {
                cur = insert(root->right, data);
                root->right = cur;
            }

            return root;
        }
    }

    /*
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

*/

    // without base case

    map<int, pair<int, int>> m; // <vlevel, <data, hlevel>>
    void verticalOrderNodes(Node *node, int vlevel, int hlevel)
    {
        // cout<<node->data<<endl;
        if (node->left)
        {
            if (m.find(vlevel - 1) == m.end() || hlevel + 1 < m[vlevel - 1].second)
                m[vlevel - 1] = {node->left->data, hlevel + 1};
            verticalOrderNodes(node->left, vlevel - 1, hlevel + 1);
        }
        if (node->right)
        {
            if (m.find(vlevel + 1) == m.end() || hlevel + 1 < m[vlevel + 1].second)
                m[vlevel + 1] = {node->right->data, hlevel + 1};
            verticalOrderNodes(node->right, vlevel + 1, hlevel + 1);
        }
    }

    void topView(Node *root)
    {
        if (root == nullptr)
            return;

        m.emplace(0, make_pair(root->data, 0));
        verticalOrderNodes(root, 0, 0);

        for (auto itr : m)
            cout << itr.second.first << " ";
    }
};

// OR
// with base case

map<int, pair<int, int>> m; // <vlevel, <data, hlevel>>
void verticalOrderNodes(Node *node, int vlevel, int hlevel)
{
    if (node == nullptr)
        return;

    if (m.find(vlevel) == m.end() || hlevel < m[vlevel].second)
        m[vlevel] = {node->data, hlevel};

    verticalOrderNodes(node->left, vlevel - 1, hlevel + 1);
    verticalOrderNodes(node->right, vlevel + 1, hlevel + 1);
}

void topView(Node *root)
{
    if (root == nullptr)
        return;

    verticalOrderNodes(root, 0, 0);

    for (auto itr : m)
        cout << itr.second.first << " ";
}

void topView(Node *root)
{
    queue<pair<Node *, int>> que; // <node, vlevel>
    que.push({root, 0});
    map<int, int> m; // <vlevel, data>

    while (!que.empty())
    {
        pair<Node *, int> rn = que.front();
        que.pop();
        if (m.find(rn.second) == m.end())
            m[rn.second] = rn.first->data;
        if (rn.first->left)
            que.push({rn.first->left, rn.second - 1});
        if (rn.first->right)
            que.push({rn.first->right, rn.second + 1});
    }

    for (auto itr : m)
        cout << itr.second << " ";
}

//End of Solution

int main()
{

    Solution myTree;
    Node *root = NULL;

    int t;
    int data;

    std::cin >> t;

    while (t-- > 0)
    {
        std::cin >> data;
        root = myTree.insert(root, data);
    }

    myTree.topView(root);
    return 0;
}
