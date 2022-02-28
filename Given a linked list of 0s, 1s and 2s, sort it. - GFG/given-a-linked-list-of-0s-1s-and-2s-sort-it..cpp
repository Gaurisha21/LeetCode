// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;


 // } Driver Code Ends
/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    public:
    Node* segregate(Node *head) {
        Node *one=new Node(-1);
        Node *two=new Node(-1);
        Node *zero=new Node(-1);
        Node *o=one, *t=two, *z=zero, *c=head;
        while(c!=NULL)
        {
            int val = c->data;
            if(val==0)
            {
                z->next=c;
                z=z->next;
            }
            else if(val==1)
            {
                o->next=c;
                o=o->next;
            }
            else
            {
                t->next=c;
                t=t->next;
            }
            c=c->next;
        }
        z->next=(one->next!=NULL ? one->next : two->next);
        o->next=(two->next!=NULL ? two->next : NULL);
        t->next=NULL;
        return zero->next;
    }
};


// { Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}  // } Driver Code Ends