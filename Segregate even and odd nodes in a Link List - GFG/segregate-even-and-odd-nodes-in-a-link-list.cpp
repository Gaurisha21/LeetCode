// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data <<" "; 
        node = node->next; 
    }  
    cout<<"\n";
} 


 // } Driver Code Ends
//User function template for C++

/*
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
class Solution{
public:
    Node *seg(Node *head)
    {
        if(head==NULL || head->next==NULL) return head;
        Node *o=new Node(-1), *e=new Node(-1), *h1=o, *h2=e, *c=head;
        while(c!=NULL)
        {
            if(c->data%2==0)
            {
                e->next=c;
                e=e->next;
            }
            else
            {
                o->next=c;
                o=o->next;
            }
            c=c->next;
        }
        o->next=NULL;
        e->next=h1->next;
        return h2->next;
    }
    Node* divide(int N, Node *head){
        return seg(head);
    }
};

// { Driver Code Starts.

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans); 
    }
    return 0;
}
  // } Driver Code Ends