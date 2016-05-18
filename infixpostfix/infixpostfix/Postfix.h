// File: Postfix.h class header for infix->postfix converter
// Author: Gabriel Prestemon
// Purpose: Convert an infix expression to a postfix expression
#pragma once
#ifndef _POSTFIX_H
#define _POSTFIX_H

#include <string>

class Postfix {
private:
	// infix expression
	std::string infix;
	// postfix expression
	std::string postfix;
	// convert the infix expression to a postfix expression
	void convert();
	// checks if all parenthesis are paired
	bool checkParenthesis();
public:
	// default constructor
	Postfix() { infix = ""; postfix = ""; }
	// constructor with input
	Postfix(std::string in) { setInfix(in); }
	// return the infix expression
	inline std::string getInfix() { return infix; }
	// return the postfix expression
	inline std::string getPostfix() { return postfix; }
	// set the infix expression (also converts it to postfix)
	inline void setInfix(std::string in) { infix = in; convert(); }
};

#endif