#include<iostream>
#include<vector>

using namespace std;
class MinStack {
private:
    vector<int> stack;
    int count;
public:
    /** initialize your data structure here. */
    MinStack() {
        count = 0;
    }

    void push(int x) {
        stack.push_back(x);
        count++;
    }

    void pop() {
        stack.pop_back();

    }

    int top() {
        assert(stack.size() > 0);
        return stack[stack.size()-1];
    }

    int getMin() {
        assert(stack.size() > 0);
        int min = stack[0];
        for (int i = 1; i < stack.size(); i++) {
            if (stack[i] < min) {
                min = stack[i];
            }
        }
        return min;
    }
};
int main() {
    MinStack minStack ;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    std::cout << minStack.getMin() << std::endl;   
    minStack.pop();
    std::cout << minStack.top() << std::endl;      
    std::cout << minStack.getMin() << std::endl;   
    return 0;
}
