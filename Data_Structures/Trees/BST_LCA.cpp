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

    /*The tree node has data, left child and right child 
class Node {
    int data;
    Node* left;
    Node* right;
};

*/

    vector<Node *> rootTo_nodePath(Node *node, int val)
    {
        if (node == nullptr)
            return {};
        if (node->data == val)
            return {node};
        if (val < node->data)
        {
            vector<Node *> larr = rootTo_nodePath(node->left, val);
            if (larr.size() > 0)
            {
                larr.push_back(node);
                return larr;
            }
        }
        else
        {
            vector<Node *> rarr = rootTo_nodePath(node->right, val);
            if (rarr.size() > 0)
            {
                rarr.push_back(node);
                return rarr;
            }
        }
        return {};
    }

    Node *lca(Node *root, int v1, int v2)
    {
        vector<Node *> path1 = rootTo_nodePath(root, v1);
        vector<Node *> path2 = rootTo_nodePath(root, v2);

        Node *lca = root;
        int i = path1.size() - 1;
        int j = path2.size() - 1;
        while (i >= 0 && j >= 0)
        {
            if (path1[i] != path2[j])
                break;
            lca = path1[i];
            i--, j--;
        }

        return lca;
        // Write your code here.
    }

}; //End of Solution

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

    int v1, v2;
    std::cin >> v1 >> v2;

    Node *ans = myTree.lca(root, v1, v2);

    std::cout << ans->data;

    return 0;
}
