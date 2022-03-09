class Node{
public:
    int val;
    Node *next;
    Node *prev;
    Node(){val=0; next=NULL;}
    Node(int data){val=data; next=NULL; prev=NULL;}
    Node(int data, Node *Next, Node *Prev){val=data; next=Next; prev=Prev;}
};

class MyLinkedList {
public:
    int size;
    Node *head;
    MyLinkedList() {
        size=0;
        head=NULL;
    }
    
    int get(int index) {
        if(index>=size || index<0) return -1;
        Node *temp=head;
        while(index-->0)
            temp=temp->next;
        return temp->val;
    }
    
    void addAtHead(int val) {
        Node *node = new Node(val);
        if(head==NULL) 
        {
            head=node;
            head->next=head->prev=NULL;
        }
        else
        {
            node->next=head;
            head->prev=node;
            head=node;
        }
        size++;
        // cout<<size<<endl;
        return;
    }
    
    void addAtTail(int val) {
        Node *node = new Node(val), *temp=head;
        if(head==NULL) 
        {
            head=node;
            head->next=head->prev=NULL;
        }
        else
        {
            while(temp->next!=NULL)
                temp=temp->next;
            temp->next=node;
            node->prev=temp;
            node->next=NULL;
        }
        size++;
        // cout<<size<<endl;
        return;
    }
    
    void addAtIndex(int index, int val) {
        Node *node = new Node(val), *temp=head;
        if(index>size || index<0) return;
        if(index==0)
        {
            addAtHead(val);
            // cout<<size<<endl;
            return;
        }
        else if(index==size)
        {
            addAtTail(val);
            // cout<<size<<endl;
            return;
        }
        else 
        {
            Node *p, *temp=head;
            while(index--)
            {
                p=temp;
                temp=temp->next;
            }
            p->next=node;
            node->prev=p;
            node->next=temp;
            temp->prev=node;
        }
        size++;
        // cout<<size<<endl;
        return;
    }
    
    void deleteAtIndex(int index) {
        // cout<<index<<" Size "<<size<<" ";
        if(index>=size || index<0) return;
        else if(index==0) head=head->next;
        else
        {
            Node *p, *temp=head;
            while(index>0)
            {
                p=temp;
                temp=temp->next;
                index--;
            }
            p->next=temp->next;
            if(temp->next!=NULL)
                temp->next->prev=p;
            temp->next=NULL;
            temp->prev=NULL;
            delete(temp);
        }
        size--;
        // cout<<size<<endl;
        return;
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
