// 75 leetcodeChallenge-->>

// pair method-->>
// optimal approach-->>
class MinStack {
public:
  vector<pair<int ,int>>v;
    MinStack() {
// Nothing to do in this(but if we use array then we use pointer)
    }
    
    void push(int val) {
        if(v.empty()){
            v.push_back({val,val});
            return; 
        }
        // more than one element
        auto top=v.back();
        int min_til_now=min(val,top.second);
        v.push_back({val,min_til_now});
    }


    // A,B,C,D
    void pop() {
       v.pop_back();
    }


    int top() {
        
        return v.back().first;
        
    }
    
    int getMin() {
       return v.back().second;
        
    }
};


// Not a optimal approach-->>
// // simple Method-->
// class MinStack {
// public:
    
//     vector<int> v;

//     MinStack() {
        
//     }
    
//     void push(int val) {
//         v.push_back(val);
//     }
    
//     void pop() {
//         if(!v.empty())
//             v.pop_back();
//     }
    
//     int top() {
//         return v.back();
//     }
    
//     int getMin() {
        
//         int mini = INT_MAX;

//         for(int i = 0; i < v.size(); i++) {
//             if(v[i] < mini) {
//                 mini = v[i];
//             }
//         }

//         return mini;
//     }
// };


/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */