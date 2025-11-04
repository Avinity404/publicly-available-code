#include <iostream>
#include <stack>

using namespace std;

int main(void)
{
    // ----- data ----- //
    stack<char> styrta;
    char symbol;
    string input = "(3+4)+5/3"; // <-- wprowadz wyrazenie tutaj
    string output = "";         // <-- otrzymana postac Postfix


    // ----- calculations ----- //
    for(int c = 0; c < input.size(); c++)
    {
        symbol = input[c];

        if(symbol >= '0' && symbol <= '9')
        {
            output += symbol;
        }
        else if(symbol == '(')
        {
            styrta.push(symbol);
        }
        else if(symbol == ')')
        {
            while(!styrta.empty() && styrta.top() != '(')
            {
                output += styrta.top();
                styrta.pop();
            }
            if (!styrta.empty())
                styrta.pop();
        }
        else if(symbol == '+' || symbol == '-')
        {
            while(!styrta.empty() && styrta.top() != '(')
            {
                output += styrta.top();
                styrta.pop();
            }
            styrta.push(symbol);
        }
        else if(symbol == '*' || symbol == '/')
        {
            while(!styrta.empty() && (styrta.top() == '*' || styrta.top() == '/'))
            {
                output += styrta.top();
                styrta.pop();
            }
            styrta.push(symbol);
        }
    }
    while(!styrta.empty())
    {
        output += styrta.top();
        styrta.pop();
    }


    // ----- result ----- //
    cout << "Wyrazenie: " << input << "\n";
    cout << "Zapisane w Postfix: " << output << '\n';     // <-- otrzymana postac Postfix (wyswietl)
    
    return 0;
}
