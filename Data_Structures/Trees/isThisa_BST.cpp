
bool checkleft(Node *node, int data)
{
    if (node == nullptr)
        return true;
    if (node->data >= data)
        return false;
    return checkleft(node->left, data) && checkleft(node->right, data);
}

bool checkright(Node *node, int data)
{
    if (node == nullptr)
        return true;
    if (node->data <= data)
        return false;
    return checkright(node->left, data) && checkright(node->right, data);
}

bool checkBST(Node *root)
{
    if (root == nullptr)
        return true;
    if (checkleft(root->left, root->data) && checkright(root->right, root->data) == 0)
        return false;
    return checkBST(root->left) && checkBST(root->right);
}

// OR

// by checking if inorder array is sorted or not
vector<int> inorder(Node *node, vector<int> &arr)
{
    if (node == nullptr)
        return {};
    inorder(node->left, arr);
    arr.push_back(node->data);
    inorder(node->right, arr);
    return arr;
}

bool checkBST(Node *root)
{
    vector<int> inodr;
    inorder(root, inodr);
    for (int i = 0; i < inodr.size() - 1; i++)
        if (inodr[i + 1] <= inodr[i])
            return false;
    // for(int i : inodr)
    //     cout<<i<<" ";
    return true;
}