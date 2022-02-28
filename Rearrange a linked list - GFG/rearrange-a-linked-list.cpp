// { Driver Code Starts
// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};



 // } Driver Code Ends
/* Node structure

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution
{
    public:
    // Node *seg(Node *head)
    // {
    //     if(head==NULL || head->next==NULL) return head;
    //     Node *o=new Node(-1), *e=new Node(-1), *h1=o, *h2=e, *c=head;
    //     while(c!=NULL)
    //     {
    //         if(c->data%2==0)
    //         {
    //             e->next=c;
    //             e=e->next;
    //         }
    //         else
    //         {
    //             o->next=c;
    //             o=o->next;
    //         }
    //         c=c->next;
    //     }
    //     e->next=NULL;
    //     o->next=h2->next;
    //     return h1->next;
    // }
    void rearrangeEvenOdd(Node *head)
    {
        if(head==NULL || head->next==NULL)
            return;
        Node *c1=head, *c2=head->next, *h1=c1, *h2=c2;
        while(c2!=NULL and c2->next!=NULL)
        {
            Node *f=c2->next;
            c1->next=f;
            c2->next=f->next;
            c1=c1->next;
            c2=c2->next;
        }
        c1->next=h2;
    }
};


// { Driver Code Starts.

/* Driver program to test above function*/
int main()
{
    int T,i,n,l;

    cin>>T;

    while(T--)
    {
        struct Node *head = NULL;
        struct Node *temp = head;
        cin>>n;
        for(i=1; i<=n; i++)
        {
            cin>>l;

            if (head == NULL)
            {   
                head = temp = new Node(l); 
                
            }
            else
            {  temp->next = new Node(l);
               temp = temp->next;
            }
        }
        Solution ob;
        ob.rearrangeEvenOdd(head);
        while(head != NULL)
        {
            printf("%d ", head->data);
            head = head->next;
        }
        printf("\n");
    }
    return 0;
}
  // } Driver Code Ends