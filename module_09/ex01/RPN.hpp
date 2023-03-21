#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <stack>
# include <stdlib.h>

bool isOperator(char c);
int calcOperation(int a, int b, char op);
int rpnCalc(std::string inp);
void validCheck(std::string inp);

#endif