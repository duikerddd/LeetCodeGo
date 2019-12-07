class Solution {
public:
    void push(int value) {
        stack[top++] = value;
        if(top == 1)
        {
            min[top-1] = value;
        }
        else
        {
            min[top-1] = (min[top-1]<min[top-2]?min[top-1]:min[top-2]);
        }  
    }
    void pop() {
        if(top <= 0)
            return;
        top--;
        stack.pop_back();
        min.pop_back();    
    }
    int top() {
        return stack[top-1];
    }
    int min() {
        return min[top-1]
    }
    vector<int> stack;
    vector<int> min;
    int top = 0;
};
