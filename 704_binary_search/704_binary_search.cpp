#include <iostream>
using namespace std;
#include <vector>

//inplemented [ ) binary search
class Solution {
public:
    int binary_search(vector<int>& nums, int target, int l, int h){
        if(l == h) return -1; //if no number found, index of the number greater than target is returned 
        int mid = (l+h)/2;
        if(nums[mid] == target) return mid;
        if(nums[mid] < target){
            return binary_search(nums, target, mid+1, h);
        } else {
            return binary_search(nums, target, l, mid);
        }
    }
    int search(vector<int>& nums, int target) {
        return binary_search(nums, target, 0, nums.size());
    }
};


int main(){
    Solution s;
    vector<int> nums;
    nums = {1,2,4,6,7};
    int target = 4;
    cout << "index is: " << s.search(nums, target) << endl;
    return 0;
}