// File: Source.cpp for infixpostfix
// Author: Gabriel Prestemon
// Purpose: Main for infix postfix
#include <iostream>
#include <string>
#include "Postfix.h"
#include "Evaluator.h"

using namespace std;

int main() {
	cout << "Enter an expression: " << endl;
	cout << "Valid operators: +, -, *, x, /" << endl;

	// get the expression from the user
	string infixExpression;
	getline(cin, infixExpression);

	Postfix p(infixExpression);

	cout << p.getInfix() << endl;
	cout << p.getPostfix() << endl;

	Evaluator e(p.getPostfix());
	cout << e.getResult();

	// end program
	cout << "\n\n";
	system("pause");
	return 0;
}