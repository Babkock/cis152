/*****************************************
 * Name: Convert Infix to Postfix Using Stack
 * Author: Tanner Babcock
 * Created: September 15, 2022
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
    const int NUMBER_EXPS = 6;

    string input;
    string data[] = {
        "2+3*4",         // 234*+
        "a*b+5",         // ab*5+
        "(1+2)*7",       // 12+7*
        "a*b/c",         // ab*c/
        "(a/(b-c+d))*(e-a)*c", // abc-d+/ea-*c*
        "a/b-c+d*e-a*c"  // ab/c-de*+ac*-
    };

    for (int x = 0; x < NUMBER_EXPS; x++) {
        cout << "*********************************************" << endl;
        cout << "Infix " << (x + 1) << ": " << data[x] << endl;
        cout << "Postfix: " << toPostfix(data[x]) << endl;
    }

    cout << "*********************************************" << endl;
    cout << "Enter infix notation with no spaces: ";
    getline(cin, input);
    cout << "Infix: " << input << endl;
    cout << "Postfix: " << toPostfix(input) << endl;
    cout << "*********************************************" << endl;

    return 0;
}
