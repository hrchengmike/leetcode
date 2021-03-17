#include <iostream>
using namespace std;
int main(){
    string a = "hello";
    string b = " world ";
    char c = '!';
    a += b;
    cout << a << endl;
    a += c;
    cout << a << endl;
    a.append(b);
    cout << a << endl;
    // a.append(c); error, cannot append character
    // cout << a << endl;
}