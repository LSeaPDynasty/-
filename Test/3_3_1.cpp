#include <iostream>  
  
unsigned long long Ackermann(unsigned int m, unsigned int n) {  
    if (m == 0) {  
        return n + 1;  
    } else if (m > 0 && n == 0) {  
        return Ackermann(m - 1, 1);  
    } else if (m > 0 && n > 0) {  
        return Ackermann(m - 1, Ackermann(m, n - 1));  
    }  
    return 0; // Should never reach here with valid input  
}  
  
int main() {  
    unsigned int m = 2, n = 1;  
    std::cout << "Ackermann(" << m << "," << n << ") = " << Ackermann(m, n) << std::endl;  
    return 0;  
}