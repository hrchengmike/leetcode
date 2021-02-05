#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void sortColors1(vector<int>& nums) {
        sort(nums.begin(), nums.end());
    }

    void sortColors2(vector<int>& nums) {
        
        int count [3] = {0, 0, 0}; 
        for(auto i : nums){
            count[i]++;
        }
        for(int i = 0; i < count[0]; i++) nums[i] = 0;
        for(int i = count[0]; i < count[0]+count[1]; i++) nums[i] = 1;
        for(int i = count[0]+count[1]; i < count[0]+count[1]+count[2]; i++) nums[i] = 2;    
    }
};

int main(){
    Solution s;
    vector<int> v = {0, 2, 1, 1, 0, 2, 1, 0};
    s.sortColors1(v);
    for(auto n : v) cout << n;
    cout << endl;
    vector<int> v2 = {0, 2, 1, 1, 0, 2, 1, 0}; 
    s.sortColors2(v2);
    for(auto n : v2) cout << n;
    cout << endl;
}