/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int prec(char ch)
{
    if(ch=='^')
    return 3;
    else if(ch=='/'||ch=='*')
    return 2;
    else if(ch=='+'||ch=='-')
    return 1;
    else
    return -1;
    
}


string infixtopostfix(string s)
{
    stack<char> stack;
    string res;
    for(int i=0;i<s.length();i++)
    {
        if(isalpha(s[i]))
        {    
            res=res+s[i];
        }
        else if(s[i]=='(')
        {
            stack.push('(');
        }
        else if(s[i]==')')
        {
            while(!stack.empty()&&stack.top()!='(')
            {
                char ch=stack.top();
                res+=ch;
                stack.pop();
            }
            if(!stack.empty())
                stack.pop();
        }
        else
        {
            while(!stack.empty()&&prec(stack.top())>=prec(s[i]))
            {
                char ch=stack.top();
                stack.pop();
                res+=ch;
            }
            stack.push(s[i]);
        }
    }
    while(!stack.empty())
    {
        res+=stack.top();
        stack.pop();
    }
    return res;
    
}
int main()
{
    //printf("Hello World");
    string exp = "a+b*(c^d-e)^(f+g*h)-i"; 
    cout<<infixtopostfix(exp); 

    return 0;
}
