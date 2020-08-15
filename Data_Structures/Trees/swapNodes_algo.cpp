#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the swapNodes function below.
 */

class Node
{
public:
    Node *left;
    Node *right;
    int data;
    Node(int data)
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};
Node *root = new Node(1);

void printInorder(Node *node)
{
    if (node->left)
        printInorder(node->left);
    cout << node->data << " ";
    if (node->right)
        printInorder(node->right);
}

int constructTree(vector<vector<int>> &indexes)
{
    queue<pair<Node *, int>> que;
    int i = 0;
    que.push({root, i++});
    int level = 0;
    while (!que.empty())
    {
        int size = que.size();
        while (size--)
        {
            pair<Node *, int> rn = que.front();
            que.pop();
            if (indexes[rn.second][0] != -1)
            {
                rn.first->left = new Node(indexes[rn.second][0]);
                que.push({rn.first->left, i++});
            }
            if (indexes[rn.second][1] != -1)
            {
                rn.first->right = new Node(indexes[rn.second][1]);
                que.push({rn.first->right, i++});
            }
        }
        level++;
    }
    // printInorder(root);
    return level;
}

void swaplr(Node *&l, Node *&r)
{
    Node *temp = l;
    l = r;
    r = temp;
}

void swapAt(int l, int scount, Node *node)
{
    queue<Node *> que;
    que.push(node);

    int level = 1;
    int slevel = l;
    while (!que.empty())
    {
        if (scount == 0)
            return;
        bool fs = false;
        int size = que.size();
        while (size--)
        {
            Node *rn = que.front();
            que.pop();

            if (rn->left)
                que.push(rn->left);
            if (rn->right)
                que.push(rn->right);
            if (level == slevel)
            {
                fs = true;
                // Node* temp = rn->left;
                // rn->left = rn->right;
                // rn->right = temp;
                swaplr(rn->left, rn->right);
            }
        }
        level++;
        if (fs)
        {
            scount--;
            slevel += l;
        }
    }
}

vector<int> inorder(Node *node, vector<int> &inarr)
{
    if (node->left)
        inorder(node->left, inarr);
    inarr.push_back(node->data);
    if (node->right)
        inorder(node->right, inarr);
    return inarr;
}

vector<vector<int>> swapNodes(vector<vector<int>> indexes, vector<int> queries)
{
    int maxlevel = constructTree(indexes);
    // cout<<maxlevel<<endl;
    Node *node = root;
    // printInorder(node);
    vector<vector<int>> inorderarr;
    for (auto i = 0; i < queries.size(); i++)
    {
        int scount = maxlevel / queries[i];
        cout << scount << endl;
        swapAt(queries[i], scount, node);
        vector<int> arr;
        inorder(node, arr);
        inorderarr.push_back(arr);
    }
    return inorderarr;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> indexes(n);
    for (int indexes_row_itr = 0; indexes_row_itr < n; indexes_row_itr++)
    {
        indexes[indexes_row_itr].resize(2);

        for (int indexes_column_itr = 0; indexes_column_itr < 2; indexes_column_itr++)
        {
            cin >> indexes[indexes_row_itr][indexes_column_itr];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int queries_count;
    cin >> queries_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> queries(queries_count);

    for (int queries_itr = 0; queries_itr < queries_count; queries_itr++)
    {
        int queries_item;
        cin >> queries_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        queries[queries_itr] = queries_item;
    }

    vector<vector<int>> result = swapNodes(indexes, queries);

    for (int result_row_itr = 0; result_row_itr < result.size(); result_row_itr++)
    {
        for (int result_column_itr = 0; result_column_itr < result[result_row_itr].size(); result_column_itr++)
        {
            fout << result[result_row_itr][result_column_itr];

            if (result_column_itr != result[result_row_itr].size() - 1)
            {
                fout << " ";
            }
        }

        if (result_row_itr != result.size() - 1)
        {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
