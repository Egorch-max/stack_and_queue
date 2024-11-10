#include <iostream>
#include "stack_queue.h"
#include <string>

using namespace std;

int Conformity(char s)
{
    if (s == '(')
    {
        return ')';
    }

    if (s == '[')
    {
        return ']';
    }

    if (s == '{')
    {
        return '}';
    }
}

int Check_for_correctness(string s)
{
    Stack<char>stack;
    for (size_t i = 0; i < s.size(); i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            stack.push(s[i]);
        }
        if (s[i] == ')' || s[i] == ']' || s[i] == '}')
        {
            if (!stack.isEmpty() && s[i] == Conformity(stack.top()))
            {
                stack.pop();
            }
            else
            {
                return false;
            }
        }
    }
    if (!stack.isEmpty())
    {
        return false;
    }
    else
    {
        return true;
    }
}

int main()
{
    string expr;

    cout << "Enter an expression: ";

    cin >> expr;

    if (Check_for_correctness(expr) == 1)
    {
        cout << "All brackets match";
    }
    else
    {
        cout << "NOT all brackets match";
    }
}
