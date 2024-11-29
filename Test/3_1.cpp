#include <iostream>  
#include <vector>  
#include <stdexcept>  
  
template <typename T>  
class SeqStack {  
private:  
    std::vector<T> stack;  
  
public:  
    void push(const T& value) {  
        stack.push_back(value);  
    }  
  
    void pop() {  
        if (stack.empty()) {  
            throw std::out_of_range("Stack underflow");  
        }  
        stack.pop_back();  
    }  
  
    T top() const {  
        if (stack.empty()) {  
            throw std::out_of_range("Stack is empty");  
        }  
        return stack.back();  
    }  
  
    bool isEmpty() const {  
        return stack.empty();  
    }  
};  
  
int main() {  
    SeqStack<int> stack;  
    stack.push(1);  
    stack.push(2);  
    std::cout << "Top: " << stack.top() << std::endl;  
    stack.pop();  
    std::cout << "Top after pop: " << stack.top() << std::endl;  
    return 0;  
}