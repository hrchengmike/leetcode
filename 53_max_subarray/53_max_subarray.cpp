#include <vector>
#include <iostream>
using namespace std;

// lemma: max sum subaray with ending index j is the maximum of a[j](x) and max subarray with ending index j-1
// Then calculate the max over all ending index 
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int prev_max = nums[0];//max sub array with ending index i-1 initialized with first element 
        int max = nums[0];//global max over all ending indices
        for(int i = 1; i < nums.size(); i++){
            //find max sub array with ending index i
            //then find the max among those
            int cur_max = nums[i] > nums[i]+prev_max ? nums[i] : nums[i]+prev_max;
            prev_max = cur_max;
            max = cur_max > max ? cur_max:max;
        }
        return max;
    }
};

int main(){
    Solution s;
    vector<int> input = {-2,1,-3,4,-1,2,1,-5,4};
    int result = s.maxSubArray(input);
    cout << "result: "<< result << endl;//max subarray {4, -1 ,2, 1} with sum 6
    return 0;
}