#include "Postfix.h"
#include <iostream>
#include <stack>

// convert the infix expression to a postfix expression
void Postfix::convert() {
	// make sure the expression is convertable
	if (!checkParenthesis()) {
		std::cout << "\nMISMATCHING PARENTHESIS\n";
	}
	// strip the white spaces from the expression
	stripWhiteSpace();

	std::stack<char> operators;
	for (int i = 0; i < infix.size(); i++) {
		// if the character is an operator push it onto the stack
		if (isOperator(infix[i])) {
			// if there is a precedence issue, pop from the stack
			if(!operators.empty()) {
				while (checkPrecedence(operators.top(), infix[i])) {
					postfix.push_back(' ');
					postfix.push_back(operators.top());
					operators.pop();
					if (operators.empty()) {
						break;
					}
				}
			}
			operators.push(infix[i]);
			postfix.push_back(' ');
		}
		// if the character is an open parenthesis,  push it onto the stack
		else if (openParenthesis(infix[i])) {
			operators.push(infix[i]);
		}
		// if the character is a close parenthesis, pop the stack into the expression
		//    until its matching open parenthesis.
		//      char c holds the matching open parenthesis
		else if (char c = closeParenthesis(infix[i])) {
			while (operators.top() != c) {
				postfix.push_back(' ');
				postfix.push_back(operators.top());
				operators.pop();
			}
			// discard the remaining open parenthesis
			operators.pop();
		}
		// if it's a number, put it into the expression
		else if (isdigit(infix[i]) || infix[i] == '.') {
			postfix.push_back(infix[i]);
		}
	}

	while (!operators.empty()) {
		postfix.push_back(' ');
		postfix.push_back(operators.top());
		operators.pop();
	}
}

// checks if all parenthesis are paired
bool Postfix::checkParenthesis() {
	std::stack<char> stk;
	for (int i = 0; i < infix.size(); i++) {
		if (openParenthesis(infix[i])) {
			stk.push(infix[i]);
		}
		if (char c = closeParenthesis(infix[i])) {
			if (stk.top() != c) {
				return false;
			}
			stk.pop();
		}
	}
	if (stk.empty()) {
		return true;
	}
	return false;
}

// strips the white spaces from the expression
void Postfix::stripWhiteSpace() {
	for (int i = 0; i < infix.size(); i++) {
		if (infix[i] == ' ' || infix[i] == '\t') {
			// remove the index, decrement i to match the new index space
			infix.erase(i--, 1);
		}
	}
}

// checks if the character is an operator
bool Postfix::isOperator(char c) {
	if (c == 'x' || c == '*' || c == '/' || c == '+' || c == '-') {
		return true;
	}
	return false;
}

// checks if the character is an open parenthesis
bool Postfix::openParenthesis(char c) {
	if (c == '(' || c == '[' || c == '{' || c == '<') {
		return true;
	}
	return false;
}

// checks if the character is a closing parenthesis
// returns its alternate opening parenthesis
char Postfix::closeParenthesis(char c) {
	switch (c) {
	case ')':
		return '(';
	case ']':
		return '[';
	case '}':
		return '{';
	case '>':
		return '<';
	default:
		return 0;
	}
}

// true if precedence is higher, false if precedence is lower
bool Postfix::checkPrecedence(char stackTop, char nextOp) {
	if (stackTop == '*' || stackTop == 'x' || stackTop == '/') {
		if (nextOp == '-' || nextOp == '+') {
			return true;
		}
	}
	return false;
}


// number conversion
//float n;
//// whole number digits
//while (isdigit(infix[i])) {
//	n *= 10;
//	n += infix[i] - '0';
//	// increment index
//	if (i < infix.size() - 1) { i++; }
//	else { break; }
//}
//// decimals
//if (infix[i] == '.') {
//	// increment index
//	if (i < infix.size() - 1) { i++; }
//	else { break; }
//	int decimalCount = 1;
//	while (isdigit(infix[i])) {
//		n += ((infix[i] - '0') / pow(10, decimalCount));
//		// increment index
//		if (i < infix.size() - 1) { i++; }
//		else { break; }
//	}
//} // end decimal
//// add the number to the 
