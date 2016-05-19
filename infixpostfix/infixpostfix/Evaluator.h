// File: Evaluator.h class header for postfix evaluator
// Author: Gabriel Prestemon
// Purpose: Evaluate a postfix expression
#pragma once
#ifndef _EVALUATOR_H
#define _EVALUATOR_H

#include <string>

class Evaluator {
private:
	// postfix expression
	std::string postfix;
	// result
	float result;

	// evaluate the postfix expression
	void evaluate();
	// strips white space from the postfix expression
	void stripWhiteSpace();
	// checks if the character is an operator
	bool isOperator(char);
	// operates on the input, a op b
	float operate(float, char, float);

public:
	// default constructor
	Evaluator() { postfix = ""; result = 0; }
	// constructor with input
	Evaluator(std::string post) { postfix = post; evaluate(); }
	// return the postfix expression
	inline std::string getPostfix() { return postfix; }
	// return the evaluated result
	inline float getResult() { return result; }
	// set the postfix expression (also evaluates it)
	inline void setPostfix(std::string post) { postfix = post; evaluate(); }

};

#endif