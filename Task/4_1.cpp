#include <iostream>  
#include <cstring> // 仅为了使用strlen函数，但尽量遵循要求，我们可以自己实现长度计算  
  
char* removeSubstrings(const char* s, const char* t) {  
    
    int lenS = 0;  
    while (s[lenS] != '\0') {  
        lenS++;  
    }  
    int lenT = 0;  
    while (t[lenT] != '\0') {  
        lenT++;  
    }  
  
    
    if (lenT == 0) {  
        char* result = new char[lenS + 1];  
        strcpy(result, s);  
        return result;  
    }  
    if (lenS == 0) {  
        return new char[1]{'\0'};  
    }  
  
     
    char* result = new char[lenS + 1];  
    int resultIndex = 0;  
  
    int i = 0, j = 0;  
    while (s[i] != '\0') {  
         
        j = 0;  
        while (s[i + j] != '\0' && t[j] != '\0' && s[i + j] == t[j]) {  
            j++;  
        }  
         
        if (t[j] == '\0') {  
             
            i += lenT;  
        } else {  
             
            result[resultIndex++] = s[i];  
            i++;  
        }  
    }  
     
    result[resultIndex] = '\0';  
  
    return result;  
}  
  
int main() {  
    const char* s = "hello world, hello universe";  
    const char* t = "hello";  
    char* result = removeSubstrings(s, t);  
    std::cout << result << std::endl;  
    // 记得释放分配的内存  
    delete[] result;  
    return 0;  
}