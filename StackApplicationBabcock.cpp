/*****************************************
 * Name: Convert Infix to Postfix Using Stack
 * Author: Tanner Babcock
 * Created: September 14, 2022
 * Course: CIS 152 - Data Structures
 * Version: 1.0
 * OS: Void GNU/Linux
 * IDE: Emacs
 * Copyright : This is my own original work based
 * on specifications issued by our instructor.
 * Academic Honesty: I attest that this is my original
 * work. I have not used unauthorized source code,
 * either modified or unmodified. I have not given
 * other fellow student(s) access to my program.
******************************************/
#include <iostream>
#include <stack>
#include <string>
using namespace std;

/* returns precedence of given operator */
int prec(char c) {
    int ret = 0;
    switch (c) {
        case '+': case '-':
            ret = 1;
            break;
        case '*': case '/':
            ret = 2;
            break;
        case '^':
            ret = 3;
            break;
    }
    return ret;
}

/* determines if character is an operand */
bool isOperand(char c) {
    bool x = ((c >= 'a') && (c <= 'z')) || ((c >= 'A') && (c <= 'Z'));
    bool y = (c >= '0') && (c <= '9');
    return x || y;
}

string toPostfix(string s) {
    stack<char> stack;
    string result;
    char c;

    for (unsigned int x = 0; x < s.length(); x++) {
        c = s[x];

        /* if character is an operand, add it to result */
        if (isOperand(c))
            result += c;

        /* check for '(' and push */
        else if (c == '(')
            stack.push('(');

        /* check for ')', pop and output until '(' */
        else if (c == ')') {
            while (stack.top() != '(') {
                result += stack.top();
                stack.pop();
            }
            stack.pop();
        }

        /* that means character is an operator */
        else {
            while (!(stack.empty()) && ((prec(s[x]) <= prec(stack.top())))) {
                if ((c == '^') && (stack.top() != '^'))
                    break;
                else {
                    result += stack.top();
                    stack.pop();
                }
            }
            stack.push(c);
        }
    }

    /* pop all remaining elements */
    while (!(stack.empty())) {
        result += stack.top();
        stack.pop();
    }
    return result;
}

int main(void) {
    string exp = "a+b*(c-d^e)^(f+g*h)-i";

    cout << exp << endl;
    cout << "Converting..." << endl;
    cout << toPostfix(exp) << endl;
    return 0;
}
