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
public:
	// default constructor
	Postfix() { infix = ""; postfix = ""; }
	// constructor with input
	Postfix(std::string in) { setInfix(in); }
	// return the infix expression
	std::string getInfix() { return infix; }
	// return the postfix expression
	std::string getPostfix() { return postfix; }
	// set the infix expression (also converts it to postfix)
	void setInfix(std::string in) { infix = in; convert(); }
};

#endif