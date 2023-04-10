// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"
int getPrior(char sim) {
    switch (sim) {
    case '(':
        return 0;
    case ')':
        return 1;
    case '+':
        return 2;
    case '-':
        return 2;
    case '*':
        return 3;
    case '/':
        return 3;
    default:
        return 0;
    }
}
std::string infx2pstfx(std::string inf) {
TStack<char, 100> opStack;
    std::string result = "";
    for (int i = 0; i < inf.size(); i++) {
        if (isdigit(inf[i]) != 0) {
            result += inf[i];
        } else if (getPrior(inf[i]) == 2 || getPrior(inf[i]) == 3) {
            result += " ";
            if (opStack.isEmpty() || getPrior(opStack.get()) == 0 ||
                getPrior(inf[i]) > getPrior(opStack.get())) {
                opStack.push(inf[i]);
            } else if (getPrior(inf[i]) <= getPrior(opStack.get())) {
                while (getPrior(inf[i]) <= getPrior(opStack.get())) {
                    result += opStack.pop();
                    result += " ";
                }
                opStack.push(inf[i]);
            }
        } else if (getPrior(inf[i]) == 0) {
            opStack.push(inf[i]);
        } else if (getPrior(inf[i]) == 1) {
            while (getPrior(opStack.get()) != 0) {
                result += " ";
                result += opStack.pop();
            }
            opStack.pop();
        }
    }
    while (!opStack.isEmpty()) {
        result += " ";
        result += opStack.pop();
    }
    return std::string(result);
}
int calculate(const int a, const int b, const char oper) {
    switch (oper) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        default: break;
    }
    return 0;
}
int eval(std::string pref) {
TStack<int, 100> opStack2;
    std::string result2 = "";
    for (size_t i = 0; i < pref.size(); i++) {
        if (getPrior(pref[i]) == -1) {
            if (pref[i] == ' ') {
                continue;
            } else if (isdigit(pref[i + 1])) {
                result2 += pref[i];
                continue;
            } else {
                result2 += pref[i];
                opStack2.push(atoi(result2.c_str()));
                result2 = "";
            }
        } else {
            int b = opStack2.get();
            opStack2.pop();
            int a = opStack2.get();
            opStack2.pop();
            opStack2.push(calculate(a, b, pref[i]));
        }
    }
    return opStack2.get();
}
