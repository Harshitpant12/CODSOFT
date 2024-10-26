#include <iostream>
using namespace std;

int main()
{
    cout << "A calculator for simple calculations -->" << endl;
    long long int n1, n2;
    cout << "Enter the first number: " << endl;
    cin >> n1;
    cout << "Enter the second number: " << endl;
    cin >> n2;
    char op;
    cout << "Choose an operator between : +, -, *, /" << endl;
    cout << "Enter the operator: " << endl;
    cin >> op;

    switch (op)
    {
    case '+':
        cout << "Addition will be: " << n1 + n2 << endl;
        break;
    case '-':
        cout << "Subtraction will be: " << n1 - n2 << endl;
        break;
    case '*':
        cout << "Multiplication will be: " << n1 * n2 << endl;
        break;
    case '/':
        cout << "Division will be: " << float(n1) / float(n2) << endl;
        break;
    default:
        cout << "Please Enter a valid operator." << endl;
    }

    return 0;
}
