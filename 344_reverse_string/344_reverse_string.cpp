#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        for (int i = 0;i < n/2; i++){
            swap(s[i], s[n-1-i]);
            /*
            char temp = s[i];
            s[i] = s[n-1-i];
            s[n-1-i] = temp;
            */
        }
    }
};

int main(){
    vector<char> input;
    input.push_back('a');
    input.push_back('b');
    input.push_back('c');
    input.push_back('d');
    input.push_back('e');
    input.push_back('f');
    input.push_back('g');
    input.push_back('h');
    Solution sol;
    //vector<int> output;
    //output.reserve(2*n);
    sol.reverseString(input);
    for (int i = 0; i < input.size(); i++){
        cout << input[i];
    }
    return  0;
}