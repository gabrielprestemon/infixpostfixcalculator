// File: Source.cpp for infixpostfix
// Author: Gabriel Prestemon
// Purpose: Main for infix postfix
#include <iostream>
#include <string>

using namespace std;

int main() {
	cout << "Enter an expression: " << endl;
	cout << "Valid operators: " << endl;

	// get the expression from the user
	string infixExpression;
	getline(cin, infixExpression);

	cout << infixExpression;

	// end program
	cout << "\n\n";
	system("pause");
	return 0;
}