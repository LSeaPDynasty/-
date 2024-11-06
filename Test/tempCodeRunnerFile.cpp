#include <iostream>  
#include <stack>  
#include <string>  
#include <cctype>  
#include <stdexcept>  
  
using namespace std;  
  
 
int precedence(char op) {  
    if (op == '+' || op == '-')  
        return 1;  
    if (op == '*' || op == '/')  
        return 2;  
    return 0;  
}  
  
  
bool isOperator(char ch) {  
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';  
}  
  

string infixToPostfix(const string &exp) {  
    stack<char> opStack; 
    string postexp; 
    char ch, topOp;  
    int i = 0;  
    opStack.push('=');  
  
    while (exp[i] != '\0') {  
        ch = exp[i];  
  
         
        if (isdigit(ch) || ch == '.') {  
            string num;  
            while (i < exp.length() && (isdigit(exp[i]) || exp[i] == '.')) {  
                num += exp[i];  
                i++;  
            }  
            postexp += num + "#";  
            i--; 
        }  
          
        else if (ch == '(') {  
            opStack.push(ch);  
        }  
         
        else if (ch == ')') {  
            while ((topOp = opStack.top()) != '(') {  
                postexp += topOp;  
                opStack.pop();  
            }  
            opStack.pop(); 
        }  
        
        else if (isOperator(ch)) {  
            while ((topOp = opStack.top()) != '=' && precedence(topOp) >= precedence(ch)) {  
                postexp += topOp;  
                opStack.pop();  
            }  
            opStack.push(ch);  
        }  
        i++;  
    }  
  
    while ((topOp = opStack.top()) != '=') {  
        postexp += topOp;  
        opStack.pop();  
    }  
  
    return postexp;  
}  
  
 
int evaluatePostfix(const string &postexp) {  
    stack<int> st;   
    int num, top1, top2;  
    char ch;  
    for (size_t i = 0; i < postexp.length(); ++i) {  
        ch = postexp[i];  
  
         
        if (isdigit(ch) || ch == '.') {  
            string numStr;  
            while (i < postexp.length() && (isdigit(postexp[i]) || postexp[i] == '.')) {  
                numStr += postexp[i];  
                i++;  
            }  
            num = stoi(numStr); 
            
            st.push(num);  
            i--;  
        }  
        
        else if (ch == '+') {  
            top2 = st.top(); st.pop();  
            top1 = st.top(); st.pop();  
            st.push(top1 + top2);  
        }  
        else if (ch == '-') {  
            top2 = st.top(); st.pop();  
            top1 = st.top(); st.pop();  
            st.push(top1 - top2);  
        }  
        else if (ch == '*') {  
            top2 = st.top(); st.pop();  
            top1 = st.top(); st.pop();  
            st.push(top1 * top2);  
        }  
        else if (ch == '/') {  
            top2 = st.top(); st.pop();  
            if (top2 == 0) {  
                cerr << "Error: Division by zero" << endl;  
                throw runtime_error("Division by zero");  
            }  
            top1 = st.top(); st.pop();  
            st.push(top1 / top2);  
        }  
    }  
  
    return st.top();  
}  
  
int main() {  
    string exp;  
    cout << "中缀表达式: ";  
    cin >> exp;  
  
    string postexp = infixToPostfix(exp);  
    cout << "后缀表达式:" << postexp << endl;  
  
    int result = evaluatePostfix(postexp);  
    cout << "结果:" << result << endl;  
  
    return 0;  
}