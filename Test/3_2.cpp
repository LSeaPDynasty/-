#include <iostream>  
#include <stdexcept>  
  
template <typename T>  
class LinkStack {  
private:  
    struct Node {  
        T data;  
        Node* next;  
        Node(const T& value, Node* nextNode = nullptr) : data(value), next(nextNode) {}  
    };  
    Node* topNode;  
  
public:  
    LinkStack() : topNode(nullptr) {}  
  
    ~LinkStack() {  
        while (!isEmpty()) {  
            pop();  
        }  
    }  
  
    void push(const T& value) {  
        Node* newNode = new Node(value, topNode);  
        topNode = newNode;  
    }  
  
    void pop() {  
        if (isEmpty()) {  
            throw std::out_of_range("Stack underflow");  
        }  
        Node* temp = topNode;  
        topNode = topNode->next;  
        delete temp;  
    }  
  
    T top() const {  
        if (isEmpty()) {  
            throw std::out_of_range("Stack is empty");  
        }  
        return topNode->data;  
    }  
  
    bool isEmpty() const {  
        return topNode == nullptr;  
    }  
};  
  
int main() {  
    LinkStack<int> stack;  
    stack.push(1);  
    stack.push(2);  
    std::cout << "Top: " << stack.top() << std::endl;  
    stack.pop();  
    std::cout << "Top after pop: " << stack.top() << std::endl;  
    return 0;  
}