/* BY THE GREATEST C++ PROGRAMMER SIR BLOB */

#pragma once

#include <iostream>
#include <string>
#include <cmath>

#include "../Util/ArrayList.hpp"

class Equation {
    private: 
        std::string equation;

        ArrayList<char> operators = ArrayList<char>();

        ArrayList<double> operands = ArrayList<double>();
        
        double stringToDouble(std::string str);
        std::string doubleToString(double num);

        bool checkValidEquation(std::string equation);
        void tokenizeEquation(std::string equation);
        std::string removeSpaces(std::string str);

        double eval(char op, double num1, double num2);
        double solve(std::string equation);

    public:

        Equation();
        Equation(std::string equation);
        ~Equation();

        std::string getEquation();

        void setEquation(std::string equation);

        double calculate();
};


Equation::Equation() {
    equation = "";
}

Equation::Equation(std::string equation) {
    this->equation = removeSpaces(equation);
}

Equation::~Equation() {
    delete &equation;
}

std::string Equation::getEquation() {
    return equation;
}

void Equation::setEquation(std::string equation) {
    this->equation = removeSpaces(equation);
}

double Equation::stringToDouble(std::string str) {
    double num = 0;
    int decimalPoint = 0;
    bool decimal = false;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '.') {
            decimal = true;
            continue;
        }
        if (decimal) {
            decimalPoint++;
        }
        num = num * 10 + (str[i] - '0');
    }
    for (int i = 0; i < decimalPoint; i++) {
        num /= 10;
    }
    return num;
}

std::string Equation::doubleToString(double num) {
    std::string str = "";
    int decimalPoint = 0;
    bool decimal = false;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '.') {
            decimal = true;
            continue;
        }
        if (decimal) {
            decimalPoint++;
        }
        num = num * 10 + (str[i] - '0');
    }
    for (int i = 0; i < decimalPoint; i++) {
        num /= 10;
    }
    return str;
}

bool Equation::checkValidEquation(std::string equation) {
    int openParentheses = 0;
    int closeParentheses = 0;
    for (int i = 0; i < equation.length(); i++) {
        if (equation[i] == '(') {
            openParentheses++;
        } else if (equation[i] == ')') {
            closeParentheses++;
        }
    }
    if (openParentheses != closeParentheses) {
        return false;
    }
    return true;
}

void Equation::tokenizeEquation(std::string equation) {

    operands.clear();
    operators.clear();

    std::string num = "";
    for (int i = 0; i < equation.length(); i++) {
        if (equation[i] == '+' || equation[i] == '-' || equation[i] == '*' || equation[i] == '/' || equation[i] == '^') {
            operands.addLast(stringToDouble(num));
            operators.addLast(equation[i]);
            num = "";
        } else {
            num += equation[i];
        }
    }
    operands.addLast(stringToDouble(num));
}

std::string Equation::removeSpaces(std::string str) {
    std::string newStr = "";
    for (int i = 0; i < str.length(); i++) {
        if (str[i] != ' ') {
            newStr += str[i];
        }
    }
    return newStr;
}

double Equation::eval(char op, double num1, double num2) {
    switch (op) {
        case '^':
            return pow(num1, num2);
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            if (num2 == 0) {
                throw std::invalid_argument("Cannot divide by zero.");
            }
            return num1 / num2;
        default:
            throw std::invalid_argument("Invalid operator.");
    }
}

double Equation::solve(std::string equation) {

    tokenizeEquation(equation);

    for (int i = 0; i < operators.getSize(); i++) {
        if (operators.get(i) == '^') {
            operands.set(i, eval(operators.get(i), operands.get(i), operands.get(i + 1)));
            operands.remove(i + 1);
            operators.remove(i);
            i--;
        }
    }

    for (int i = 0; i < operators.getSize(); i++) {
        if (operators.get(i) == '*' || operators.get(i) == '/') {
            operands.set(i, eval(operators.get(i), operands.get(i), operands.get(i + 1)));
            operands.remove(i + 1);
            operators.remove(i);
            i--;
        }
    }
    

    for (int i = 0; i < operators.getSize(); i++) {
        if (operators.get(i) == '+' || operators.get(i) == '-') {
            operands.set(i, eval(operators.get(i), operands.get(i), operands.get(i + 1)));
            operands.remove(i + 1);
            operators.remove(i);
            i--;
        }
    }

    return operands.get(0);
}

double Equation::calculate() {

    std::cout << "Equation: " << equation << std::endl;

    std::string finalInput = "";

    for (int i = 0; i < equation.length(); i++) {
        if (equation[i] == '(') {
            for (int j = i + 1; j < equation.length(); j++) {
                if (equation[j] == ')') {
                    finalInput = equation.substr(i + 1, j - i - 1);
                    equation = equation.substr(0, i) + std::to_string(solve(finalInput)) + equation.substr(j + 1, equation.length() - j - 1);
                    break;
                }
            }
        }
    }

    return solve(equation);
}