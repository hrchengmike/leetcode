#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1, 1);
        for(int i = 3; i < n+1; i++){
            int max = 0;
            for(int j = 1; j < i; j++){
                if(j * dp[i - j] > max){
                    max = j * dp[i - j];
                }
                if(j * (i - j) > max){
                    max = j * (i - j);
                }
            }
            dp[i] = max;
        }
        return dp[n];
    }
};

int main(){
    int input [5]= {1, 5, 10, 15, 20};
    Solution s;
    for(int i = 0; i < 5; i++){
        cout << "Integer break of " << i << " is ";
        cout << s.integerBreak(input[i])<< endl;
    }
}