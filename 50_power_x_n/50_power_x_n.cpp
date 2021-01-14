#include <iostream>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1.0;
        if(n == 1) return x;
        if(n == -1) return 1/x;
        double temp = myPow(x, n/2);
        if(n % 2 == 0) {
            return temp * temp;
        } else if (n > 0){
            return x * temp * temp; 
        } else {
            return 1/x * temp * temp;
        }
    }
};

int main (){
    Solution s;
    int n [] = {-3, -2, -1, 0, 1, 2, 3 };
    for(int i = 0; i < 7; i++){
        cout << "2^ " << n[i] << " = " << s.myPow(2, n[i]) << endl;
    }
}