class Node{
public:
    int val;
    Node *next;
    Node(){val=0; next=NULL;}
    Node(int data){val=data; next=NULL;}
    Node(int data, Node *next){val=data; next=next;}
};

class MyLinkedList {
public:
    int size;
    Node *head;
    MyLinkedList() {
        size=0;
        head=NULL;
    }
    
    void print(Node *head)
    {
        Node *temp=head;
        while(temp!=NULL) 
        {
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    
    int get(int index) {
        if(index >= size || index < 0) return -1;
        Node *curr = head;
        for (int i = 0; i< index; i++)
        {
            curr = curr->next;
        }
        return curr->val;
    }
    
    void addAtHead(int val) {
        Node *node=new Node(val);
        // cout<<"node "<<node->val<<endl;
        if(head==NULL)
        {
            head=node;
        }
        else
        {
            node->next=head;
            head=node;
            // cout<<head->val<<endl;
        }
        size++;
        // cout<<"AH size "<<size<<endl;
        // print(head);
    }
    
    void addAtTail(int val) {
        Node *node=new Node(val);
        if(head==NULL)
        {
            head=node;
            // cout<<head->val<<endl;
        }
        else
        {
            Node *temp=head;
            while(temp->next!=NULL)
                temp=temp->next;
            temp->next=node;
            // cout<<temp->val<<endl;
        }
        size++;
        // cout<<"AT size "<<size<<endl;
        // print(head);
    }
    
    void addAtIndex(int index, int val) {
        if(index>size || index<0) return;
        Node *node=new Node(val);
        // index++;
        if(index==0){
            addAtHead(val);
            // size++;
            // cout<<"AI size "<<size<<endl;
            // print(head);
            return;
        }
        if(index==size){
            addAtTail(val);
            // size++;
            // cout<<"AI size "<<size<<endl;
            // print(head);
            return;
        }
        if(head==NULL)
        {
            head=node;
            // cout<<head->val<<endl;
        }
        else
        {
            Node *temp=head, *prev;
            while(index--)
            {
                prev=temp;
                temp=temp->next;
            }
            prev->next=node;
            node->next=temp;
            // cout<<prev->next->val<<endl;
        }
        size++;
        // cout<<"AI size "<<size<<endl;
        // print(head);
    }
    
    void deleteAtIndex(int index) {
        if(index>=size || index<0) return;
        if(index==0) head=head->next;
        else
        {
            Node *temp=head, *prev;
            while(index--)
            {
                prev=temp;
                temp=temp->next;
            }
            prev->next=temp->next;
        }
        size--;
        // cout<<"D size "<<size<<endl;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */