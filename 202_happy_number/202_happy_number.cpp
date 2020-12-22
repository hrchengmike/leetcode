#include <iostream>
#include <set>
#include <cmath>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        std::set<int> set;
        while(true){
            set.insert(n);
            cout << n <<endl;
            int sum = sum_digit(n);
            if(sum == 1) return true;
            if(set.count(sum)>0) return false;
            set.insert(sum);
            n = sum;
        }
    }
    int sum_digit(int n){
        int sum = 0;
        while(n > 0){
            sum += pow(n % 10, 2);
            n /= 10;
        }
        return sum;
    }
};

int main() {
    int input;
    cout << "please input a number:\n";
    cin >> input;
    Solution s;
    cout << "starting program: \n";
    int output = s.isHappy(input);
    if(output){
        cout << "input is a happy number\n";
    } else{
        cout << "input is not a happy number\n";
    }
    return 0;
}
