// File: Evaluator.cpp source code for postfix evaluator
// Author: Gabriel Prestemon
// Purpose: Evaluate a postfix expression
#include "Evaluator.h"
#include <string>
#include <stack>

// NEEDS WORK!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
void Evaluator::evaluate() {
	std::stack<float> numbers;
		
	for (int i = 0; i < postfix.size(); i++) {
		if (isdigit(postfix[i])) {
			// number conversion
			float n = 0;
			// whole number digits
			while (isdigit(postfix[i])) {
				n *= 10;
				n += postfix[i] - '0';
				// increment index
				if (i < postfix.size() - 1) { i++; }
				else { break; }
			} // endwhile
			// decimals
			if (postfix[i] == '.') {
				// increment index
				if (i < postfix.size() - 1) {
					i++;
					int decimalCount = 2;
					while (isdigit(postfix[i])) {
						n += ((postfix[i] - '0') / pow(10, decimalCount));
						// increment index
						if (i < postfix.size() - 1) { i++; }
						else { break; }
					} // endwhile
				} // endif
			} // endif
			numbers.push(n);
		} // endif number case
		// operator case
		else if (isOperator(postfix[i])) {
			float b = numbers.top();
			numbers.pop();
			float a = numbers.top();
			numbers.pop();
			numbers.push(operate(a, postfix[i], b));
		}
	}
	result = numbers.top();
}

// strips the white spaces from the expression
void Evaluator::stripWhiteSpace() {
	for (int i = 0; i < postfix.size(); i++) {
		if (postfix[i] == ' ' || postfix[i] == '\t') {
			// remove the index, decrement i to match the new index space
			postfix.erase(i--, 1);
		}
	}
}

// checks if the character is an operator
bool Evaluator::isOperator(char c) {
	if (c == 'x' || c == '*' || c == '/' || c == '+' || c == '-') {
		return true;
	}
	return false;
}

float Evaluator::operate(float a, char op, float b) {
	switch (op) {
	case 'x':
	case '*':
		return a * b;
	case '/':
		return a / b;
	case '+':
		return a + b;
	case '-':
		return a - b;
	default:
		return 0;
	}
}