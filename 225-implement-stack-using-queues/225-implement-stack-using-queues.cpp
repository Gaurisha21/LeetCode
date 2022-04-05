class MyStack {
    queue<int> q1,q2;
    int noOfEle;
public:
    MyStack() {
        noOfEle = 0;
    }
    
    void push(int x) {
        q1.push(x);
        noOfEle++;
    }
    
    int pop() {
        while(q1.size()!=1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        noOfEle--;
        int x=q1.front();
        q1.pop();
        queue<int> q=q1;
        q1=q2;
        q2=q;
        return x;
    }
    
    int top() {
        while(q1.size()!=1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        noOfEle--;
        int x=q1.front();
        q1.pop();
        q2.push(x);
        queue<int> q=q1;
        q1=q2;
        q2=q;
        return x;
    }
    
    bool empty() {
        return q1.size()==0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */