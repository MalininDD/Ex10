// Copyright 2021 MalininDmitry
#include "postfix.h"
#include <stack>
#include <string>
#include <sstream>

bool checkNumber(char sym) {
    if(sym == '0' or sym == '1' or sym == '2' or sym == '3' or sym == '4' or sym == '5' or sym == '6' or sym == '7' or sym == '8' or sym == '9'){
        return true;
    }
    else
        return false;
}

int getPowerOfOperation(char sym) {
    if (sym == '(' or sym == ')') {
        return 0;
    }
    else if (sym == '+' or sym == '-'){
        return 1;
    }
    else if (sym == '/' or sym == '*')
        return 2;
    else
        return 3;
}

int isBracketOpen(char sym) {
    if(sym == '(')
        return 1;
    return 0;
}

int isBracketClose(char sym) {
    if(sym == ')')
        return 1;
    return 0;
}

std::string getNumber(std::string s,int i) {
    std::string y;
    int count = 0;
    for (int j = i+2; j <= s.length(); j++) {
        if(!checkNumber(s[j])){
            count = j - i;
            break;
        }
    }
    y = s.substr(i, count);
    return y;
}

std::string infix2postfix(std::string s){
    std::stack<std::string> st_digit;
    std::stack<char> st_operation;
    std::string x;
    std::string y = "";
    std::string answer = "";
    for (int i = 0; i < s.length(); i++) {
        if (checkNumber(s[i])) {
            if((i + 1 < s.length()) and (s[i+1] == '.')){
                x = getNumber(s,i);
                st_digit.push(x);
                i+=x.length()-1;
            } else {
                x = s[i];
                st_digit.push(x);
            }
        } else if (s[i] != ' ') {
            if(st_operation.empty()){
                st_operation.push(s[i]);
            } else {
                if(getPowerOfOperation(s[i]) > getPowerOfOperation(st_operation.top()) or isBracketOpen(s[i])){
                    st_operation.push(s[i]);
                } else if(isBracketClose(s[i])) {
                    while (st_operation.top() != '(') {
                        if(!st_digit.empty()) {
                            y = st_digit.top();
                            y+=' ';
                            st_digit.pop();
                        }
                        if(!st_digit.empty()) {
                            answer+=st_digit.top();
                            answer+=' ';
                            st_digit.pop();
                        }
                        answer+=y;
                        answer+=st_operation.top();
                        st_digit.push(answer);
                        answer = "";
                        st_operation.pop();
                    }
                    st_operation.pop();
                } else {
                    if (!st_digit.empty()) {
                        y = st_digit.top();
                        y+=' ';
                        st_digit.pop();
                    }
                    if (!st_digit.empty()) {
                        answer+=st_digit.top();
                        answer+=' ';
                        st_digit.pop();
                    }
                    answer+=y;
                    answer+=st_operation.top();
                    st_digit.push(answer);
                    answer = "";
                    st_operation.pop();
                    i-=1;
                }
            }
        }
    }
    
    std::stack<std::string> st_digit1;
    while (!st_digit.empty()) {
        st_digit1.push(st_digit.top());
        st_digit.pop();
    }
    
    while (!st_digit1.empty()) {
        answer += st_digit1.top();
        answer += " ";
        st_digit1.pop();
    }
    
    while (!st_operation.empty()) {
        answer += st_operation.top();
        answer += " ";
        st_operation.pop();
    }
    
    answer.erase(answer.length()-1,1);
    return answer;
}
