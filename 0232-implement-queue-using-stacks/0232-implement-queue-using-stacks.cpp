// 75 LeetCodeChallenge-->>


// yeh mera algorithm hai jisme push operation o(1) mein aur pop aur peek operation o(n) mein chal raha hai
// In this we use two stack-->>


class MyQueue {
public:
stack<int>st1;
stack<int>st2;
    MyQueue() {
        
    }
    
    void push(int x) {
        st1.push(x);
    }
    
    int pop() {
        while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();
        }
        int element=st2.top();
        st2.pop();
        while(!st2.empty()){
            st1.push(st2.top());
            st2.pop();
        }
        return element;
    }
    
    int peek() {
         while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();
        }
        int element=st2.top();
           while(!st2.empty()){
            st1.push(st2.top());
            st2.pop();
        }
        return element;
    }
    
    bool empty() {
      return st1.empty(); 
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */