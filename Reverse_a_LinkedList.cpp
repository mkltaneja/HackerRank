
class SinglyLinkedListNode
{
public:
    int data;
    SinglyLinkedListNode *next;

    SinglyLinkedListNode(int node_data)
    {
        this->data = node_data;
        this->next = nullptr;
    }
};

class SinglyLinkedList
{
public:
    SinglyLinkedListNode *head;
    SinglyLinkedListNode *tail;

    SinglyLinkedList()
    {
        this->head = nullptr;
        this->tail = nullptr;
    }

    void insert_node(int node_data)
    {
        SinglyLinkedListNode *node = new SinglyLinkedListNode(node_data);

        if (!this->head)
        {
            this->head = node;
        }
        else
        {
            this->tail->next = node;
        }

        this->tail = node;
    }
};

void print_singly_linked_list(SinglyLinkedListNode *node, string sep, ofstream &fout)
{
    while (node)
    {
        fout << node->data;

        node = node->next;

        if (node)
        {
            fout << sep;
        }
    }
}

void free_singly_linked_list(SinglyLinkedListNode *node)
{
    while (node)
    {
        SinglyLinkedListNode *temp = node;
        node = node->next;

        free(temp);
    }
}

// Complete the reverse function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode *reverse(SinglyLinkedListNode *head)
{
    SinglyLinkedListNode *prev = nullptr;
    SinglyLinkedListNode *curr = head;
    SinglyLinkedListNode *forw = head;

    while (curr != nullptr)
    {
        forw = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forw;
    }
    return prev;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int tests;
    cin >> tests;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int tests_itr = 0; tests_itr < tests; tests_itr++)
    {
        SinglyLinkedList *llist = new SinglyLinkedList();

        int llist_count;
        cin >> llist_count;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        for (int i = 0; i < llist_count; i++)
        {
            int llist_item;
            cin >> llist_item;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            llist->insert_node(llist_item);
        }

        SinglyLinkedListNode *llist1 = reverse(llist->head);

        print_singly_linked_list(llist1, " ", fout);
        fout << "\n";

        free_singly_linked_list(llist1);
    }

    fout.close();

    return 0;
}
// #include <bits/stdc++.h>

// using namespace std;

// float answer(float n, float x)
// {
    
//     float a = 5;
//     int tz = 0;
//     while(n/a >= 1)
//     {
//         tz += n/a;
//         a *= 5;
//     }

//     float ans;
//     ans = tz * n * x/100;

//     return ans;
// }

// int main()
// {
//     float n;
//     cin>>n;
//     float x;
//     cin>>x;

//     printf("%.2f", answer(n,x));
//     return 0;
// }



// #include <bits/stdc++.h>

// using namespace std;

// int divisors(int n)
// {
//     int count = 0;
//     for(int i=1;i*i<=n;i++)
//     {
//         if(n%i == 0)
//         {
//             if(i == n/i)
//                 count++;
//             else
//                 count += 2;
//         }
//     }
//     return count;
// }

// int main()
// {
//     int n;
//     while(cin>>n)
//     {
//         if(n == 0)
//             break;
//         //cout<<divisors(n)<<endl;
//         if(divisors(n) % 2 == 0)
//             cout<<"no\n";
//         else 
//             cout<<"yes\n";
//     }
//     return 0;
// }




// #include <bits/stdc++.h>

// using namespace std;

// int main()
// {
//     long long int a,b;
//     cin>>a>>b;

//     long long int c = a;
//     if((a & 1) && b >= a + 3)
//         cout<<a+1<<" "<<a+2<<" "<<a+3<<endl;
//     else if(!(a & 1) && b >= a + 2)
//         cout<<a<<" "<<a+1<<" "<<a+2<<endl;
//     else 
//         cout<<-1<<endl;

//     return 0;
// }