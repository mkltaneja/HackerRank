/* Node is defined as :
typedef struct node
{
    int val;
    struct node* left;
    struct node* right;
    int ht;
} node; */

void update_height(node* nod)
{
    int lh = -1, rh = -1;
    nod->ht = max(lh, rh) + 1;
}

node* llrot(node* nod)
{
    node* l = nod->left;
    node* lr = l->right;
    l->right = nod;
    nod->left = lr;
    update_height(l);
    update_height(nod);
    
    return l;
}
node* rrrot(node* nod)
{
    node* r = nod->right;
    node* rl = r->left;
    r->left = nod;
    nod->right = rl;
    update_height(r);
    update_height(nod);

    return r;
}

node* checkBF(node* nod)
{
    int lh = -1, rh = -1;
    if(nod->left)
        lh = nod->left->ht;
    if(nod->right)
        rh = nod->right->ht;
    int BF = lh - rh;
    
    // if(BF <= 1 && BF >= -1)
    //     return nod;
    
    if(BF == 2)  // ll or lr
    {
        node* l = nod->left;
        int lhl = -1, rhl = -1;
        if(l->left)
            lhl = l->left->ht;
        if(l->right)
            rhl = l->right->ht;
        int bfl = lhl - rhl;
        if(bfl == -1)
            return llrot(nod);
        else
        {
            nod->left = rrrot(nod->left);
            return llrot(nod);
        }
    }
    else if(BF == -2) //rr or rl
    {
        node* r = nod->right;
        int lhr = -1, rhr = -1;
        if(r->left)
            lhr = r->left->ht;
        if(r->right)
            rhr = r->right->ht;
        int bfr = lhr - rhr;
        
        if(bfr == 1)
            return rrrot(nod);
        else
        {
            nod->right = llrot(nod->right);
            return rrrot(nod);
        }
    }
    return nod;
}

node * dup_insert(node * root,int val)
{
    if(root == nullptr)
    {
        node* nod = new node();
        nod->val = val;
        nod->ht = 0;
        return nod;
    }
    if(val < root->val)
    {
        root->left = dup_insert(root->left, val);
        if(root->right)
            root->ht = max(root->right->ht, root->left->ht + 1);
        else 
            root->ht = root->left->ht + 1;        
    }
    else 
    {
        root->right = dup_insert(root->right, val);
        if(root->left)
            root->ht = max(root->left->ht, root->right->ht + 1);
        else 
            root->ht = root->right->ht + 1;
    }
    
    root = checkBF(root);
    return root;
}

void inorder(node* nod)
{
    if(nod == nullptr)
        return;
    inorder(nod->left);
    cout<<nod->val<<" ";
    inorder(nod->right);
}

node * insert(node * root,int val)
{
    root = dup_insert(root,val);
    inorder(root);
    cout<<endl;
    return root;
}