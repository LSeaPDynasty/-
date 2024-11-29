#include <iostream>  
#include <stack>  
#include <stdexcept>  
  
unsigned long long AckermannNonRecursive(unsigned int m, unsigned int n) {  
    std::stack<std::pair<unsigned int, unsigned int>> stack;  
    stack.push({m, n});  
  
    while (!stack.empty()) {  
        auto [currentM, currentN] = stack.top();  
        stack.pop();  
  
        if (currentM == 0) {  
            return currentN + 1;  
        } else if (currentM > 0 && currentN == 0) {  
            stack.push({currentM - 1, 1});  
        } else if (currentM > 0 && currentN > 0) {  
            stack.push({currentM, currentN - 1});  
            stack.push({currentM - 1, 0}); // Placeholder for Ackermann(m-1, Ackermann(m, n-1))  
        }  
    }  
    throw std::runtime_error("Unexpected stack state"); // Should never reach here with valid input  
}  
  
int main() {  
    unsigned int m = 2, n = 1;  
    std::cout << "AckermannNonRecursive(" << m << "," << n << ") = " << AckermannNonRecursive(m, n) << std::endl;  
    return 0;  
}