#include <iostream>

using namespace std;

int main()
{
    int a, b;

    cout << "Enter number : ";
    cin >> a;

    cout << "Enter number : ";
    cin >> b;

    cout << "\n======================" << endl;
    cout << "Addition : " << a + b << endl;
    cout << "Subtraction : " << a - b << endl;
    cout << "Multiplication : " << a * b << endl;
    cout << "Division : " << a / b << endl;
    cout << "Modulus : " << a % b << endl;

    cout << "\n======================" << endl;
    cout << "\n========relational operator========" << endl;
    cout << "\nrelational operator : " << (a > b) << endl;
    cout << "\nrelational operator : " << (a < b) << endl;
    cout << "\nrelational operator : " << (a == b) << endl;
    cout << "\nrelational operator : " << (a != b) << endl;
    cout << "\nrelational operator : " << (a >= b) << endl;
    cout << "\nrelational operator : " << (a <= b) << endl;

    cout << "\n======================" << endl;
    cout << "\n========Assignment operator========" << endl;
    cout << "\nAssignment operator : " << (a = b) << endl;
    cout << "\nAssignment operator : " << (a += b) << endl;
    cout << "\nAssignment operator : " << (a -= b) << endl;
    cout << "\nAssignment operator : " << (a *= b) << endl;
    cout << "\nAssignment operator : " << (a /= b) << endl;
    cout << "\nAssignment operator : " << (a %= b) << endl;
    cout << "\nAssignment operator : " << (a &= b) << endl;
    cout << "\nAssignment operator : " << (a |= b) << endl;
    cout << "\nAssignment operator : " << (a ^= b) << endl;
    cout << "\nAssignment operator : " << (a <<= b) << endl;
    cout << "\nAssignment operator : " << (a >>= b) << endl;

    cout << "\n======================" << endl;
    cout << "\n========Increment/Decrement operator========" << endl;
    cout << "\nIncrement : " << ++a << endl;
    cout << "\nDecrement : " << --b << endl;

    cout << "\n======================" << endl;
    cout << "\n========Logical operator========" << endl;
    cout << "\nLogical AND : " << (a && b) << endl;
    cout << "\nLogical OR : " << (a || b) << endl;
    cout << "\nLogical NOT : " << (!a) << endl;

    cout << "\n======================" << endl;
    cout << "\n========Bitwise operator========" << endl;
    cout << "\nBitwise AND : " << (a & b) << endl;
    cout << "\nBitwise OR : " << (a | b) << endl;
    cout << "\nBitwise XOR : " << (a ^ b) << endl;
    cout << "\nBitwise NOT : " << (~a) << endl;
    cout << "\nLeft Shift : " << (a << 1) << endl;
    cout << "\nRight Shift : " << (a >> 1) << endl;
    cout << "\nLeft Shift : " << (b << 1) << endl;
    cout << "\nRight Shift : " << (b >> 1) << endl;

    cout << "\n======================" << endl; 
    cout << "\nTernary Operator : " << (a > b ? a : b) << endl;

    return 0;
}