#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum < S) return 0;
        vector<vector<int>> memo (nums.size(), vector<int>(sum * 2 + 1, -1));
        return dp(nums, nums.size()-1, S, memo);
    }
    int dp(vector<int>& nums, int i, int j, vector<vector<int>>& memo){
        if(j < 0) j = -j;
        if(memo[i][j] != -1) return memo[i][j];
        if (i == 0){
            if(j == nums[0] && j == 0){
                memo[i][j] = 2;
                return 2;             
            }else if( j == nums[0] || j == -nums[0] ) {
                memo[i][j] = 1;
                return 1;
            } else {
                memo[i][j] = 0;
                return 0; 
            }
        }
        int result =  dp(nums, i-1, j+nums[i], memo) + dp(nums, i-1, j-nums[i], memo);
        memo[i][j] = result;
        return result; 
    }
};

int main(){
vector<vector<int>> input{ { 0, 0, 0, 1 }, 
                           { 1, 1, 1, 1, 1}, 
                           { 7, 8, 9, 4 },
                           { 1 } }; 
    vector<int> target{1, 3, 10000, 2};
    Solution s;
    for(int i = 0; i < input.size(); i++){
        cout << "test case " << i << endl;
        cout << "input: ";
        for(int j = 0; j < input[i].size(); j++)
            cout << input[i][j] << ' ';
        cout << endl;
        cout << "target: " << target[i] << endl;
        cout << "result: " << s.findTargetSumWays(input[i], target[i]) << endl;
    }



}