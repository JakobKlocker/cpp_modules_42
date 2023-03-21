#include "RPN.hpp"

bool isOperator(char c)
{
    if(c == '+' || c == '-' || c == '*' || c == '/')
        return true;
    return false;
}

int calcOperation(int a, int b, char op)
{
    if(op == '+')
        return b + a;
    else if(op == '-')
        return b - a;
    else if(op == '*')
        return b * a;
    else if(op == '/')
        return b / a;
    return -1;
}

int rpnCalc(std::string inp)
{
    int a, b;
    std::stack<int> stk;
    for(unsigned long i = 0; i < inp.size(); i++)
    {
        // if(inp[i] == ' ')
        //     continue;
        if(isOperator(inp[i]))
        {
            if(stk.size() < 2)
            {
                std::cout << "Error." << std::endl;
                std::exit(1);
            }
            a = stk.top();
            stk.pop();
            b = stk.top();
            stk.pop();
            stk.push(calcOperation(a, b, inp[i]));
        }
        else if(isdigit(inp[i]))
            stk.push(inp[i] - '0');
    }
    return stk.top();
}

void validCheck(std::string inp)
{
    for(unsigned long i = 0; i < inp.length(); i++)
    {
        if(!isdigit(inp[i]) && inp[i] != '-' && inp[i] != '+' && inp[i] != '*' && inp[i] != '/' 
            && inp[i] != ' ')
        {
            std::cout << "Error" << std::endl;
            std::exit(1);
        }
    }
}
