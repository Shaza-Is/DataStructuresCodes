#include <iostream>
#include <string>
#include <sstream>
#include <stack>

using namespace std;
bool isOP(string c)
{
    bool flag;
    if(c == "^")
        flag = true;
    else if(c == "*")
        flag = true;
    else if(c == "/")
        flag = true;
    else if(c == "+")
        flag = true;
    else if(c == "-")
        flag = true;
    else
        flag = false;

    return flag;
}
string postTOin(string s)
{
    string infix;
    stack<string> calcStack;
    string buffer;
    stringstream ss(s);
    string first;
    string second;
    while (ss >> buffer)
    {
        if(!isOP(buffer))
        {
            calcStack.push(buffer);
        }
        else
        {
            second = (std::string) calcStack.top();
            calcStack.pop();
            first = (std::string) calcStack.top();
            calcStack.pop();
            calcStack.push("(" + first + buffer + second + ")");

        }
    }
    infix = (std::string)calcStack.top();
    infix = infix.substr(1,(infix.length()-2));
    return infix;
}


int main()
{
    string input ="";
    while(input != "end")
    {

        cout << "Enter postfix to convert: (or end to close)" << endl;
        getline(cin,input);
        cout << postTOin(input) << endl;

     }
    return 0;
}

